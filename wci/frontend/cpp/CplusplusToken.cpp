/**
 * <h1>CplusplusToken</h1>
 *
 * <p>Base class for Cplusplus token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "CplusplusToken.h"

namespace wci { namespace frontend { namespace Cplusplus {

using namespace std;

map<string, CplusplusTokenType> CplusplusToken::RESERVED_WORDS;
map<string, CplusplusTokenType> CplusplusToken::SPECIAL_SYMBOLS;
map<CplusplusTokenType, string> CplusplusToken::SPECIAL_SYMBOL_NAMES;

bool CplusplusToken::INITIALIZED = false;

void CplusplusToken::initialize()
{
    if (INITIALIZED) return;

    vector<string> rw_strings =
    {
        "AND", "ARRAY", "BEGIN", "CASE", "CONST", "DIV", "DO", "DOWNTO",
        "ELSE", "END", "FILE", "FOR", "FUNCTION", "GOTO", "IF", "IN",
        "LABEL", "MOD", "NIL", "NOT", "OF", "OR", "PACKED", "PROCEDURE",
        "PROGRAM", "RECORD", "REPEAT", "SET", "THEN", "TO", "TYPE",
        "UNTIL", "VAR", "WHILE", "WITH"
    };

    vector<CplusplusTokenType> rw_keys =
    {
        CplusplusTokenType::AND,
        CplusplusTokenType::ARRAY,
        CplusplusTokenType::BEGIN,
        CplusplusTokenType::CASE,
        CplusplusTokenType::CONST,
        CplusplusTokenType::DIV,
        CplusplusTokenType::DO,
        CplusplusTokenType::DOWNTO,

        CplusplusTokenType::ELSE,
        CplusplusTokenType::END,
        CplusplusTokenType::FILE,
        CplusplusTokenType::FOR,
        CplusplusTokenType::FUNCTION,
        CplusplusTokenType::GOTO,
        CplusplusTokenType::IF,
        CplusplusTokenType::IN,

        CplusplusTokenType::LABEL,
        CplusplusTokenType::MOD,
        CplusplusTokenType::NIL,
        CplusplusTokenType::NOT,
        CplusplusTokenType::OF,
        CplusplusTokenType::OR,
        CplusplusTokenType::PACKED,
        CplusplusTokenType::PROCEDURE,

        CplusplusTokenType::PROGRAM,
        CplusplusTokenType::RECORD,
        CplusplusTokenType::REPEAT,
        CplusplusTokenType::SET,
        CplusplusTokenType::THEN,
        CplusplusTokenType::TO,
        CplusplusTokenType::TYPE,

        CplusplusTokenType::UNTIL,
        CplusplusTokenType::VAR,
        CplusplusTokenType::WHILE,
        CplusplusTokenType::WITH
    };

    for (int i = 0; i < rw_strings.size(); i++)
    {
        RESERVED_WORDS[rw_strings[i]] = rw_keys[i];
    }

    vector<string> ss_strings =
    {
        "+", "-", "*", "/", ":=", ".", ",", ";", ":", "'", "=", "<>",
        "<", "<=", ">=", ">", "(", ")", "[", "]", "{", "}",  "^", ".."
    };

    vector<CplusplusTokenType> ss_keys =
    {
        CplusplusTokenType::PLUS,
        CplusplusTokenType::MINUS,
        CplusplusTokenType::STAR,
        CplusplusTokenType::SLASH,
        CplusplusTokenType::COLON_EQUALS,
        CplusplusTokenType::DOT,
        CplusplusTokenType::COMMA,
        CplusplusTokenType::SEMICOLON,
        CplusplusTokenType::COLON,
        CplusplusTokenType::QUOTE,
        CplusplusTokenType::EQUALS,
        CplusplusTokenType::NOT_EQUALS,

        CplusplusTokenType::LESS_THAN,
        CplusplusTokenType::LESS_EQUALS,
        CplusplusTokenType::GREATER_EQUALS,
        CplusplusTokenType::GREATER_THAN,
        CplusplusTokenType::LEFT_PAREN,
        CplusplusTokenType::RIGHT_PAREN,
        CplusplusTokenType::LEFT_BRACKET,
        CplusplusTokenType::RIGHT_BRACKET,
        CplusplusTokenType::LEFT_BRACE,
        CplusplusTokenType::RIGHT_BRACE,
        CplusplusTokenType::UP_ARROW,
        CplusplusTokenType::DOT_DOT
    };

    for (int i = 0; i < ss_strings.size(); i++)
    {
        SPECIAL_SYMBOLS[ss_strings[i]] = ss_keys[i];
    }

    vector<string> ss_names =
    {
        "PLUS", "MINUS", "STAR", "SLASH", "COLON_EQUALS", "DOT", "COMMA",
        "SEMICOLON", "COLON", "QUOTE", "EQUALS", "NOT_EQUALS",

        "LESS_THAN", "LESS_EQUALS", "GREATER_EQUALS", "GREATER_THAN",
        "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACKET", "RIGHT_BRACKET",
        "LEFT_BRACE", "RIGHT_BRACE", "UP_ARROW", "DOT_DOT"
    };

    for (int i = 0; i < ss_names.size(); i++)
    {
        SPECIAL_SYMBOL_NAMES[ss_keys[i]] = ss_names[i];
    }

    INITIALIZED = true;
}

CplusplusToken::CplusplusToken(Source *source) throw (string)
    : Token(source)
{
    initialize();
}

}}}  // namespace wci::frontend::Cplusplus
