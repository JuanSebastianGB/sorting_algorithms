#include "sort.h"

/**
 * get_max_value - Get the max value of a gived array
 * @array: Array needed to get the max value
 * @size: Size of the array
 * @max_value: Max value to get/set
 * Return: Nothing
 */
void get_max_value(int *array, size_t size, int *max_value)
{
	int i;

	for (i = 0, *max_value = *array; i < (int)size; i++)
		if (array[i] > *max_value)
			*max_value = array[i];
}

/**
 * create_array - Create an array of 10 positions started in zeros
 * @size: size of the array to be created
 * Return: Array created
 *
 */
int *create_array(int size)
{
	int *array = NULL;

	array = malloc(sizeof(*array) * size);
	if (array == NULL)
		return (0);
	for (size = 0; size <= 9; size++)
		array[size] = size;

	return (array);
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int *base_array = NULL, max_value, copy_max_value, number_of_digits = 0;

	if (array == NULL || size < 2)
		return;
	base_array = create_array(10);
	if (!base_array)
		return;
	get_max_value(array, size, &max_value);
	copy_max_value = max_value;
	for (; copy_max_value != 0; copy_max_value /= 10, number_of_digits++)
		print_array(array, size);
	;
	free(base_array);
}
