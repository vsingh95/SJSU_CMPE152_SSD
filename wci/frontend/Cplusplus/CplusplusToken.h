/**
 * <h1>CplusplusToken</h1>
 *
 * <p>Base class for Cplusplus token classes.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */

#ifndef WCI_FRONTEND_Cplusplus_CplusplusTOKEN_H_
#define WCI_FRONTEND_Cplusplus_CplusplusTOKEN_H_

#include <string>
#include <map>
#include "../Token.h"
#include "../Source.h"

namespace wci { namespace frontend { namespace Cplusplus {

using namespace std;
using namespace wci::frontend;

/**
 * Cplusplus token types.
 */
enum class CplusplusTokenType
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

constexpr CplusplusTokenType PT_AND = CplusplusTokenType::AND;
constexpr CplusplusTokenType PT_ARRAY = CplusplusTokenType::ARRAY;
constexpr CplusplusTokenType PT_BEGIN = CplusplusTokenType::BEGIN;
constexpr CplusplusTokenType PT_CASE = CplusplusTokenType::CASE;
constexpr CplusplusTokenType PT_CONST = CplusplusTokenType::CONST;
constexpr CplusplusTokenType PT_DIV = CplusplusTokenType::DIV;
constexpr CplusplusTokenType PT_DO = CplusplusTokenType::DO;
constexpr CplusplusTokenType PT_DOWNTO = CplusplusTokenType::DOWNTO;

constexpr CplusplusTokenType PT_ELSE = CplusplusTokenType::ELSE;
constexpr CplusplusTokenType PT_END = CplusplusTokenType::END;
constexpr CplusplusTokenType PT_FILE = CplusplusTokenType::FILE;
constexpr CplusplusTokenType PT_FOR = CplusplusTokenType::FOR;
constexpr CplusplusTokenType PT_FUNCTION = CplusplusTokenType::FUNCTION;
constexpr CplusplusTokenType PT_GOTO = CplusplusTokenType::GOTO;
constexpr CplusplusTokenType PT_IF = CplusplusTokenType::IF;
constexpr CplusplusTokenType PT_IN = CplusplusTokenType::IN;

constexpr CplusplusTokenType PT_LABEL = CplusplusTokenType::LABEL;
constexpr CplusplusTokenType PT_MOD = CplusplusTokenType::MOD;
constexpr CplusplusTokenType PT_NIL = CplusplusTokenType::NIL;
constexpr CplusplusTokenType PT_NOT = CplusplusTokenType::NOT;
constexpr CplusplusTokenType PT_OF = CplusplusTokenType::OF;
constexpr CplusplusTokenType PT_OR = CplusplusTokenType::OR;
constexpr CplusplusTokenType PT_PACKED = CplusplusTokenType::PACKED;
constexpr CplusplusTokenType PT_PROCEDURE = CplusplusTokenType::PROCEDURE;

constexpr CplusplusTokenType PT_PROGRAM = CplusplusTokenType::PROGRAM;
constexpr CplusplusTokenType PT_RECORD = CplusplusTokenType::RECORD;
constexpr CplusplusTokenType PT_REPEAT = CplusplusTokenType::REPEAT;
constexpr CplusplusTokenType PT_SET = CplusplusTokenType::SET;
constexpr CplusplusTokenType PT_THEN = CplusplusTokenType::THEN;
constexpr CplusplusTokenType PT_TO = CplusplusTokenType::TO;
constexpr CplusplusTokenType PT_TYPE = CplusplusTokenType::TYPE;

constexpr CplusplusTokenType PT_UNTIL = CplusplusTokenType::UNTIL;
constexpr CplusplusTokenType PT_VAR = CplusplusTokenType::VAR;
constexpr CplusplusTokenType PT_WHILE = CplusplusTokenType::WHILE;
constexpr CplusplusTokenType PT_WITH = CplusplusTokenType::WITH;

constexpr CplusplusTokenType PT_PLUS = CplusplusTokenType::PLUS;
constexpr CplusplusTokenType PT_MINUS = CplusplusTokenType::MINUS;
constexpr CplusplusTokenType PT_STAR = CplusplusTokenType::STAR;
constexpr CplusplusTokenType PT_SLASH = CplusplusTokenType::SLASH;
constexpr CplusplusTokenType PT_COLON_EQUALS = CplusplusTokenType::COLON_EQUALS;
constexpr CplusplusTokenType PT_DOT = CplusplusTokenType::DOT;
constexpr CplusplusTokenType PT_COMMA = CplusplusTokenType::COMMA;
constexpr CplusplusTokenType PT_SEMICOLON = CplusplusTokenType::SEMICOLON;
constexpr CplusplusTokenType PT_COLON = CplusplusTokenType::COLON;
constexpr CplusplusTokenType PT_QUOTE = CplusplusTokenType::QUOTE;
constexpr CplusplusTokenType PT_EQUALS = CplusplusTokenType::EQUALS;
constexpr CplusplusTokenType PT_NOT_EQUALS = CplusplusTokenType::NOT_EQUALS;

constexpr CplusplusTokenType PT_LESS_THAN = CplusplusTokenType::LESS_THAN;
constexpr CplusplusTokenType PT_LESS_EQUALS = CplusplusTokenType::LESS_EQUALS;
constexpr CplusplusTokenType PT_GREATER_EQUALS = CplusplusTokenType::GREATER_EQUALS;
constexpr CplusplusTokenType PT_GREATER_THAN = CplusplusTokenType::GREATER_THAN;
constexpr CplusplusTokenType PT_LEFT_PAREN = CplusplusTokenType::LEFT_PAREN;
constexpr CplusplusTokenType PT_RIGHT_PAREN = CplusplusTokenType::RIGHT_PAREN;
constexpr CplusplusTokenType PT_LEFT_BRACKET = CplusplusTokenType::LEFT_BRACKET;
constexpr CplusplusTokenType PT_RIGHT_BRACKET = CplusplusTokenType::RIGHT_BRACKET;
constexpr CplusplusTokenType PT_LEFT_BRACE = CplusplusTokenType::LEFT_BRACE;
constexpr CplusplusTokenType PT_RIGHT_BRACE = CplusplusTokenType::RIGHT_BRACE;
constexpr CplusplusTokenType PT_UP_ARROW = CplusplusTokenType::UP_ARROW;
constexpr CplusplusTokenType PT_DOT_DOT = CplusplusTokenType::DOT_DOT;

constexpr CplusplusTokenType PT_IDENTIFIER = CplusplusTokenType::IDENTIFIER;
constexpr CplusplusTokenType PT_INTEGER = CplusplusTokenType::INTEGER;
constexpr CplusplusTokenType PT_REAL = CplusplusTokenType::REAL;
constexpr CplusplusTokenType PT_STRING = CplusplusTokenType::STRING;
constexpr CplusplusTokenType PT_ERROR = CplusplusTokenType::ERROR;
constexpr CplusplusTokenType PT_END_OF_FILE = CplusplusTokenType::END_OF_FILE;

class CplusplusToken : public Token
{
public:
    static map<string, CplusplusTokenType> RESERVED_WORDS;
    static map<string, CplusplusTokenType> SPECIAL_SYMBOLS;
    static map<CplusplusTokenType, string> SPECIAL_SYMBOL_NAMES;

protected:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    CplusplusToken(Source *source) throw (string);

private:
    static bool INITIALIZED;

    /**
     * Initialize the static maps.
     */
    static void initialize();
};

}}}  // namespace wci::frontend::Cplusplus

#endif /* WCI_FRONTEND_Cplusplus_CplusplusTOKEN_H_ */
