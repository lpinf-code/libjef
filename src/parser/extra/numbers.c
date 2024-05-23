/*
** EPITECH PROJECT, 2024
** jef
** File description:
** src/parser/extra/numbers.c
*/

#include "jef/parsing.h"

static int decimals(struct json_tokens *tokens, struct json_token *tok)
{
    int i = 0;

    for (; jef_tkn_isin(tokens->cursor[i], "0123456789") >= 0; i++);
    if (i == 0) {
        tokens->errors++;
    }
    tok->size += i;
    tokens->cursor += i;
    return 1;
}

static int exponents(struct json_tokens *tokens, struct json_token *tok)
{
    int i = 1;

    if (jef_tkn_isin(tokens->cursor[0], "-0123456789") < 0)
        return 0;
    for (; jef_tkn_isin(tokens->cursor[i], "0123456789") >= 0; i++);
    if (i == 1 && tokens->cursor[0] == '-') {
        tokens->errors++;
    }
    tok->size += i;
    tokens->cursor += i;
    return 1;
}

int jef_tkn_number(struct json_tokens *tokens, struct json_token *tok)
{
    int i = 1;
    int index = 0;

    if (jef_tkn_isin(tokens->cursor[0], "-0123456789") >= 0) {
        tok->type = JSON_TK_NUMBER;
    } else
        return 0;
    for (; jef_tkn_isin(tokens->cursor[i], "0123456789") >= 0; i++);
    index = jef_tkn_isin(tokens->cursor[i], ".eE");
    if (i == 1 && tokens->cursor[0] == '-') {
        tokens->errors++;
        return 1;
    }
    tok->size += i;
    tokens->cursor += i;
    if (index == 0)
        return decimals(tokens, tok);
    if (index > 0)
        return exponents(tokens, tok);
    return 1;
}
