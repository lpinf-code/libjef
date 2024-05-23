/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/parser/unserialize.c
*/

#include "jef/json.h"
#include "jef/parsing.h"
#include <stdlib.h>

/**
 * @brief Turns a JSON string into an entity.
 *
 * @param input The string to unserialize.
 * @returns An entity containing the data stored in the string. NULL on error.
 */
json_entity_t *json_unserialize(const char *input)
{
    struct json_tokens tokens = { .cursor = input };
    json_entity_t *entity;

    while (jef_tkn_next(&tokens) > 0);
    tokens.current = tokens.start;
    entity = jef_parse_entity(&tokens);
    tokens.current = tokens.start;
    for (; tokens.current != NULL; tokens.start = tokens.current) {
        tokens.current = tokens.start->next;
        free(tokens.start);
    }
    return entity;
}
