const int X_SIZE = 60;
const int Y_SIZE = 30;

int matrix[X_SIZE][Y_SIZE];

void init_matrix()
{
    register int *matrix_ptr;	// Current element

    for (matrix_ptr = &matrix[0][0]; 
	     matrix_ptr <= &matrix[X_SIZE-1][Y_SIZE-1];
	     ++matrix_ptr) {

	*matrix_ptr = -1;
    }
}
