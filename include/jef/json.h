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
 * @brief Turns an entity into JSON and writes the result into a file.
 *
 * @param entity The entity to serialize.
 * @param outptr A file descriptor at which the data is to be stored.
 * @param indent Indentation for objects/arrays, -1 to disable formatting.
 * @returns On success, returns the number of written bytes. -1 on failure.
 */
int json_serialize_file(json_entity_t *entity, int fd, int indent);


/**
 * @brief Turns a JSON string into an entity.
 *
 * @param input The string to unserialize.
 * @returns An entity containing the data stored in the string. NULL on error.
 */
json_entity_t *json_unserialize(const char *input);

/**
 * @brief Turns a file containing JSON into an entity.
 *
 * @param fd A file descriptor pointing to the file to unserialize.
 * @returns An entity containing the data stored in the string. NULL on error.
 */
json_entity_t *json_unserialize_file(int fd);

#endif // !JEF_JSON_H
