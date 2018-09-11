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

constexpr CppTokenType CT_AND = CppTokenType::AND;
constexpr CppTokenType CT_ARRAY = CppTokenType::ARRAY;
constexpr CppTokenType CT_BEGIN = CppTokenType::BEGIN;
constexpr CppTokenType CT_CASE = CppTokenType::CASE;
constexpr CppTokenType CT_CONST = CppTokenType::CONST;
constexpr CppTokenType CT_DIV = CppTokenType::DIV;
constexpr CppTokenType CT_DO = CppTokenType::DO;
constexpr CppTokenType CT_DOWNTO = CppTokenType::DOWNTO;

constexpr CppTokenType CT_ELSE = CppTokenType::ELSE;
constexpr CppTokenType CT_END = CppTokenType::END;
constexpr CppTokenType CT_FILE = CppTokenType::FILE;
constexpr CppTokenType CT_FOR = CppTokenType::FOR;
constexpr CppTokenType CT_FUNCTION = CppTokenType::FUNCTION;
constexpr CppTokenType CT_GOTO = CppTokenType::GOTO;
constexpr CppTokenType CT_IF = CppTokenType::IF;
constexpr CppTokenType CT_IN = CppTokenType::IN;

constexpr CppTokenType CT_LABEL = CppTokenType::LABEL;
constexpr CppTokenType CT_MOD = CppTokenType::MOD;
constexpr CppTokenType CT_NIL = CppTokenType::NIL;
constexpr CppTokenType CT_NOT = CppTokenType::NOT;
constexpr CppTokenType CT_OF = CppTokenType::OF;
constexpr CppTokenType CT_OR = CppTokenType::OR;
constexpr CppTokenType CT_PACKED = CppTokenType::PACKED;
constexpr CppTokenType CT_PROCEDURE = CppTokenType::PROCEDURE;

constexpr CppTokenType CT_PROGRAM = CppTokenType::PROGRAM;
constexpr CppTokenType CT_RECORD = CppTokenType::RECORD;
constexpr CppTokenType CT_REPEAT = CppTokenType::REPEAT;
constexpr CppTokenType CT_SET = CppTokenType::SET;
constexpr CppTokenType CT_THEN = CppTokenType::THEN;
constexpr CppTokenType CT_TO = CppTokenType::TO;
constexpr CppTokenType CT_TYPE = CppTokenType::TYPE;

constexpr CppTokenType CT_UNTIL = CppTokenType::UNTIL;
constexpr CppTokenType CT_VAR = CppTokenType::VAR;
constexpr CppTokenType CT_WHILE = CppTokenType::WHILE;
constexpr CppTokenType CT_WITH = CppTokenType::WITH;

constexpr CppTokenType CT_PLUS = CppTokenType::PLUS;
constexpr CppTokenType CT_MINUS = CppTokenType::MINUS;
constexpr CppTokenType CT_STAR = CppTokenType::STAR;
constexpr CppTokenType CT_SLASH = CppTokenType::SLASH;
constexpr CppTokenType CT_COLON_EQUALS = CppTokenType::COLON_EQUALS;
constexpr CppTokenType CT_DOT = CppTokenType::DOT;
constexpr CppTokenType CT_COMMA = CppTokenType::COMMA;
constexpr CppTokenType CT_SEMICOLON = CppTokenType::SEMICOLON;
constexpr CppTokenType CT_COLON = CppTokenType::COLON;
constexpr CppTokenType CT_QUOTE = CppTokenType::QUOTE;
constexpr CppTokenType CT_EQUALS = CppTokenType::EQUALS;
constexpr CppTokenType CT_NOT_EQUALS = CppTokenType::NOT_EQUALS;

constexpr CppTokenType CT_LESS_THAN = CppTokenType::LESS_THAN;
constexpr CppTokenType CT_LESS_EQUALS = CppTokenType::LESS_EQUALS;
constexpr CppTokenType CT_GREATER_EQUALS = CppTokenType::GREATER_EQUALS;
constexpr CppTokenType CT_GREATER_THAN = CppTokenType::GREATER_THAN;
constexpr CppTokenType CT_LEFT_PAREN = CppTokenType::LEFT_PAREN;
constexpr CppTokenType CT_RIGHT_PAREN = CppTokenType::RIGHT_PAREN;
constexpr CppTokenType CT_LEFT_BRACKET = CppTokenType::LEFT_BRACKET;
constexpr CppTokenType CT_RIGHT_BRACKET = CppTokenType::RIGHT_BRACKET;
constexpr CppTokenType CT_LEFT_BRACE = CppTokenType::LEFT_BRACE;
constexpr CppTokenType CT_RIGHT_BRACE = CppTokenType::RIGHT_BRACE;
constexpr CppTokenType CT_UP_ARROW = CppTokenType::UP_ARROW;
constexpr CppTokenType CT_DOT_DOT = CppTokenType::DOT_DOT;

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
