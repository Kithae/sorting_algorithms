#include "sort.h"

/**
 * get_max - function to return maximum int array value.
 * @array: an array
 * @size: array size.
 *
 * Return: maximum array integer.
 */
int get_max(int *array, int size)
{
	int max, a;

	for (max = array[0], a = 1; a < size; a++)
	{
		if (array[a] > max)
			max = array[a];
	}

	return (max);
}

/**
 * counting_sort - uses counting sort algorithm
* to sort in ascending order
* @array: an array
 * @size: array size.
*/
void counting_sort(int *array, size_t size)
{
	int *tally, *curr, max, a;

	if (array == NULL || size < 2)
		return;

	curr = malloc(sizeof(int) * size);
	if (curr == NULL)
		return;
	max = get_max(array, size);
	tally = malloc(sizeof(int) * (max + 1));
	if (tally == NULL)
	{
		free(curr);
		return;
	}

	for (a = 0; a < (max + 1); a++)
		tally[a] = 0;
	for (a = 0; a < (int)size; a++)
		tally[array[a]] += 1;
	for (a = 0; a < (max + 1); a++)
		tally[a] += tally[a - 1];
	print_array(tally, max + 1);

	for (a = 0; a < (int)size; a++)
	{
		curr[tally[array[a]] - 1] = array[a];
		tally[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = curr[a];

	free(curr);
	free(tally);
}
