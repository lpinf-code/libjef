/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/parser/unserialize.c
*/

#include "jef/json.h"
#include "jef/parsing.h"

/**
 * @brief Turns a JSON string into an entity.
 *
 * @param input The string to unserialize.
 * @returns An entity containing the data stored in the string. NULL on error.
 */
json_entity_t *json_unserialize(const char *input)
{
    struct json_tokens tokens = { .cursor = input };

    while (jef_tkn_next(&tokens));
    return NULL;
}
