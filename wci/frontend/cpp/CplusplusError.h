/**
 * <h1>CplusplusError</h1>
 *
 * <p>Cplusplus translation errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_Cplusplus_CplusplusERROR_H_
#define WCI_FRONTEND_Cplusplus_CplusplusERROR_H_

#include <string>
#include <map>

namespace wci { namespace frontend { namespace Cplusplus {

using namespace std;

/**
 * Cplusplus error codes.
 */
enum class CplusplusErrorCode
{
    ALREADY_FORWARDED,
    CASE_CONSTANT_REUSED,
    IDENTIFIER_REDEFINED,
    IDENTIFIER_UNDEFINED,
    INCOMPATIBLE_ASSIGNMENT,
    INCOMPATIBLE_TYPES,
    INVALID_ASSIGNMENT,
    INVALID_CHARACTER,
    INVALID_CONSTANT,
    INVALID_EXPONENT,
    INVALID_EXPRESSION,
    INVALID_FIELD,
    INVALID_FRACTION,
    INVALID_IDENTIFIER_USAGE,
    INVALID_INDEX_TYPE,
    INVALID_NUMBER,
    INVALID_STATEMENT,
    INVALID_SUBRANGE_TYPE,
    INVALID_TARGET,
    INVALID_TYPE,
    INVALID_VAR_PARM,
    MIN_GT_MAX,
    MISSING_BEGIN,
    MISSING_COLON,
    MISSING_COLON_EQUALS,
    MISSING_COMMA,
    MISSING_CONSTANT,
    MISSING_DO,
    MISSING_DOT_DOT,
    MISSING_END,
    MISSING_EQUALS,
    MISSING_FOR_CONTROL,
    MISSING_IDENTIFIER,
    MISSING_LEFT_BRACKET,
    MISSING_OF,
    MISSING_PERIOD,
    MISSING_PROGRAM,
    MISSING_RIGHT_BRACKET,
    MISSING_RIGHT_PAREN,
    MISSING_SEMICOLON,
    MISSING_THEN,
    MISSING_TO_DOWNTO,
    MISSING_UNTIL,
    MISSING_VARIABLE,
    NOT_CONSTANT_IDENTIFIER,
    NOT_RECORD_VARIABLE,
    NOT_TYPE_IDENTIFIER,
    RANGE_INTEGER,
    RANGE_REAL,
    STACK_OVERFLOW,
    TOO_MANY_LEVELS,
    TOO_MANY_SUBSCRIPTS,
    UNEXPECTED_EOF,
    UNEXPECTED_TOKEN,
    UNIMPLEMENTED,
    UNRECOGNIZABLE,
    WRONG_NUMBER_OF_PARMS,

    // Fatal errors.
    IO_ERROR,
    TOO_MANY_ERRORS
};

