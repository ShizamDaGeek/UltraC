#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum
{
    TOKEN_COMMENT_SINGLE,   // Single Comment
    TOKEN_COMMENT_MULTI,    // Multi Comment

    // Symbols and Operators
    TOKEN_SEMICOLON,        // ;
    TOKEN_COLON,            // :
    TOKEN_COMMA,            // ,
    TOKEN_AMPERSAND,        // &

    // Arithmetic Operators
    TOKEN_PLUS,             // +
    TOKEN_MINUS,            // -
    TOKEN_MULTIPLY,         // *
    TOKEN_DIVIDE,           // /

    // System Functions
    TOKEN_SYSOUTPUT,        // System Output
    TOKEN_SYSINPUT,         // System Input
    TOKEN_SYSQUIT,          // System Quit

    // Data Types
    TOKEN_TYPEDEF,          // type
    TOKEN_INT,              // Integer literals (e.g., 100, -16)
    TOKEN_FLOAT,            // Float literals (e.g., 6.9, -6.9)
    TOKEN_STRING,           // String literals (e.g., "ShizamDa_Geek")
    TOKEN_CHAR,             // Character literals (e.g., 'S')
    TOKEN_BOOLEAN,          // Boolean (true/false)
    TOKEN_IDENTIFIER,       // Variable names (e.g., price, input, chance)
    TOKEN_POINTER,          // Pointer (&variable)
    TOKEN_VOID,             // void

    // Loops & Control Structures
    TOKEN_WHILE,            // While Loop
    TOKEN_FOR,              // For Loop
    TOKEN_SWITCH,           // Switch
    TOKEN_CASE,             // Case Statement 
    TOKEN_IF,               // If Statement
    TOKEN_ELSE_IF,          // Else if
    TOKEN_ELSE,             // Else Statement
    TOKEN_BREAK,            // Break
    TOKEN_CONTINUE,         // Continue

    // Comparison Operators
    TOKEN_LT,               // Less than (<)
    TOKEN_GT,               // Greater than (>)
    TOKEN_LE,               // Less than or equal to (<=)
    TOKEN_GE,               // Greater than or equal to (>=)
    TOKEN_EQ,               // Equal to (==)
    TOKEN_NE,               // Not equal to (!=)

    // Brackets & Parentheses
    TOKEN_LB,               // {
    TOKEN_RB,               // }
    TOKEN_LP,               // (
    TOKEN_RP,               // )
    TOKEN_LSB,              // [
    TOKEN_RSB,              // ]

    TOKEN_QUESTION_MARK,    // ? (Explain Code)
    TOKEN_EXCLAMATION_MARK, // ! (Stops code)
    TOKEN_PLUS_REPEAT,      // +() (Repeat output)
    TOKEN_GOTO,             // goto() (Jump to line)
    TOKEN_WAIT,             // wait() (Wait execution)

    TOKEN_LIST,             // List
    TOKEN_DICT,             // Dictionary

    TOKEN_NULL,             // NULL

}TokenType;

typedef struct Token
{
    TokenType Type;
    char* Value;
};

typedef struct Lexer
{
    const char *input;
    size_t pos;
    char current_char;
};

int main()
{
    

    return 0;
}