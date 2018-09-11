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
    // Reserved words 
    AUTO, DOUBLE, INT, STRUCT, 
    BREAK, ELSE, LONG, SWITCH, 
    CASE, ENUM, NAMESPACE, TEMPLATE, 
    CHAR, EXTERN, OPERATOR, THIS, 
    CLASS, FLOAT, PROTECTED, THROW, 
    CONST, FOR, PUBLIC, UNION, 
    CONTINUE, GOTO, RETURN, VOID, 
    DO, IF, STATIC, WHILE, 

    // Special Symbols 
    TILDE, NOT, AT, PERCENT, CARET, AND, STAR, MIUNS, PLUS, EQUALS, 
    LINE, SLASH, COLON, SEMICOLON, QUESTION, LESS_THAN, GREATER_THAN, DOT, COMMA, 
    SINGLE_QUOTE, QUOTE, LEFT_PAREN, RIGHT_PAREN, LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE, 
    PLUS_PLUS, MINUS_MINUS, LEFT_SHIFT, RIGHT_SHIFT, LESS_EQUALS, GREATER_EQUALS, PLUS_EQUALS, MINUS_EQUALS, STAR_EQUALS, SLASH_EQUALS, 
    EQUAL_EQUALS, LINE_EQUALS, PERCENT_EQUALS, AND_EQUALS, CARET_EQUALS, NOT_EQUALS, SHIFT_LEFT_EQUALS, SHIFT_RIGHT_EQUALS, LINE_LINE, AND_AND,  
    SLASH_SLASH, SLASH_STAR, STAR_SLASH, 

    IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE,
};

constexpr CppTokenType CT_AUTO = CppTokenType::AUTO;
constexpr CppTokenType CT_DOUBLE = CppTokenType::DOUBLE;
constexpr CppTokenType CT_INT = CppTokenType::INT;
constexpr CppTokenType CT_STRUCT = CppTokenType::STRUCT;

constexpr CppTokenType CT_BREAK = CppTokenType::BREAK;
constexpr CppTokenType CT_ELSE = CppTokenType::ELSE;
constexpr CppTokenType CT_LONG = CppTokenType::LONG;
constexpr CppTokenType CT_SWITCH = CppTokenType::SWITCH;

constexpr CppTokenType CT_CASE = CppTokenType::CASE;
constexpr CppTokenType CT_ENUM = CppTokenType::ENUM;
constexpr CppTokenType CT_NAMESPACE = CppTokenType::NAMESPACE;
constexpr CppTokenType CT_TEMPLATE = CppTokenType::TEMPLATE;

constexpr CppTokenType CT_CHAR = CppTokenType::CHAR;
constexpr CppTokenType CT_EXTERN = CppTokenType::EXTERN;
constexpr CppTokenType CT_OPERATOR = CppTokenType::OPERATOR;
constexpr CppTokenType CT_THIS = CppTokenType::THIS;

constexpr CppTokenType CT_CLASS = CppTokenType::CLASS;
constexpr CppTokenType CT_FLOAT = CppTokenType::FLOAT;
constexpr CppTokenType CT_PROTECTED = CppTokenType::PROTECTED;
constexpr CppTokenType CT_THROW = CppTokenType::THROW;

constexpr CppTokenType CT_CONST = CppTokenType::CONST;
constexpr CppTokenType CT_FOR = CppTokenType::FOR;
constexpr CppTokenType CT_PUBLIC = CppTokenType::PUBLIC;
constexpr CppTokenType CT_UNION = CppTokenType::UNION;

constexpr CppTokenType CT_CONTINUE = CppTokenType::CONTINUE;
constexpr CppTokenType CT_GOTO = CppTokenType::GOTO;
constexpr CppTokenType CT_RETURN = CppTokenType::RETURN;
constexpr CppTokenType CT_VOID = CppTokenType::VOID;

constexpr CppTokenType CT_DO = CppTokenType::DO;
constexpr CppTokenType CT_IF = CppTokenType::IF;
constexpr CppTokenType CT_STATIC = CppTokenType::STATIC;
constexpr CppTokenType CT_WHILE = CppTokenType::WHILE;

constexpr CppTokenType CT_TILDE = CppTokenType::TILDE;
constexpr CppTokenType CT_NOT = CppTokenType::NOT;
constexpr CppTokenType CT_AT = CppTokenType::AT;
constexpr CppTokenType CT_PERCENT = CppTokenType::PERCENT;
constexpr CppTokenType CT_CARET = CppTokenType::CARET;
constexpr CppTokenType CT_AND = CppTokenType::AND;
constexpr CppTokenType CT_STAR = CppTokenType::STAR;
constexpr CppTokenType CT_MIUNS = CppTokenType::MIUNS;
constexpr CppTokenType CT_PLUS = CppTokenType::PLUS;
constexpr CppTokenType CT_EQUALS = CppTokenType::EQUALS;

