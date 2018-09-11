/**
 * <h1>CppToken</h1>
 *
 * <p>Base class for Cpp token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_Cpp_CppTOKEN_H_
#define WCI_FRONTEND_Cpp_CppTOKEN_H_

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace Cpp {

using namespace std;
using namespace wci::frontend;

/**
 * Cpp token types.
 */
enum class CppTokenType
{
    // Reserved words.
    AUTO, DOUBLE, INT, STRUCT, BREAK, ELSE, LONG, SWITCH, CASE,
    ENUM, NAMESPACE, TEMPLATE, CHAR, EXTERN, OPERATOR, THIS, CLASS,
    FLOAT, PROTECTED, THROW, CONST, FOR, PUBLIC, UNION, CONTINUE, GOTO,
    RETURN, VOID, DO, IF, STATIC, WHILE,

    // Special symbols.
    PLUS, MINUS, STAR, SLASH, TILDA,
    DOT, COMMA, SEMICOLON, COLON, QUOTE,
    EQUALS, NOT_EQUALS, LESS_THAN, LESS_EQUALS,
    GREATER_EQUALS, GREATER_THAN, LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE,
    UP_ARROW, EXCLAMATION, AT, PERCENT, AND, LINE, QUESTION,
    PERIOD, PLUS_PLUS, MINUS_MINUS, LESS_LESS, GREATER_GREATER, PLUS_EQUAL,
    MINUS_EQUAL, STAR_EQUAL, SLASH_EQUAL, EQUAL_EQUAL, LINE_EQUAL, PERCENT_EQUAL,
    AND_EQUAL, UP_ARROW_EQUAL, EXCLAMATION_EQUAL, LESS_LESS_EQUAL, GREATER_GREATER_EQUAL,
    LINE_LINE, AND_AND, SLASH_SLASH, SLASH_STAR, STAR_SLASH,



    IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE,
};

constexpr CppTokenType PT_AUTO = CppTokenType::AUTO;
constexpr CppTokenType PT_DOUBLE = CppTokenType::DOUBLE;
constexpr CppTokenType PT_INT = CppTokenType::INT;
constexpr CppTokenType PT_STRUCT = CppTokenType::STRUCT;
constexpr CppTokenType PT_BREAK = CppTokenType::BREAK;
constexpr CppTokenType PT_ELSE = CppTokenType::ELSE;
constexpr CppTokenType PT_LONG = CppTokenType::LONG;
constexpr CppTokenType PT_SWITCH = CppTokenType::SWITCH;

constexpr CppTokenType PT_CASE = CppTokenType::CASE;
constexpr CppTokenType PT_ENUM = CppTokenType::ENUM;
constexpr CppTokenType PT_NAMESPACE = CppTokenType::NAMESPACE;
constexpr CppTokenType PT_TEMPLATE = CppTokenType::TEMPLATE;
constexpr CppTokenType PT_CHAR = CppTokenType::CHAR;
constexpr CppTokenType PT_EXTERN = CppTokenType::EXTERN;
constexpr CppTokenType PT_OPERATOR = CppTokenType::OPERATOR;
constexpr CppTokenType PT_THIS = CppTokenType::THIS;

constexpr CppTokenType PT_CLASS = CppTokenType::CLASS;
constexpr CppTokenType PT_FLOAT = CppTokenType::FLOAT;
constexpr CppTokenType PT_PROTECTED = CppTokenType::PROTECTED;
constexpr CppTokenType PT_THROW = CppTokenType::THROW;
constexpr CppTokenType PT_CONST = CppTokenType::CONST;
constexpr CppTokenType PT_FOR = CppTokenType::FOR;
constexpr CppTokenType PT_PUBLIC = CppTokenType::PUBLIC;
constexpr CppTokenType PT_UNION= CppTokenType::UNION;

constexpr CppTokenType PT_CONTINUE = CppTokenType::CONTINUE;
constexpr CppTokenType PT_GOTO = CppTokenType::GOTO;
constexpr CppTokenType PT_RETURN = CppTokenType::RETURN;
constexpr CppTokenType PT_VOID = CppTokenType::VOID;
constexpr CppTokenType PT_DO = CppTokenType::DO;
constexpr CppTokenType PT_IF = CppTokenType::IF;
constexpr CppTokenType PT_STATIC = CppTokenType::STATIC;


constexpr CppTokenType PT_WHILE = CppTokenType::WHILE;
constexpr CppTokenType PT_PLUS = CppTokenType::PLUS;
constexpr CppTokenType PT_MINUS = CppTokenType::MINUS;
constexpr CppTokenType PT_STAR = CppTokenType::STAR;

constexpr CppTokenType PT_SLASH = CppTokenType::SLASH;
constexpr CppTokenType PT_TILDA = CppTokenType::TILDA;
constexpr CppTokenType PT_DOT = CppTokenType::DOT;
constexpr CppTokenType PT_COMMA = CppTokenType::COMMA;
constexpr CppTokenType PT_SEMICOLON = CppTokenType::SEMICOLON;
constexpr CppTokenType PT_COLON = CppTokenType::COLON;
constexpr CppTokenType PT_QUOTE = CppTokenType::QUOTE;
constexpr CppTokenType PT_EQUALS = CppTokenType::EQUALS;
constexpr CppTokenType PT_NOT_EQUALS = CppTokenType::NOT_EQUALS;

