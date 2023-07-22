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
	int a = i, left = 2 * i + 1, right = 2 * i + 2, t;

	if (left < heap && array[left] > array[a])
		a = left;
	if (right < heap && array[right] > array[a])
		a = right;
	if (a != i)
	{
		t = array[i], array[i] = array[lar], array[lar] = t;
		print_array(array, size);
		stupify(array, heap, a, size);
	}
}

/**
* heap_sort - uses heap sort algo to sort arrays
* @array: an array
* @size: array size
*/

void heap_sort(int *array, size_t size)
{
	int b = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; b >= 0; b--)
		stupify(array, size, b, size);
	for (b = size - 1; b >= 0; b--)
	{
		temp = array[0];
		array[0] = array[b];
		array[b] = temp;
		if (b > 0)
			print_array(array, size);
		stupify(array, b, 0, size);
	}

}