constexpr CppTokenType CT_LINE = CppTokenType::LINE;
constexpr CppTokenType CT_SLASH = CppTokenType::SLASH;
constexpr CppTokenType CT_COLON = CppTokenType::COLON;
constexpr CppTokenType CT_SEMICOLON = CppTokenType::SEMICOLON;
constexpr CppTokenType CT_QUESTION = CppTokenType::QUESTION;
constexpr CppTokenType CT_LESS_THAN = CppTokenType::LESS_THAN;
constexpr CppTokenType CT_GREATER_THAN = CppTokenType::GREATER_THAN;
constexpr CppTokenType CT_DOT = CppTokenType::DOT;
constexpr CppTokenType CT_COMMA = CppTokenType::COMMA;

constexpr CppTokenType CT_SINGLE_QUOTE = CppTokenType::SINGLE_QUOTE;
constexpr CppTokenType CT_QUOTE = CppTokenType::QUOTE;
constexpr CppTokenType CT_LEFT_PAREN = CppTokenType::LEFT_PAREN;
constexpr CppTokenType CT_RIGHT_PAREN = CppTokenType::RIGHT_PAREN;
constexpr CppTokenType CT_LEFT_BRACKET = CppTokenType::LEFT_BRACKET;
constexpr CppTokenType CT_RIGHT_BRACKET = CppTokenType::RIGHT_BRACKET;
constexpr CppTokenType CT_LEFT_BRACE = CppTokenType::LEFT_BRACE;
constexpr CppTokenType CT_RIGHT_BRACE = CppTokenType::RIGHT_BRACE;

constexpr CppTokenType CT_PLUS_PLUS = CppTokenType::PLUS_PLUS;
constexpr CppTokenType CT_MINUS_MINUS = CppTokenType::MINUS_MINUS;
constexpr CppTokenType CT_LEFT_SHIFT = CppTokenType::LEFT_SHIFT;
constexpr CppTokenType CT_RIGHT_SHIFT = CppTokenType::RIGHT_SHIFT;
constexpr CppTokenType CT_LESS_EQUALS = CppTokenType::LESS_EQUALS;
constexpr CppTokenType CT_GREATER_EQUALS = CppTokenType::GREATER_EQUALS;
constexpr CppTokenType CT_PLUS_EQUALS = CppTokenType::PLUS_EQUALS;
constexpr CppTokenType CT_MINUS_EQUALS = CppTokenType::MINUS_EQUALS;
constexpr CppTokenType CT_STAR_EQUALS = CppTokenType::STAR_EQUALS;
constexpr CppTokenType CT_SLASH_EQUALS = CppTokenType::SLASH_EQUALS;

constexpr CppTokenType CT_EQUAL_EQUALS = CppTokenType::EQUAL_EQUALS;
constexpr CppTokenType CT_LINE_EQUALS = CppTokenType::LINE_EQUALS;
constexpr CppTokenType CT_PERCENT_EQUALS = CppTokenType::PERCENT_EQUALS;
constexpr CppTokenType CT_AND_EQUALS = CppTokenType::AND_EQUALS;
constexpr CppTokenType CT_CARET_EQUALS = CppTokenType::CARET_EQUALS;
constexpr CppTokenType CT_NOT_EQUALS = CppTokenType::NOT_EQUALS;
constexpr CppTokenType CT_SHIFT_LEFT_EQUALS = CppTokenType::SHIFT_LEFT_EQUALS;
constexpr CppTokenType CT_SHIFT_RIGHT_EQUALS = CppTokenType::SHIFT_RIGHT_EQUALS;
constexpr CppTokenType CT_LINE_LINE = CppTokenType::LINE_LINE;
constexpr CppTokenType CT_AND_AND = CppTokenType::AND_AND;

constexpr CppTokenType CT_SLASH_SLASH = CppTokenType::SLASH_SLASH;
constexpr CppTokenType CT_SLASH_STAR = CppTokenType::SLASH_STAR;
constexpr CppTokenType CT_STAR_SLASH = CppTokenType::STAR_SLASH;

constexpr CppTokenType CT_IDENTIFIER = CppTokenType::IDENTIFIER;
constexpr CppTokenType CT_INTEGER = CppTokenType::INTEGER;
constexpr CppTokenType CT_REAL = CppTokenType::REAL;
constexpr CppTokenType CT_STRING = CppTokenType::STRING;
constexpr CppTokenType CT_ERROR = CppTokenType::ERROR;
constexpr CppTokenType CT_END_OF_FILE = CppTokenType::END_OF_FILE;

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
