/*
 * library.c -- external functions of libbarcode
 *
 * Copyright (c) 1999 Alessandro Rubini (rubini@gnu.org)
 * Copyright (c) 1999 Prosa Srl. (prosa@prosa.it)
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#if 0
#include <unistd.h>
#endif
#include <errno.h>

#include "barcode.h"


void debug_print( char * s) {};
void debug_print_float( double f) {};
void debug_print_int( long i) {};
double trunc(double d){return (int)d;}

/*
 * This function allocates a barcode structure and strdup()s the
 * text string. It returns NULL in case of error
 */
struct Barcode_Item *Barcode_Create(char *text)
{
    struct Barcode_Item *bc;

    bc = malloc(sizeof(*bc));
    if (!bc) return NULL;

    memset(bc, 0, sizeof(*bc));
    bc->ascii = strdup(text);
    bc->margin = BARCODE_DEFAULT_MARGIN; /* default margin */
    bc->checksum = -1;
    return bc;
}


/*
 * Free a barcode structure
 */
int Barcode_Delete(struct Barcode_Item *bc)
{
    if (bc->ascii)
        free(bc->ascii);
    if (bc->partial)
        free(bc->partial);
    if (bc->textinfo)
        free(bc->textinfo);
    if (bc->encoding)
        free(bc->encoding);
    free(bc);
    return 0; /* always success */
}


/*
 * The various supported encodings.  This might be extended to support
 * dynamic addition of extra encodings
 */
extern int Barcode_ean_verify(unsigned char *text);
extern int Barcode_ean_encode(struct Barcode_Item *bc);
extern int Barcode_upc_verify(unsigned char *text);
extern int Barcode_upc_encode(struct Barcode_Item *bc);
extern int Barcode_isbn_verify(unsigned char *text);
extern int Barcode_isbn_encode(struct Barcode_Item *bc);
extern int Barcode_39_verify(unsigned char *text);
extern int Barcode_39_encode(struct Barcode_Item *bc);
extern int Barcode_128b_verify(unsigned char *text);
extern int Barcode_128b_encode(struct Barcode_Item *bc);
extern int Barcode_128c_verify(unsigned char *text);
extern int Barcode_128c_encode(struct Barcode_Item *bc);
extern int Barcode_128_verify(unsigned char *text);
extern int Barcode_128_encode(struct Barcode_Item *bc);
extern int Barcode_i25_verify(unsigned char *text);
extern int Barcode_i25_encode(struct Barcode_Item *bc);

struct encoding {
    int type;
    int (*verify)(unsigned char *text);
    int (*encode)(struct Barcode_Item *bc);
};

struct encoding encodings[] = {
    {BARCODE_EAN,  Barcode_ean_verify,  Barcode_ean_encode},
    {BARCODE_UPC,  Barcode_upc_verify,  Barcode_upc_encode},
    {BARCODE_ISBN, Barcode_isbn_verify, Barcode_isbn_encode},
    {BARCODE_128C, Barcode_128c_verify, Barcode_128c_encode},
    {BARCODE_128B, Barcode_128b_verify, Barcode_128b_encode},
    {BARCODE_39,   Barcode_39_verify,   Barcode_39_encode},
    {BARCODE_I25,  Barcode_i25_verify,  Barcode_i25_encode},
    {BARCODE_128,  Barcode_128_verify,  Barcode_128_encode},
    {0,            NULL,                NULL}
};

/*
 * A function to encode a string into bc->partial, ready for
 * postprocessing to the output file. Meaningful bits for "flags" are
 * the encoding mask, the noascii bit and stretch bit. These bits
 * get saved in the data structure.
 */
int Barcode_Encode(struct Barcode_Item *bc, int flags)
{
    int validbits = BARCODE_ENCODING_MASK | BARCODE_NO_CHECKSUM;
    struct encoding *cptr;

    /* If any flag is cleared in "flags", inherit it from "bc->flags" */
    if (!(flags & BARCODE_ENCODING_MASK))
        flags |= bc->flags & BARCODE_ENCODING_MASK;
    flags = bc->flags = (flags & validbits) | (bc->flags & ~validbits);

    if (!(flags & BARCODE_ENCODING_MASK)) {
        /* get the first code able to handle the text */
        for (cptr = encodings; cptr->verify; cptr++)
            if (cptr->verify((unsigned char *)bc->ascii)==0)
                break;
        if (!cptr->verify) {
            bc->error = EINVAL; /* no code can handle this text */
            return -1;
        }
        flags |= cptr->type; /* this works */
        bc->flags |= cptr->type;
    }
    for (cptr = encodings; cptr->verify; cptr++)
        if (cptr->type == (flags & BARCODE_ENCODING_MASK))
            break;
    if (!cptr->verify) {
        bc->error = EINVAL; /* invalid barcode type */
        return -1;
    }
    if (cptr->verify(bc->ascii) != 0) {
        bc->error = EINVAL;
        return -1;
    }
    return cptr->encode(bc);
}

/*
 * Choose the position
 */
int Barcode_Position(struct Barcode_Item *bc, int wid, int hei,
                     int xoff, int yoff, double scalef)
{
    bc->width = wid; bc->height = hei;
    bc->xoff = xoff; bc->yoff = yoff;
    bc->scalef = scalef;
    return 0;
}



/*
 * Return the version
 */

int Barcode_Version(char *vptr)
{
    if (vptr)
        strcpy(vptr, BARCODE_VERSION);
    return BARCODE_VERSION_INT;
}
/*
 * Return the index from barname
 */
int FromBarcodeStringToID(const char *barname)
{
	if(strcmp(barname,"BARCODE_ANY")==0)
	{
		return 0;
	}
	else if(strcmp(barname,"BARCODE_EAN")==0)
	{
		return 1;
	}
    else if(strcmp(barname,"BARCODE_UPC")==0) /* upc == 12-digit ean */
	{
		return 2;
	}
	else if(strcmp(barname,"BARCODE_ISBN")==0) /* isbn numbers (still EAN13) */
	{
		return 3;
	}
    else if(strcmp(barname,"BARCODE_39")==0)  /* code 39 */
	{
		return 4;
	}     
    else if(strcmp(barname,"BARCODE_128")==0)       /* code 128 (a,b,c: autoselection) */
    {
		return 5;
	}
	else if(strcmp(barname,"BARCODE_128C")==0)     /* code 128 (compact form for digits) */
    {
		return 6;
	}
    else if(strcmp(barname,"BARCODE_128B")==0)     /* code 128, full printable ascii */
    {
		return 7;
	}     
    else if(strcmp(barname,"BARCODE_I25")==0)     /* interleaved 2 of 5 (only digits) */
    {
		return 8;
	}       
	return 5;
}