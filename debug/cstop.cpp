float point_color(int point_number)
{
    float correction;  		// color correction factor 
    extern float red,green,blue;// current colors 

    // Lookup color correction
    extern lookup(int point_number);

    correction = lookup(point_number);
    return (red*correction * 100.0 + 
	    blue*correction * 10.0 +
	    green*correction);
}
