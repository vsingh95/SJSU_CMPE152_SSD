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
    AND, ARRAY, BEGIN, CASE, CONST, DIV, DO, DOWNTO, ELSE, END,
    FILE, FOR, FUNCTION, GOTO, IF, IN, LABEL, MOD, NIL, NOT,
    OF, OR, PACKED, PROCEDURE, PROGRAM, RECORD, REPEAT, SET,
    THEN, TO, TYPE, UNTIL, VAR, WHILE, WITH,

    // Special symbols.
    PLUS, MINUS, STAR, SLASH, COLON_EQUALS,
    DOT, COMMA, SEMICOLON, COLON, QUOTE,
    EQUALS, NOT_EQUALS, LESS_THAN, LESS_EQUALS,
    GREATER_EQUALS, GREATER_THAN, LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACKET, RIGHT_BRACKET, LEFT_BRACE, RIGHT_BRACE,
    UP_ARROW, DOT_DOT,

    IDENTIFIER, INTEGER, REAL, STRING,
    ERROR, END_OF_FILE,
};

constexpr CppTokenType PT_AND = CppTokenType::AND;
constexpr CppTokenType PT_ARRAY = CppTokenType::ARRAY;
constexpr CppTokenType PT_BEGIN = CppTokenType::BEGIN;
constexpr CppTokenType PT_CASE = CppTokenType::CASE;
constexpr CppTokenType PT_CONST = CppTokenType::CONST;
constexpr CppTokenType PT_DIV = CppTokenType::DIV;
constexpr CppTokenType PT_DO = CppTokenType::DO;
constexpr CppTokenType PT_DOWNTO = CppTokenType::DOWNTO;

constexpr CppTokenType PT_ELSE = CppTokenType::ELSE;
constexpr CppTokenType PT_END = CppTokenType::END;
constexpr CppTokenType PT_FILE = CppTokenType::FILE;
constexpr CppTokenType PT_FOR = CppTokenType::FOR;
constexpr CppTokenType PT_FUNCTION = CppTokenType::FUNCTION;
constexpr CppTokenType PT_GOTO = CppTokenType::GOTO;
constexpr CppTokenType PT_IF = CppTokenType::IF;
constexpr CppTokenType PT_IN = CppTokenType::IN;

constexpr CppTokenType PT_LABEL = CppTokenType::LABEL;
constexpr CppTokenType PT_MOD = CppTokenType::MOD;
constexpr CppTokenType PT_NIL = CppTokenType::NIL;
constexpr CppTokenType PT_NOT = CppTokenType::NOT;
constexpr CppTokenType PT_OF = CppTokenType::OF;
constexpr CppTokenType PT_OR = CppTokenType::OR;
constexpr CppTokenType PT_PACKED = CppTokenType::PACKED;
constexpr CppTokenType PT_PROCEDURE = CppTokenType::PROCEDURE;

constexpr CppTokenType PT_PROGRAM = CppTokenType::PROGRAM;
constexpr CppTokenType PT_RECORD = CppTokenType::RECORD;
constexpr CppTokenType PT_REPEAT = CppTokenType::REPEAT;
constexpr CppTokenType PT_SET = CppTokenType::SET;
constexpr CppTokenType PT_THEN = CppTokenType::THEN;
constexpr CppTokenType PT_TO = CppTokenType::TO;
constexpr CppTokenType PT_TYPE = CppTokenType::TYPE;

constexpr CppTokenType PT_UNTIL = CppTokenType::UNTIL;
constexpr CppTokenType PT_VAR = CppTokenType::VAR;
constexpr CppTokenType PT_WHILE = CppTokenType::WHILE;
constexpr CppTokenType PT_WITH = CppTokenType::WITH;

constexpr CppTokenType PT_PLUS = CppTokenType::PLUS;
constexpr CppTokenType PT_MINUS = CppTokenType::MINUS;
constexpr CppTokenType PT_STAR = CppTokenType::STAR;
constexpr CppTokenType PT_SLASH = CppTokenType::SLASH;
constexpr CppTokenType PT_COLON_EQUALS = CppTokenType::COLON_EQUALS;
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
constexpr CppTokenType PT_DOT_DOT = CppTokenType::DOT_DOT;

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
