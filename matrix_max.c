#include <stdio.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int *function_01(int rows, int cols, int mat[][cols], int *min_of_max);
void print_matrix_and_maxrow(int rows, int cols, int mat[][cols], int array_max[]);

int main(int argc, char const *argv[])
{
	int mat[ROWS][COLS]={{2,5,3,9},{55,7,3,6},{2,22,3,5}};
	int *min_of_max;
	int *max_of_rows = (*int) malloc(sizeof(int) * rows);
	max_of_rows = funcion_01(ROWS, COLS, mat, min_of_max);
	print_matrix_and_maxrow(ROWS, COLS, mat, max_of_rows);
	printf("\nIl valore minimo tra i valori massimi e': %d", *min_of_max);
	return 0;
}

int *function_01(int rows, int cols, int mat[][cols], int *min_of_max){
	int *max_of_rows = (int *) malloc(sizeof(int) * rows);

	if (max_of_rows != NULL)
	{
		//initialize max_of_rows
		for (int i = 0; i < rows; ++i)
		{
			max_of_rows[i]=mat[i][0];
		}

		//find the max for each row and store on array "max_of_rows"
		for (int i = 0; i < rows; ++i)
		{
			for (int l = 0; l < cols; ++l)
			{
				if (max_of_rows[i] < mat[i][l])
				{
					max_of_rows[i] = mat[i][l];
				}
			}
		}

		//initialize min_of_max
		*min_of_max = max_of_rows[0];

		//found the min of array "max_of_rows" and store in *min_of_max
		for (int i = 0; i < rows; ++i)
		{
			if (*min_of_max > max_of_rows[i])
			{
				*min_of_max = max_of_rows[i];
			}
		}
	
		//return array address
		return max_of_rows;
	}	
}

void print_matrix_and_maxrow(int rows, int cols, int mat[][cols], int array_max[]){
	for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			printf(" %3d ", mat[i][j]);
		}
		printf("\tmax: %d\n", array_max[i]);
	}
}
