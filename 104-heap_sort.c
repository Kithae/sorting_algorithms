#include "sort.h"

/**
* stupify - a function to heapfiy recurrssively
* @array: an array
* @heap: heap data size
* @i: an index
* @size: array size
*/

void stupify(int *array, int heap, int i, int size)
{
	int stup = i, left = 2 * i + 1, right = 2 * i + 2, t;

	if (left < heap && array[left] > array[stup])
		stup = left;
	if (right < heap && array[right] > array[stup])
		stup = right;
	if (stup != i)
	{
		t = array[i], array[i] = array[stup], array[stup] = t;
		print_array(array, size);
		stupify(array, heap, stup, size);
	}
}

/**
* heap_sort - uses heap sort algo to sort arrays
* @array: an array
* @size: array size
*/

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; i >= 0; i--)
		stupify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		if (i > 0)
			print_array(array, size);
		stupify(array, i, 0, size);
	}
}
