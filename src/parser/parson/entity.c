/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/parser/parson/automatic.c
*/

#include <stddef.h>
#include <stdlib.h>

#include "jef/internal/parsing.h"
#include "jef/entity.h"

json_entity_t *jef_parson_static(struct json_tokens *tokens)
{
    json_entity_t *entity = json_entity_new();

    if (entity == NULL)
        return NULL;
    switch (tokens->current->type) {
        case JSON_TK_NULL:
            break;
        case JSON_TK_TRUE:
            json_entity_set_boolean(entity, true);
            break;
        case JSON_TK_FALSE:
            json_entity_set_boolean(entity, false);
            break;
        default:
            return NULL;
    }
    tokens->current = tokens->current->next;
    return entity;
}

static void run_str_escape(
    json_entity_t *ent,
    struct json_tokens *tokens,
    int i,
    int *cur_ptr
)
{
    char c = tokens->current->begin[i];

    JEF_CHAR_REP(c, 'n', '\n');
    JEF_CHAR_REP(c, 'r', '\r');
    JEF_CHAR_REP(c, 't', '\t');
    JEF_CHAR_REP(c, 'b', '\b');
    JEF_CHAR_REP(c, 'f', '\f');
    ent->content.string[*cur_ptr] = c;
    (*cur_ptr)++;
}

static void run_str_loop(json_entity_t *ent, struct json_tokens *tokens)
{
    int cur = 0;
    bool escape = false;

    for (int i = 0; i < tokens->current->size; i++) {
        if (escape) {
            escape = false;
            run_str_escape(ent, tokens, i, &cur);
            continue;
        }
        if (tokens->current->begin[i] == '\\')
            escape = true;
        else {
            ent->content.string[cur] = tokens->current->begin[i];
            cur++;
        }
    }
    ent->content.string[cur] = 0;
}

json_entity_t *jef_parson_string(struct json_tokens *tokens)
{
    json_entity_t *ent = json_entity_new();

    if (ent != NULL)
        json_entity_set_string(ent, malloc(tokens->current->size + 1), true);
    if (ent->content.string == NULL)
        return NULL;
    run_str_loop(ent, tokens);
    tokens->current = tokens->current->next;
    return ent;
}

json_entity_t *jef_parse_entity(struct json_tokens *tokens)
{
    switch (tokens->current->type) {
        case JSON_TK_OBJ_START:
            return jef_parson_object(tokens);
        case JSON_TK_ARR_START:
            return jef_parson_array(tokens);
        case JSON_TK_NULL:
        case JSON_TK_TRUE:
        case JSON_TK_FALSE:
            return jef_parson_static(tokens);
        case JSON_TK_NUMBER:
        case JSON_TK_INTEGER:
            return jef_parson_number(tokens);
        case JSON_TK_STRING:
            return jef_parson_string(tokens);
        default:
            return NULL;
    }
}
