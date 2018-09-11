/**
 * <h1>CppToken</h1>
 *
 * <p>Base class for Cpp token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "CppToken.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;

map<string, CppTokenType> CppToken::RESERVED_WORDS;
map<string, CppTokenType> CppToken::SPECIAL_SYMBOLS;
map<CppTokenType, string> CppToken::SPECIAL_SYMBOL_NAMES;

bool CppToken::INITIALIZED = false;

void CppToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {

        "auto", "double", "int", "struct", 
        "break", "else", "long", "switch", 
        "case", "enum", "namespace", "template",
        "char", "extern", "operator", "this",
        "class", "float", "protected", "throw", 
        "const", "for", "public", "union",
        "continue", "goto", "return", "void", 
        "do", "if", "static", "while"
    };

    vector<CppTokenType> rw_keys =
    {
        CppTokenType::AUTO,
        CppTokenType::DOUBLE,
        CppTokenType::INT,
        CppTokenType::STRUCT,

        CppTokenType::BREAK,
        CppTokenType::ELSE,
        CppTokenType::LONG,
        CppTokenType::SWITCH,

        CppTokenType::CASE,
        CppTokenType::ENUM,
        CppTokenType::NAMESPACE,
        CppTokenType::TEMPLATE,

        CppTokenType::CHAR,
        CppTokenType::EXTERN,
        CppTokenType::OPERATOR,
        CppTokenType::THIS,

        CppTokenType::CLASS,
        CppTokenType::FLOAT,
        CppTokenType::PROTECTED,
        CppTokenType::THROW,

        CppTokenType::CONST,
        CppTokenType::FOR,
        CppTokenType::PUBLIC,
        CppTokenType::UNION,

        CppTokenType::CONTINUE,
        CppTokenType::GOTO,
        CppTokenType::RETURN,
        CppTokenType::VOID,

        CppTokenType::DO,
        CppTokenType::IF,
        CppTokenType::STATIC,
        CppTokenType::WHILE

    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
        "~", "!", "@", "%", "^", "&", "*", "-", "+", "=", 
        "|", "/", ":", ";", "?", "<", ">", ".", ",", 
        "'", "\"", "(", ")", "[", "]", "{", "}", 
        "++", "--", "<<", ">>", "<=", ">=", "+=", "-=", "*=", "/=", 
        "==", "|=", "%=", "&=", "^=", "!=", "<<=", ">>=", "||", "&&", 
        "//", "/*", "*/"
    };

    vector<CppTokenType> ss_keys =
    {
        CppTokenType::TILDE,
        CppTokenType::NOT,
        CppTokenType::AT,
        CppTokenType::PERCENT,
        CppTokenType::CARET,
        CppTokenType::AND,
        CppTokenType::STAR,
        CppTokenType::MIUNS,
        CppTokenType::PLUS,
        CppTokenType::EQUALS,

        CppTokenType::LINE,
        CppTokenType::SLASH,
        CppTokenType::COLON,
        CppTokenType::SEMICOLON,
        CppTokenType::QUESTION,
        CppTokenType::LESS_THAN,
        CppTokenType::GREATER_THAN,
        CppTokenType::DOT,
        CppTokenType::COMMA,

        CppTokenType::SINGLE_QUOTE,
        CppTokenType::QUOTE,
        CppTokenType::LEFT_PAREN,
        CppTokenType::RIGHT_PAREN,
        CppTokenType::LEFT_BRACKET,
        CppTokenType::RIGHT_BRACKET,
        CppTokenType::LEFT_BRACE,
        CppTokenType::RIGHT_BRACE,

        CppTokenType::PLUS_PLUS,
        CppTokenType::MINUS_MINUS,
        CppTokenType::LEFT_SHIFT,
        CppTokenType::RIGHT_SHIFT,
        CppTokenType::LESS_EQUALS,
        CppTokenType::GREATER_EQUALS,
        CppTokenType::PLUS_EQUALS,
        CppTokenType::MINUS_EQUALS,
        CppTokenType::STAR_EQUALS,
        CppTokenType::SLASH_EQUALS,

        CppTokenType::EQUAL_EQUALS,
        CppTokenType::LINE_EQUALS,
        CppTokenType::PERCENT_EQUALS,
        CppTokenType::AND_EQUALS,
        CppTokenType::CARET_EQUALS,
        CppTokenType::NOT_EQUALS,
        CppTokenType::SHIFT_LEFT_EQUALS,
        CppTokenType::SHIFT_RIGHT_EQUALS,
        CppTokenType::LINE_LINE,
        CppTokenType::AND_AND, 

        CppTokenType::SLASH_SLASH,
        CppTokenType::SLASH_STAR,
        CppTokenType::STAR_SLASH
    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
         "TILDE", "NOT", "AT", "PERCENT", "CARET", "AND", "STAR", "MIUNS", "PLUS", "EQUALS",
         "LINE", "SLASH", "COLON", "SEMICOLON", "QUESTION", "LESS_THAN", "GREATER_THAN", "DOT", "COMMA",
         "SINGLE_QUOTE", "QUOTE", "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_BRACE", "RIGHT_BRACE",
         "PLUS_PLUS", "MINUS_MINUS", "LEFT_SHIFT", "RIGHT_SHIFT", "LESS_EQUALS", "GREATER_EQUALS", 
         "PLUS_EQUALS", "MINUS_EQUALS", "STAR_EQUALS", "SLASH_EQUALS",
         "EQUAL_EQUALS", "LINE_EQUALS", "PERCENT_EQUALS", "AND_EQUALS", "CARET_EQUALS", 
         "NOT_EQUALS", "SHIFT_LEFT_EQUALS", "SHIFT_RIGHT_EQUALS", "LINE_LINE", "AND_AND", 
         "SLASH_SLASH", "SLASH_STAR", "STAR_SLASH"
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

CppToken::CppToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::Cpp
