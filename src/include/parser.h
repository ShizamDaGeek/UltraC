#ifndef PARSER_H
#define PARSER_H

#include "libs.h"

typedef struct PARSER_STRUCT
{
    lexer_T* lexer;
    lexer_T* currentToken;
} parser_T;

// Initialize parser
parser_T* init_parser(lexer_T* lexer);

// Expect a certain token
void parser_eat(parser_T* parser, int token_type);

AST_T* parser_parse(parser_T* parser);

#endif