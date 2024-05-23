/*
** EPITECH PROJECT, 2024
** jef
** File description:
** include/jef/parsing.h
*/

#include "jef/types/defs.h"

#ifndef JEF_PARSING_H
    #define JEF_PARSING_H

    #define JEF_STR_DELIM "\"\'"
    #define JEF_IDENTIFYER "abcdefghijklmnopqrstuvwxyz_"

    #define JEF_CHAR_REP(c, a1, r) c = (c == a1) ? r : c

enum json_tk_type {
    JSON_TK_OBJ_START,
    JSON_TK_OBJ_END,
    JSON_TK_ARR_START,
    JSON_TK_ARR_END,
    JSON_TK_STRING,
    JSON_TK_NUMBER,
    JSON_TK_INTEGER,
    JSON_TK_NULL,
    JSON_TK_TRUE,
    JSON_TK_FALSE,
    JSON_TK_SEP,
    JSON_TK_KV,
    JSON_INVALID
};

struct json_token {
    enum json_tk_type type;
    const char *begin;
    int size;
    struct json_token *next;
};

struct json_tokens {
    struct json_token *start;
    struct json_token *current;
    struct json_token *end;
    const char *cursor;
    int errors;
};

int jef_tkn_isin(char c, const char *str);

int jef_tkn_next(struct json_tokens *tokens);

int jef_tkn_number(struct json_tokens *tokens, struct json_token *tok);

json_entity_t *jef_parse_entity(struct json_tokens *tokens);

json_entity_t *jef_parson_object(struct json_tokens *tokens);
json_entity_t *jef_parson_array(struct json_tokens *tokens);
json_entity_t *jef_parson_static(struct json_tokens *tokens);
json_entity_t *jef_parson_number(struct json_tokens *tokens);
json_entity_t *jef_parson_string(struct json_tokens *tokens);

#endif // !JEF_PARSING_H
