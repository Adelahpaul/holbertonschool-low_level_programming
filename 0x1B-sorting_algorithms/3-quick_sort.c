#include "sort.h"

/**
 * quick_sort - sorts an array with the Quicksort algorithm
 * @array: array of ints to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		print_array(array, size);
		return;
	}

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - helper function for Quicksort
 * @array: array to sort
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
    		pivot = partition(array, left, right, size);
    		quick_recursion(array, left, pivot - 1, size);
    		quick_recursion(array, pivot+1, right, size);
	}
}

/**
 * partition - gives a pivot index for Quicksort
 * @array: array to find the pivot in
 * @left: index of the left element
 * @right: index of the right element
 * @size: size of the array
 *
 * Return: the index of the pivot element
 */
int partition(int *array, int left, int right, size_t size)
{
	int tmp, i;
	int j;

	i = left - 1;

	for (j = left; j < right; j++)
	{
		if (array[j] < array[right])
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[right] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}
