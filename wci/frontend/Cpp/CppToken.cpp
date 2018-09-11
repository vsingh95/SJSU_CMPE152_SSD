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
        "AUTO", "DOUBLE", "INT", "STRUCT", "BREAK", "ELSE", "LONG", "SWITCH",
        "CASE", "ENUM", "NAMESPACE", "TEMPLATE", "CHAR", "EXTERN", "OPERATOR", "THIS",
        "CLASS", "FLOAT", "PROTECTED", "THROW", "CONST", "FOR", "PUBLIC", "UNION",
        "CONTINUE", "GOTO", "RETURN", "VOID", "DO", "IF", "STATIC",
        "WHILE"
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
        "+", "-", "*", "/", "~", ".", ",", ";", ":", "'", "=", "!=",
        "<", "<=", ">=", ">", "(", ")", "[", "]", "{", "}",  "^", "!",
        "@", "%", "&", "|", "?", ",", ".", "++", "--", "<<",  ">>", "+=",
        "-=", "*=", "/=", "==", "|=", "%=", "&=", "^=", "!=", "<<=",  ">>=", "||",
        "&&", "//", "/*", "*/"
    };

    vector<CppTokenType> ss_keys =
    {
        CppTokenType::PLUS,
        CppTokenType::MINUS,
        CppTokenType::STAR,
        CppTokenType::SLASH,
        CppTokenType::SLASH,
        CppTokenType::DOT,
        CppTokenType::COMMA,
        CppTokenType::SEMICOLON,
        CppTokenType::COLON,
        CppTokenType::QUOTE,
        CppTokenType::EQUALS,
        CppTokenType::NOT_EQUALS,

        CppTokenType::LESS_THAN,
        CppTokenType::LESS_EQUALS,
        CppTokenType::GREATER_EQUALS,
        CppTokenType::GREATER_THAN,
        CppTokenType::LEFT_PAREN,
        CppTokenType::RIGHT_PAREN,
        CppTokenType::LEFT_BRACKET,
        CppTokenType::RIGHT_BRACKET,
        CppTokenType::LEFT_BRACE,
        CppTokenType::RIGHT_BRACE,
        CppTokenType::UP_ARROW,
        CppTokenType::EXCLAMATION,

        CppTokenType::AT,
        CppTokenType::PERCENT,
        CppTokenType::AND,
        CppTokenType::LINE,
        CppTokenType::QUESTION,
        CppTokenType::COMMA,
        CppTokenType::PERIOD,
        CppTokenType::PLUS_PLUS,
        CppTokenType::MINUS_MINUS,
        CppTokenType::LESS_LESS,
        CppTokenType::GREATER_GREATER,
        CppTokenType::PLUS_EQUAL,

        CppTokenType::MINUS_EQUAL,
        CppTokenType::STAR_EQUAL,
        CppTokenType::SLASH_EQUAL,
        CppTokenType::EQUAL_EQUAL,
        CppTokenType::LINE_EQUAL,
        CppTokenType::PERCENT_EQUAL,
        CppTokenType::AND_EQUAL,
        CppTokenType::UP_ARROW_EQUAL,
        CppTokenType::EXCLAMATION_EQUAL,
        CppTokenType::LESS_LESS_EQUAL,
        CppTokenType::GREATER_GREATER_EQUAL,
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
        "PLUS", "MINUS", "STAR", "SLASH", "TILDA", "DOT", "COMMA",
        "SEMICOLON", "COLON", "QUOTE", "EQUALS", "NOT_EQUALS",

        "LESS_THAN", "LESS_EQUALS", "GREATER_EQUALS", "GREATER_THAN",
        "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
        "LEFT_BRACE", "RIGHT_BRACE", "UP_ARROW", "EXCLAMATION",

        "AT", "PERCENT", "AND", "LINE",
        "QUESTION", "COMMA", "PERIOD", "PLUS_PLUS",
        "MINUS_MINUS", "LESS_LESS", "GREATER_GREATER", "PLUS_EQUAL",

        "MINUS_EQUAL", "STAR_EQUAL", "SLASH_EQUAL", "EQUAL_EQUAL",
        "LINE_EQUALE", "PERCENT_EQUALT", "AND_EQUAL", "UP_ARROW_EQUAL",
        "EXCLAMATION_EQUAL", "LESS_LESS_EQUAL", "GREATER_GREATER_EQUAL", "LINE_LINE",
        "AND_AND", "SLASH_SLASH", "SLASH_STAR", "STAR_SLASH"
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
