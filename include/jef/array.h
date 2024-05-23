/*
** EPITECH PROJECT, 2024
** jef
** File description:
** include/jef/array.h
*/

#include "types/array.h"
#include <stdlib.h>

#ifndef JEF_ARRAY_H
    #define JEF_ARRAY_H

/**
 * @brief Create a new JSON array.
 *
 * This array will be allocated with
 * the pre-initialized size of `size`.
 *
 * @param size The size to pre-allocate the array with.
 * @returns The allocated array.
*/
json_array_t *json_array_new(size_t size);

/**
 * @brief Destroys a JSON array.
 *
 * @param array The array to destroy.
*/
void json_array_destroy(json_array_t *array);

/**
 * @brief Fetches a JSON array item.
 *
 * @param array The array to look in.
 * @param index The index to look at.
 * @returns The entity, or NULL if the index is out of bounds.
*/
json_entity_t *json_array_at(json_array_t *array, size_t index);

/**
 * @brief Inserts an item in a JSON array.
 *
 * @param array The array to insert in.
 * @param entity The entity to insert.
 * @returns 0 on success, -1 on error.
*/
int json_array_push(json_array_t *array, json_entity_t *entity);

/**
 * @brief Deletes the last item in a JSON array.
 *
 * @param array The array to delete in.
 * @returns The entity that used to reside in the array.
*/
json_entity_t *json_array_pop(json_array_t *array);

#endif // !JEF_ARRAY_H