constexpr CplusplusErrorCode ALREADY_FORWARDED = CplusplusErrorCode::ALREADY_FORWARDED;
constexpr CplusplusErrorCode CASE_CONSTANT_REUSED = CplusplusErrorCode::CASE_CONSTANT_REUSED;
constexpr CplusplusErrorCode IDENTIFIER_REDEFINED = CplusplusErrorCode::IDENTIFIER_REDEFINED;
constexpr CplusplusErrorCode IDENTIFIER_UNDEFINED = CplusplusErrorCode::IDENTIFIER_UNDEFINED;
constexpr CplusplusErrorCode INCOMPATIBLE_ASSIGNMENT = CplusplusErrorCode::INCOMPATIBLE_ASSIGNMENT;
constexpr CplusplusErrorCode INCOMPATIBLE_TYPES = CplusplusErrorCode::INCOMPATIBLE_TYPES;
constexpr CplusplusErrorCode INVALID_ASSIGNMENT = CplusplusErrorCode::INVALID_ASSIGNMENT;
constexpr CplusplusErrorCode INVALID_CHARACTER = CplusplusErrorCode::INVALID_CHARACTER;
constexpr CplusplusErrorCode INVALID_CONSTANT = CplusplusErrorCode::INVALID_CONSTANT;
constexpr CplusplusErrorCode INVALID_EXPONENT = CplusplusErrorCode::INVALID_EXPONENT;
constexpr CplusplusErrorCode INVALID_EXPRESSION = CplusplusErrorCode::INVALID_EXPRESSION;
constexpr CplusplusErrorCode INVALID_FIELD = CplusplusErrorCode::INVALID_FIELD;
constexpr CplusplusErrorCode INVALID_FRACTION = CplusplusErrorCode::INVALID_FRACTION;
constexpr CplusplusErrorCode INVALID_IDENTIFIER_USAGE = CplusplusErrorCode::INVALID_IDENTIFIER_USAGE;
constexpr CplusplusErrorCode INVALID_INDEX_TYPE = CplusplusErrorCode::INVALID_INDEX_TYPE;
constexpr CplusplusErrorCode INVALID_NUMBER = CplusplusErrorCode::INVALID_NUMBER;
constexpr CplusplusErrorCode INVALID_STATEMENT = CplusplusErrorCode::INVALID_STATEMENT;
constexpr CplusplusErrorCode INVALID_SUBRANGE_TYPE = CplusplusErrorCode::INVALID_SUBRANGE_TYPE;
constexpr CplusplusErrorCode INVALID_TARGET = CplusplusErrorCode::INVALID_TARGET;
constexpr CplusplusErrorCode INVALID_TYPE = CplusplusErrorCode::INVALID_TYPE;
constexpr CplusplusErrorCode INVALID_VAR_PARM = CplusplusErrorCode::INVALID_VAR_PARM;
constexpr CplusplusErrorCode MIN_GT_MAX = CplusplusErrorCode::MIN_GT_MAX;
constexpr CplusplusErrorCode MISSING_BEGIN = CplusplusErrorCode::MISSING_BEGIN;
constexpr CplusplusErrorCode MISSING_COLON = CplusplusErrorCode::MISSING_COLON;
constexpr CplusplusErrorCode MISSING_COMMA = CplusplusErrorCode::MISSING_COMMA;
constexpr CplusplusErrorCode MISSING_CONSTANT = CplusplusErrorCode::MISSING_CONSTANT;
constexpr CplusplusErrorCode MISSING_DO = CplusplusErrorCode::MISSING_DO;
constexpr CplusplusErrorCode MISSING_DOT_DOT = CplusplusErrorCode::MISSING_DOT_DOT;
constexpr CplusplusErrorCode MISSING_END = CplusplusErrorCode::MISSING_END;
constexpr CplusplusErrorCode MISSING_EQUALS = CplusplusErrorCode::MISSING_EQUALS;
constexpr CplusplusErrorCode MISSING_COLON_EQUALS = CplusplusErrorCode::MISSING_COLON_EQUALS;
constexpr CplusplusErrorCode MISSING_FOR_CONTROL = CplusplusErrorCode::MISSING_FOR_CONTROL;
constexpr CplusplusErrorCode MISSING_IDENTIFIER = CplusplusErrorCode::MISSING_IDENTIFIER;
constexpr CplusplusErrorCode MISSING_LEFT_BRACKET = CplusplusErrorCode::MISSING_LEFT_BRACKET;
constexpr CplusplusErrorCode MISSING_OF = CplusplusErrorCode::MISSING_OF;
constexpr CplusplusErrorCode MISSING_PERIOD = CplusplusErrorCode::MISSING_PERIOD;
constexpr CplusplusErrorCode MISSING_PROGRAM = CplusplusErrorCode::MISSING_PROGRAM;
constexpr CplusplusErrorCode MISSING_RIGHT_BRACKET = CplusplusErrorCode::MISSING_RIGHT_BRACKET;
constexpr CplusplusErrorCode MISSING_RIGHT_PAREN = CplusplusErrorCode::MISSING_RIGHT_PAREN;
constexpr CplusplusErrorCode MISSING_SEMICOLON = CplusplusErrorCode::MISSING_SEMICOLON;
constexpr CplusplusErrorCode MISSING_THEN = CplusplusErrorCode::MISSING_THEN;
constexpr CplusplusErrorCode MISSING_TO_DOWNTO = CplusplusErrorCode::MISSING_TO_DOWNTO;
constexpr CplusplusErrorCode MISSING_UNTIL = CplusplusErrorCode::MISSING_UNTIL;
constexpr CplusplusErrorCode MISSING_VARIABLE = CplusplusErrorCode::MISSING_VARIABLE;
constexpr CplusplusErrorCode NOT_CONSTANT_IDENTIFIER = CplusplusErrorCode::NOT_CONSTANT_IDENTIFIER;
constexpr CplusplusErrorCode NOT_RECORD_VARIABLE = CplusplusErrorCode::NOT_RECORD_VARIABLE;
constexpr CplusplusErrorCode NOT_TYPE_IDENTIFIER = CplusplusErrorCode::NOT_TYPE_IDENTIFIER;
constexpr CplusplusErrorCode RANGE_INTEGER = CplusplusErrorCode::RANGE_INTEGER;
constexpr CplusplusErrorCode RANGE_REAL = CplusplusErrorCode::RANGE_REAL;
constexpr CplusplusErrorCode STACK_OVERFLOW = CplusplusErrorCode::STACK_OVERFLOW;
constexpr CplusplusErrorCode TOO_MANY_LEVELS = CplusplusErrorCode::TOO_MANY_LEVELS;
constexpr CplusplusErrorCode TOO_MANY_SUBSCRIPTS = CplusplusErrorCode::TOO_MANY_SUBSCRIPTS;
constexpr CplusplusErrorCode UNEXPECTED_EOF = CplusplusErrorCode::UNEXPECTED_EOF;
constexpr CplusplusErrorCode UNEXPECTED_TOKEN = CplusplusErrorCode::UNEXPECTED_TOKEN;
constexpr CplusplusErrorCode UNIMPLEMENTED = CplusplusErrorCode::UNIMPLEMENTED;
constexpr CplusplusErrorCode UNRECOGNIZABLE = CplusplusErrorCode::UNRECOGNIZABLE;
constexpr CplusplusErrorCode WRONG_NUMBER_OF_PARMS = CplusplusErrorCode::WRONG_NUMBER_OF_PARMS;

constexpr CplusplusErrorCode IO_ERROR = CplusplusErrorCode::IO_ERROR;
constexpr CplusplusErrorCode TOO_MANY_ERRORS = CplusplusErrorCode::TOO_MANY_ERRORS;

class CplusplusError
{
public:
    static map<CplusplusErrorCode, string> SYNTAX_ERROR_MESSAGES;

    /**
     * Initialize the static map.
     */
    static void initialize();

private:
    static bool INITIALIZED;
};

}}}  // namespace wci::frontend::Cplusplus

#endif /* WCI_FRONTEND_Cplusplus_CplusplusERROR_H_ */
