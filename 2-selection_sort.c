#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: the array to be printed after each time we swap two elements
 * @size: the size of array
 *
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, temp, min_position;

	if (array == NULL)
	{
		return;
	}
	if (size < 2)
	{
		return;
	}
	for (i = 0; i < (size - 1); i++)
	{
		min_position = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_position])
				min_position = j;
		}
		if (min_position != i)
		{

			temp = array[i];
			array[i] = array[min_position];
			array[min_position] = temp;
			print_array(array, size);
		}
	}
}
