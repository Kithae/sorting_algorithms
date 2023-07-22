#include "sort.h"
/**
 * shell_sort - uses shell_sort algorithm to sort an array
 * @array: an array
 * @size: array size
 * Return: NULL
 **/
void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, a, b;
	int tmp;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (a = gap; a < size; a++)
		{
			tmp = array[a];
			b = a;
			while (b >= gap && array[b - gap] > tmp)
			{
				array[b] = array[b - gap];
				b -= gap;
			}
			array[b] = tmp;
		}
		print_array(array, size);
		gap /= 3;
	}
}
