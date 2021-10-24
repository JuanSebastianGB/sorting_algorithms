#include "sort.h"

/**
 * merge_arrays - Merge arrays
 * @array: Incoming array
 * @start: Left index
 * @mid: Middle index
 * @end: Right index
 * Return: Nothing
 */
void merge_arrays(int *array, int start, int mid, int end)
{
	int size = end - start + 1, from_initial = start, from_mid = mid + 1;
	int temporal[size], k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + start, mid - start);
	printf("[rigth]: ");
	print_array(array + mid, end - mid);
	for (k = 0; from_initial <= mid && from_mid <= end; k++)
	{

		if (array[from_initial] <= array[from_mid])
		{
			temporal[k] = array[from_initial];
			from_initial++;
		}
		else
		{
			temporal[k] = array[from_mid];
			from_mid++;
		}
	}
	for (; from_initial <= mid; from_initial++, k++)
		temporal[k] = array[from_initial];

	for (; from_mid <= end; from_mid++, k++)
		temporal[k] = array[from_mid];

	for (from_initial = start; from_initial <= end; from_initial++)
		array[from_initial] = temporal[from_initial - start];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * merge_sort_recurtion - sorts an array of integers in ascending order using
 *  the Merge sort algorithm
 * @array: Array to sort
 * @start: Left index
 * @end: Right index
 * Return: Nothing
 *
 */
void merge_sort_recurtion(int *array, int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort_recurtion(array, start, mid);
		merge_sort_recurtion(array, mid + 1, end);
		merge_arrays(array, start, mid, end);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order using
 * the Merge sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 *
 */
void merge_sort(int *array, size_t size)
{
	merge_sort_recurtion(array, 0, size - 1);
}
