#include "sort.h"

/**
 * makeSwap - swap the values of two gived elements of an array
 * @left_index: pointer to first index
 * @right_index: pointer to second index
 * Return: Nothing
 */
void makeSwap(int *left_index, int *right_index)
{
	int tmp = 0;

	tmp = *left_index;
	*left_index = *right_index;
	*right_index = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: Array to sort to
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, index, inner, actual_value;
	/* Getting the started interval*/
	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (index = interval; index < size; index++)
		{
			actual_value = array[index];
			inner = index;
			while (inner > interval - 1 && array[inner - interval] >= (int)actual_value)
			{
				array[inner] = array[inner - interval];
				inner -= interval;
			}
			array[inner] = actual_value;
		}
		interval = (interval - 1) / 3; /* Reducing interval */
		print_array(array, size);
	}
}
