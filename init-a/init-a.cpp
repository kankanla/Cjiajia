#include <assert.h>

const int MAX = 10;

/********************************************************
 * init_array_1 -- Zero out an array			*
 *							*
 * Parameters						*
 *	data -- the array to zero			*
 ********************************************************/
void init_array_1(int data[])
{
    int  index;

    for (index = 0; index < MAX; ++index) {
	assert(index >= 0);
	assert(index < MAX);
        data[index] = 0;
}

/********************************************************
 * init_array_2 -- Zero out an array			*
 *							*
 * Parameters						*
 *	data_ptr -- pointer to array to zero		*
 ********************************************************/
void init_array_2(int *data_ptr)
{
    int index;

    for (index = 0; index < MAX; ++index)
        *(data_ptr + index) = 0;
}
int main()
{
    int  array[MAX];

    // one way of initializing the array
    init_array_1(array);

    // another way of initializing the array
    init_array_1(&array[0]);

    // Similar to the first method but
    //    function is different
    init_array_2(array);

    return (0);
}
