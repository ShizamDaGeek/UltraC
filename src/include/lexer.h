#ifndef LEXER_H
#define LEXER_H

#include "libs.h"

typedef struct LEXER_STRUCT
{
    char currentCharacter;
    unsigned int index;
    char* contents;

} lexer_T;

// Initialize lexer
lexer_T* init_lexer(char* contents);

// Move pointer to the next character in the contents
void lexer_advanced(lexer_T* lexer);

// Skip whitespace
void lexer_skip_whitespace(lexer_T* lexer);

// Get next token in contents
token_T* lexer_get_next_token(lexer_T* lexer);

// Define how to parse a string
token_T* lexer_collect_string(lexer_T* lexer);

// Define how to parse an identifier
token_T* lexer_collect_identifier(lexer_T* lexer);

// Helper code for clean code
token_T* lexer_advanced_with_token(lexer_T* lexer, token_T* token);

// Return a char array
char* lexer_get_current_char_as_string(lexer_T* lexer);

#endif