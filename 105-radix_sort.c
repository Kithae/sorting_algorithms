#include "sort.h"

/**
 * radix_sort - uses Radix sort algorithm to sort an array
 * @array: an array
 * @size: array size
 */
void radix_sort(int *array, size_t size)
{
	int cap;
	size_t a, lsd;

	if (!array || size < 2)
		return;

	cap = 0;
	for (a = 0; a < size; a++)
		if (array[a] > cap)
			cap = array[a];

	for (lsd = 1; cap / lsd > 0; lsd *= 10)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}

/**
 * count_sort_LSD - uses LSD to sort count
 * @array: an array
 * @size: array size
 * @lsd: least num
 */
void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int array_count[10] = {0}, *out_arr, l, j;
	size_t b, d;

	out_arr = malloc(sizeof(int) * size);

	for (b = 0; b < size; b++)
		array_count[(array[b] / lsd) % 10]++;
	for (l = 1; l < 10; l++)
		array_count[l] += array_count[l - 1];

	for (j = size - 1; j >= 0; j--)
	{
		out_arr[array_count[(array[j] / lsd) % 10] - 1] = array[j];
		array_count[(array[j] / lsd) % 10]--;
	}

	for (d = 0; d < size; d++)
		array[d] = out_arr[d];

	free(out_arr);
}
