/*
** EPITECH PROJECT, 2024
** jef
** File description:
** include/jef/json.h
*/

/**
 * @file
 * @brief JSON serialize/unserialize functions.
*/

#include "types/defs.h"
#include <stdio.h>

#ifndef JEF_JSON_H
    #define JEF_JSON_H

/**
 * @brief Turns an entity into a valid JSON string.
 *
 * @param entity The entity to serialize.
 * @param outptr The pointer to store the string to.
 * @param indent Indentation for objects/arrays, -1 to disable formatting.
 * @returns On success, returns the string buffer size. -1 on failure.
 */
ssize_t json_serialize(json_entity_t *entity, char **outptr, int indent);

/**
 * @brief Turns a JSON string into an entity.
 *
 * @param input The string to unserialize.
 * @returns An entity containing the data stored in the string. NULL on error.
 */
json_entity_t *json_unserialize(const char *input);

#endif // !JEF_JSON_H
