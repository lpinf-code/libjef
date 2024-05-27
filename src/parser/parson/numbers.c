/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/parser/parson/numbers.c
*/

#include "jef/internal/parsing.h"
#include "jef/entity.h"

#include <stdbool.h>
#include <stddef.h>

static double exponentiate(struct json_token *tok, double value, int i)
{
    int exponent = 0;
    bool neg = (tok->begin[i + 1] == '-');

    for (i += 1 + neg; jef_tkn_isin(tok->begin[i], "0123456789") >= 0; i++)
        exponent = (exponent * 10) + (tok->begin[i] - '0');
    for (int j = 0; j < exponent; j++)
        if (neg)
            value = value / 10;
        else
            value = value * 10;
    return value;
}

double get_number(struct json_token *tok)
{
    double value = 0;
    double flt = 1;
    int i = (tok->begin[0] == '-');

    for (; jef_tkn_isin(tok->begin[i], "0123456789") >= 0; i++) {
        value = (value * 10) + (tok->begin[i] - '0');
    }
    if (tok->begin[i] == 'e' || tok->begin[i] == 'E') {
        return exponentiate(tok, value, i);
    }
    if (tok->begin[i] == '.') {
        for (i++; jef_tkn_isin(tok->begin[i], "0123456789") >= 0; i++) {
            flt = flt / 10;
            value += flt * (tok->begin[i] - '0');
        }
    }
    return value;
}

json_entity_t *jef_parson_number(struct json_tokens *tokens)
{
    double number = get_number(tokens->current);
    json_entity_t *entity = json_entity_new();

    if (entity == NULL)
        return NULL;
    if (tokens->current->type == JSON_TK_INTEGER)
        json_entity_set_integer(entity, (int64_t) number);
    else
        json_entity_set_number(entity, number);
    tokens->current = tokens->current->next;
    return entity;
}
