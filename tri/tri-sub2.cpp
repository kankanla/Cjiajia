const float triangle(const float width, const float height)
{
    float area; // area of the triangle 

    assert(width >= 0.0);
    assert(height >= 0.0);
    area = width * height / 2.0;
    return (area);
}
