
int format_coordinates( char *dest, int x,int y, char ch  )
{
	return sprintf( dest, " %i:%i:%c", x,y, ch);
}
int format_float_coordinates( char *dest, double x,double y, char ch)
{
	return sprintf( dest, " %g:%g:%c", x,y, ch);
}
