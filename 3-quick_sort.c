#include "sort.h"

/**
 * makeSwap - swap the values of two gived elements of an array
 * @left_index: First index
 * @right_index: Second index
 * @array: array to interact into
 * @size: Size of the array
 * Return: Nothing
 */
void makeSwap(int left_index, int right_index, int *array, size_t size)
{
	int tmp = 0;

	tmp = array[left_index];
	array[left_index] = array[right_index];
	array[right_index] = tmp;
	print_array(array, size);
}

/**
 * lomuto_partition - lomuto partition schema
 * @array: Array to sort in ascendant orde
 * @size: Size of the array
 * @low: Lowest index
 * @hight: Highest index
 * Return: Partition index
 *
 */
int lomuto_partition(int *array, int low, int hight, size_t size)
{
	int pivot = 0, low_case = 0, j;

	pivot = array[hight];
	low_case = low - 1;
	for (j = low; j < hight; j++)
	{
		if (pivot >= array[j])
		{
			low_case++;
			makeSwap(low_case, j, array, size);
		}
	}
	if (array[hight] < array[low_case + 1])
	{
		makeSwap(low_case + 1, hight, array, size);
	}
	return (low_case + 1);
}

/**
 * quick_sort_recurtion - Implementing recrsive sort function for the
 * Quick sort algorythm
 * @array: Array to sort in ascendant order
 * @low: Lowest index
 * @hight: Highest index
 * @size: Size of the array
 */
void quick_sort_recurtion(int *array, int low, int hight, size_t size)
{
	int part = 0;

	if (low < hight)
	{
		part = lomuto_partition(array, low, hight, size);
		quick_sort_recurtion(array, low, part - 1, size);
		quick_sort_recurtion(array, part + 1, hight, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 *  the Quick sort algorithm
 * @array: Array to sort in ascendant order
 * @size: Size of the array
 * Return: Nothing
 *
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recurtion(array, 0, size - 1, size);
}
