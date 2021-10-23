#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: Array to sort to
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;

	(void)array;
	/* Getting the started interval*/
	while (interval <= size / 3)
		interval = (interval * 3) - 1;

	while (interval > 0)
	{
		interval = (interval + 1) / 3; /* Reducing interval */
		printf(" (%ld) ", interval);
	}
}
