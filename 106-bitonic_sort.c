#include "sort.h"


/**
* swapint - swaps indexes of array
* @l: left index
* @r: right index
*/

void swapint(int *l, int *r)
{
	int temp;

	temp = *l;
	*l = *r;
	*r = temp;
}

/**
* b_merge - a function for a bitonic merge
* @array: an array
* @low: min index
* @count: slice count
* @dir: the ascend (1) or descend (0) direction
* @size: an array size
*/

void b_merge(int *array, int low, int count, int dir, size_t size)
{
	int a, b;

	if (count > 1)
	{
		b = count / 2;
		for (a = low; a < low + b; a++)
		{
			if (((array[a] > array[a + b]) && dir == 1) ||
			(dir == 0 && (array[a] < array[a + b])))
				swapint(&array[a], &array[a + b]);
		}
		b_merge(array, low, n, dir, size);
		b_merge(array, low + n, n, dir, size);
	}
}

/**
* b_sort - recursive sort bitonic function
* @array: an array
* @low: min index
* @count: slice count
* @dir: the ascend (1) or descend (0) direction
* @size: array size
*/

void b_sort(int *array, int low, int count, int dir, size_t size)
{
	int b;

	if (count > 1)
	{
		b = count / 2;
		printf("Merging [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
		b_sort(array, low, n, 1, size);
		b_sort(array, low + n, n, 0, size);
		b_merge(array, low, count, dir, size);
		printf("Result [%d/%d] ", count, (int)size);
		if (dir == 1)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + low, count);
	}
}

/**
* bitonic_sort – uses bitonic algo to sorts array
* @array: an array
* @size: array size
*/

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	b_sort(array, 0, size, 1, size);
}