constexpr CppTokenType PT_LESS_THAN = CppTokenType::LESS_THAN;
constexpr CppTokenType PT_LESS_EQUALS = CppTokenType::LESS_EQUALS;
constexpr CppTokenType PT_GREATER_EQUALS = CppTokenType::GREATER_EQUALS;
constexpr CppTokenType PT_GREATER_THAN = CppTokenType::GREATER_THAN;
constexpr CppTokenType PT_LEFT_PAREN = CppTokenType::LEFT_PAREN;
constexpr CppTokenType PT_RIGHT_PAREN = CppTokenType::RIGHT_PAREN;
constexpr CppTokenType PT_LEFT_BRACKET = CppTokenType::LEFT_BRACKET;
constexpr CppTokenType PT_RIGHT_BRACKET = CppTokenType::RIGHT_BRACKET;
constexpr CppTokenType PT_LEFT_BRACE = CppTokenType::LEFT_BRACE;
constexpr CppTokenType PT_RIGHT_BRACE = CppTokenType::RIGHT_BRACE;
constexpr CppTokenType PT_UP_ARROW = CppTokenType::UP_ARROW;
constexpr CppTokenType PT_EXCLAMATION = CppTokenType::EXCLAMATION;

constexpr CppTokenType PT_AT = CppTokenType::AT;
constexpr CppTokenType PT_PERCENT = CppTokenType::PERCENT;
constexpr CppTokenType PT_AND = CppTokenType::AND;
constexpr CppTokenType PT_LINE = CppTokenType::LINE;
constexpr CppTokenType PT_QUESTION = CppTokenType::QUESTION;
constexpr CppTokenType PT_PERIOD = CppTokenType::PERIOD;
constexpr CppTokenType PT_PLUS_PLUS = CppTokenType::PLUS_PLUS;
constexpr CppTokenType PT_MINUS_MINUS = CppTokenType::MINUS_MINUS;
constexpr CppTokenType PT_LESS_LESS = CppTokenType::LESS_LESS;
constexpr CppTokenType PT_GREATER_GREATER = CppTokenType::GREATER_GREATER;
constexpr CppTokenType PT_PLUS_EQUAL = CppTokenType::PLUS_EQUAL;
constexpr CppTokenType PT_MINUS_EQUAL = CppTokenType::MINUS_EQUAL;
constexpr CppTokenType PT_STAR_EQUAL = CppTokenType::STAR_EQUAL;

constexpr CppTokenType PT_EQUAL_EQUAL = CppTokenType::EQUAL_EQUAL;
constexpr CppTokenType PT_LINE_EQUAL = CppTokenType::LINE_EQUAL;
constexpr CppTokenType PT_PERCENT_EQUAL= CppTokenType::PERCENT_EQUAL;
constexpr CppTokenType PT_SLASH_EQUAL = CppTokenType::SLASH_EQUAL;
constexpr CppTokenType PT_AND_EQUAL = CppTokenType::AND_EQUAL;
constexpr CppTokenType PT_UP_ARROW_EQUAL = CppTokenType::UP_ARROW_EQUAL;
constexpr CppTokenType PT_EXCLAMATION_EQUAL = CppTokenType::EXCLAMATION_EQUAL;
constexpr CppTokenType PT_LESS_LESS_EQUAL = CppTokenType::LESS_LESS_EQUAL;

constexpr CppTokenType PT_GREATER_GREATER_EQUAL = CppTokenType::GREATER_GREATER_EQUAL;
constexpr CppTokenType PT_LINE_LINE = CppTokenType::LINE_LINE;
constexpr CppTokenType PT_AND_AND = CppTokenType::AND_AND;
constexpr CppTokenType PT_SLASH_SLASH = CppTokenType::SLASH_SLASH;
constexpr CppTokenType PT_SLASH_STAR = CppTokenType::SLASH_STAR;
constexpr CppTokenType PT_STAR_LASH = CppTokenType::STAR_SLASH;

constexpr CppTokenType PT_IDENTIFIER = CppTokenType::IDENTIFIER;
constexpr CppTokenType PT_INTEGER = CppTokenType::INTEGER;
constexpr CppTokenType PT_REAL = CppTokenType::REAL;
constexpr CppTokenType PT_STRING = CppTokenType::STRING;
constexpr CppTokenType PT_ERROR = CppTokenType::ERROR;
constexpr CppTokenType PT_END_OF_FILE = CppTokenType::END_OF_FILE;


class CppToken : public Token
{
public:
    static map<string, CppTokenType> RESERVED_WORDS;
    static map<string, CppTokenType> SPECIAL_SYMBOLS;
    static map<CppTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    CppToken(Source *source) throw (string);

private:
    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::frontend::Cpp

#endif /* WCI_FRONTEND_Cpp_CppTOKEN_H_ */
