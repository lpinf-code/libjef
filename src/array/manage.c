/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/array/manage.c
*/

#include "jef/array.h"
#include "jef/entity.h"

/**
 * @brief Create a new JSON array.
 *
 * This array will be allocated with
 * the pre-initialized size of `size`.
 *
 * @param size The size to pre-allocate the array with.
 * @returns The allocated array.
*/
json_array_t *json_array_new(size_t size)
{
    json_array_t *array = malloc(sizeof(json_array_t));

    if (array == NULL)
        return NULL;
    array->region_size = size;
    array->length = 0;
    array->content = malloc(sizeof(json_entity_t *) * array->region_size);
    if (array->content == NULL) {
        free(array);
        return NULL;
    }
    return array;
}

/**
 * @brief Destroys a JSON array.
 *
 * @param array The array to destroy.
*/
void json_array_destroy(json_array_t *array)
{
    for (size_t i = 0; i < array->length; i++) {
        json_entity_destroy(array->content[i]);
    }
    free(array->content);
    free(array);
}

/**
 * @brief Fetches a JSON array item.
 *
 * @param array The array to look in.
 * @param index The index to look at.
 * @returns The entity, or NULL if the index is out of bounds.
*/
json_entity_t *json_array_at(json_array_t *array, size_t index)
{
    return index >= array->length ? NULL : array->content[index];
}

static int expand_region(json_array_t *array)
{
    size_t old_size = array->region_size;
    json_entity_t **old_content = array->content;

    array->region_size = array->length * 2;
    array->content = malloc(sizeof(json_entity_t *) * array->region_size);
    if (array->content == NULL) {
        array->region_size = old_size;
        array->content = old_content;
        return -1;
    }
    for (size_t i = 0; i < old_size; i++)
        array->content[i] = old_content[i];
    free(old_content);
    return 0;
}

/**
 * @brief Inserts an item in a JSON array.
 *
 * @param array The array to insert in.
 * @param entity The entity to insert.
 * @returns 0 on success, -1 on error.
*/
int json_array_push(json_array_t *array, json_entity_t *entity)
{
    array->length++;
    if (array->length >= array->region_size)
        if (expand_region(array) == -1)
            return -1;
    array->content[array->length - 1] = entity;
    return 0;
}

/**
 * @brief Deletes the last item in a JSON array.
 *
 * @param array The array to delete in.
 * @returns The entity that used to reside in the array.
*/
json_entity_t *json_array_pop(json_array_t *array)
{
    array->length--;
    return array->content[array->length];
}
