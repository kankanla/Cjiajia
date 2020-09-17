int& biggest(int array[], int n_elements)
{
    int index;	// Current index
    int biggest; // Index of the biggest element

    // Assume the first is the biggest
    biggest = 0;
    for (index = 1; index < n_elements; ++index) {
	if (array[biggest] < array[index])
	    biggest = index;
    }

    return (array[biggest]);
}
