inline void stack::push(const int item)
{
    assert((count >= 0) &&
	   (count < sizeof(data)/sizeof(data[0])));
    data[count] = item;
    ++count;
}
