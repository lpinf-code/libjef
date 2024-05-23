/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/parser/parson/object.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "jef/parsing.h"
#include "jef/object.h"
#include "jef/entity.h"

static int early_keyed_exit(char *key)
{
    free(key);
    return -1;
}

static int get_value(
    char *key,
    json_entity_t *entity,
    struct json_tokens *tokens
)
{
    json_entity_t *ent2;

    if (tokens->current == NULL || tokens->current->type != JSON_TK_KV)
        return early_keyed_exit(key);
    tokens->current = tokens->current->next;
    if (tokens->current == NULL)
        return early_keyed_exit(key);
    ent2 = jef_parse_entity(tokens);
    if (ent2 == NULL)
        return early_keyed_exit(key);
    json_object_push(entity->content.object, key, ent2, true);
    ent2->dynamic_value = false;
    json_entity_destroy(ent2);
    if (tokens->current->type != JSON_TK_SEP
        && tokens->current->type != JSON_TK_OBJ_END)
        return -1;
    return 1;
}

static int run_object_parser(json_entity_t *entity, struct json_tokens *tokens)
{
    json_entity_t *str;
    char *key;

    if (tokens->current->type == JSON_TK_SEP) {
        tokens->current = tokens->current->next;
        if (tokens->current == NULL)
            return -1;
    }
    if (tokens->current->type == JSON_TK_OBJ_END)
        return 0;
    if (tokens->current->type != JSON_TK_STRING)
        return -1;
    str = jef_parson_string(tokens);
    printf(" - is key of :\n");
    if (str == NULL)
        return -1;
    key = str->content.string;
    str->content.string = NULL;
    json_entity_destroy(str);
    return get_value(key, entity, tokens);
}

static int parse_object(json_entity_t *entity, struct json_tokens *tokens)
{
    int a = 1;

    while (a > 0) {
        a = run_object_parser(entity, tokens);
    }
    if (a < 0)
        return 0;
    tokens->current = tokens->current->next;
    return 1;
}

json_entity_t *jef_parson_object(struct json_tokens *tokens)
{
    json_entity_t *entity;

    printf("OBJECT.\n");
    tokens->current = tokens->current->next;
    if (tokens->current == NULL)
        return NULL;
    entity = json_entity_new();
    if (entity == NULL)
        return NULL;
    json_entity_set_object(entity, json_object_new());
    if (entity->content.object == NULL) {
        json_entity_destroy(entity);
        return NULL;
    }
    if (parse_object(entity, tokens)) {
        printf("OBJECT : %p.\n", entity);
        return entity;
    } else {
        printf("OBJECT : Failure.\n");
        json_entity_destroy(entity);
    }
    return NULL;
}
