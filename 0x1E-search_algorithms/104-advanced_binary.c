#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers.
 * @array: Pointer to the first element of the array to search in.
 * @size: Number of elements in @array.
 * @value: Value to search for.
 *
 * Return: Index where @value is located, or -1 if not present or @array is NULL.
 */
int advanced_binary(int *array, size_t size, int value)
{
    size_t i;
    int result;

    if (array == NULL || size == 0)
        return (-1);

    printf("Searching in array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
    }
    printf("\n");

    if (size == 1 && array[0] != value)
        return (-1);

    if (array[size / 2] == value)
    {
        if (size % 2 == 0)
            result = size / 2 - 1;
        else
            result = size / 2;
        return (result);
    }

    if (array[size / 2] < value)
    {
        result = advanced_binary(array + size / 2 + 1,
                                 size - size / 2 - 1, value);
        if (result != -1)
            result += size / 2 + 1;
    }
    else
    {
        result = advanced_binary(array, size / 2, value);
    }

    return (result);
}
