#include "sort.h"

/**
 * swap - function that swap two integers
 * @array: the array to be printed after each time we swap two elements
 * @first_number: the first number
 * @second_number: the second number
 *
 * Return: nothing
 */

void swap(int *array, int first_number, int second_number)
{
	int temp = array[first_number];

	array[first_number] = array[second_number];
	array[second_number] = temp;
}

/**
 * lomuto_partition - function to implant partition
 * @array: the array to be printed after each time we swap two elements
 * @low: the low number
 * @hight: the hight number
 * @size: the size of array
 *
 * Return: value
 */
int lomuto_partition(int *array, int low, int hight, size_t size)
{
	int pivot = array[hight];
	int i = low - 1;
	int j = 0;

	for (j = low; j < hight; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hight])
	{
		swap(array, i + 1, hight);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - function for recursive
 * @array: the array to be printed after each time we swap two elements
 * @low: the low number
 * @hight: the hight number
 * @size: the size of array
 *
 * Return: nothing
 */

void quick_sort_recursive(int *array, int low, int hight, size_t size)
{
	int pivot_index = 0;

	if (low < hight)
	{
		pivot_index = lomuto_partition(array, low, hight, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, hight, size);
	}
}

/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: the array to be printed after each time we swap two elements
 * @size: the size of array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

