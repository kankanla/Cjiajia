/*******************************************
 * triangle -- compute area of a triangle  *
 *                                         *
 * Parameters                              *
 *  width -- width of the triangle         *
 *  height -- height of the triangle       *
 *                                         *
 * Returns                                 *
 *  area of the triangle                   *
 *******************************************/
float triangle(float width, float height)
{
    float area; // area of the triangle 

    assert(width >= 0.0);
    assert(height >= 0.0);
    area = width * height / 2.0;
    return (area);
}
