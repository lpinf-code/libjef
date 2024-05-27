/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/parser/tokenizer.c
*/

#include "jef/internal/parsing.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const char *const KEYWORDS[] = {
    "null",
    "true",
    "false"
};

int jef_tkn_isin(char c, const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (c == str[i])
            return i;
    return -1;
}

static int iseq(const char *s1, const char *s2)
{
    int i = 0;

    for (i = 0; s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return 0;
    return jef_tkn_isin(s1[i], JEF_IDENTIFYER) >= 0 ? 0 : i;
}

static void push_token(struct json_tokens *tokens, struct json_token *tok)
{
    if (tokens->start == NULL) {
        tokens->start = tok;
        tokens->end = tok;
    } else {
        tokens->end->next = tok;
        tokens->end = tok;
    }
}

static int get_string(struct json_tokens *tokens, struct json_token *tok)
{
    int i = 0;
    int index = jef_tkn_isin(tokens->cursor[0], JEF_STR_DELIM);
    bool escape = false;

    if (index == -1)
        return 0;
    for (i = 1; tokens->cursor[i] != '\0' && index >= 0; i++) {
        if (escape) {
            escape = false;
            continue;
        }
        if (jef_tkn_isin(tokens->cursor[i], JEF_STR_DELIM) == index)
            index = -1;
        escape = (tokens->cursor[i] == '\\');
    }
    tokens->errors += (index >= 0);
    tok->size = i - 2;
    tok->begin++;
    tokens->cursor += i;
    return 1;
}

static int get_static(struct json_tokens *tokens, struct json_token *tok)
{
    int index = jef_tkn_isin(tokens->cursor[0], "ntf");
    int len = 0;

    if (index == -1)
        return 0;
    len = iseq(tokens->cursor, KEYWORDS[index]);
    if (len) {
        tok->type = JSON_TK_NULL + index;
        tok->size += len - 1;
        tokens->cursor += len;
        return 1;
    }
    return 0;
}

static int get_uniq(struct json_tokens *tokens, struct json_token *tok)
{
    if (tokens->cursor[0] == '{')
        tok->type = JSON_TK_OBJ_START;
    if (tokens->cursor[0] == '}')
        tok->type = JSON_TK_OBJ_END;
    if (tokens->cursor[0] == '[')
        tok->type = JSON_TK_ARR_START;
    if (tokens->cursor[0] == ']')
        tok->type = JSON_TK_ARR_END;
    if (tokens->cursor[0] == ',')
        tok->type = JSON_TK_SEP;
    if (tokens->cursor[0] == ':')
        tok->type = JSON_TK_KV;
    tokens->cursor++;
    return 1;
}

static int get_token(struct json_tokens *tokens, struct json_token *tok)
{
    if (jef_tkn_isin(tokens->cursor[0], "{}[],:") >= 0) {
        return get_uniq(tokens, tok);
    }
    if (get_string(tokens, tok)) {
        tok->type = JSON_TK_STRING;
        return 1;
    } else if (jef_tkn_number(tokens, tok) || get_static(tokens, tok))
        return 1;
    return 1;
}

int jef_tkn_next(struct json_tokens *tokens)
{
    struct json_token *tok;
    int res;

    while (jef_tkn_isin(tokens->cursor[0], " \n\t\r") >= 0)
        tokens->cursor++;
    if (tokens->cursor[0] == '\0')
        return 0;
    tok = malloc(sizeof(struct json_token));
    tok->next = NULL;
    if (tok == NULL) {
        tokens->errors = -1;
        return -1;
    }
    tok->type = JSON_INVALID;
    tok->size = 1;
    tok->begin = tokens->cursor;
    res = get_token(tokens, tok);
    push_token(tokens, tok);
    return tokens->errors || tok->type == JSON_INVALID ? -1 : res;
}
