/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/parser/parson/object.c
*/

#include <stddef.h>

#include "jef/internal/parsing.h"
#include "jef/array.h"
#include "jef/entity.h"

static int run_array_parser(json_entity_t *entity, struct json_tokens *tokens)
{
    json_entity_t *ent2;

    if (tokens->current->type == JSON_TK_SEP) {
        tokens->current = tokens->current->next;
        if (tokens->current == NULL)
            return -1;
    }
    if (tokens->current->type == JSON_TK_ARR_END)
        return 0;
    ent2 = jef_parse_entity(tokens);
    if (ent2 == NULL)
        return -1;
    json_array_push(entity->content.array, ent2);
    if (tokens->current->type != JSON_TK_SEP
        && tokens->current->type != JSON_TK_ARR_END)
        return -1;
    return 1;
}

static int parse_array(json_entity_t *entity, struct json_tokens *tokens)
{
    int a = 1;

    while (a > 0)
        a = run_array_parser(entity, tokens);
    if (a < 0)
        return 0;
    tokens->current = tokens->current->next;
    return 1;
}

json_entity_t *jef_parson_array(struct json_tokens *tokens)
{
    json_entity_t *entity;

    tokens->current = tokens->current->next;
    if (tokens->current == NULL)
        return NULL;
    entity = json_entity_new();
    if (entity == NULL)
        return NULL;
    json_entity_set_array(entity, json_array_new(10));
    if (entity->content.object == NULL) {
        json_entity_destroy(entity);
        return NULL;
    }
    if (parse_array(entity, tokens)) {
        return entity;
    } else
        json_entity_destroy(entity);
    return NULL;
}
