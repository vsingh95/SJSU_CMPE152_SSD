/**
 * <h1>CplusplusError</h1>
 *
 * <p>Cplusplus translation errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include <vector>
#include <map>
#include "CplusplusError.h"

namespace wci { namespace frontend { namespace Cplusplus {

using namespace std;

bool CplusplusError::INITIALIZED = false;

map<CplusplusErrorCode, string> CplusplusError::SYNTAX_ERROR_MESSAGES;

void CplusplusError::initialize()
{
    if (INITIALIZED) return;

    vector<CplusplusErrorCode> error_codes =
    {
        CplusplusErrorCode::ALREADY_FORWARDED,
        CplusplusErrorCode::CASE_CONSTANT_REUSED,
        CplusplusErrorCode::IDENTIFIER_REDEFINED,
        CplusplusErrorCode::IDENTIFIER_UNDEFINED,
        CplusplusErrorCode::INCOMPATIBLE_ASSIGNMENT,
        CplusplusErrorCode::INCOMPATIBLE_TYPES,
        CplusplusErrorCode::INVALID_ASSIGNMENT,
        CplusplusErrorCode::INVALID_CHARACTER,
        CplusplusErrorCode::INVALID_CONSTANT,
        CplusplusErrorCode::INVALID_EXPONENT,
        CplusplusErrorCode::INVALID_EXPRESSION,
        CplusplusErrorCode::INVALID_FIELD,
        CplusplusErrorCode::INVALID_FRACTION,
        CplusplusErrorCode::INVALID_IDENTIFIER_USAGE,
        CplusplusErrorCode::INVALID_INDEX_TYPE,
        CplusplusErrorCode::INVALID_NUMBER,
        CplusplusErrorCode::INVALID_STATEMENT,
        CplusplusErrorCode::INVALID_SUBRANGE_TYPE,
        CplusplusErrorCode::INVALID_TARGET,
        CplusplusErrorCode::INVALID_TYPE,
        CplusplusErrorCode::INVALID_VAR_PARM,
        CplusplusErrorCode::MIN_GT_MAX,
        CplusplusErrorCode::MISSING_BEGIN,
        CplusplusErrorCode::MISSING_COLON,
        CplusplusErrorCode::MISSING_COLON_EQUALS,
        CplusplusErrorCode::MISSING_COMMA,
        CplusplusErrorCode::MISSING_CONSTANT,
        CplusplusErrorCode::MISSING_DO,
        CplusplusErrorCode::MISSING_DOT_DOT,
        CplusplusErrorCode::MISSING_END,
        CplusplusErrorCode::MISSING_EQUALS,
        CplusplusErrorCode::MISSING_FOR_CONTROL,
        CplusplusErrorCode::MISSING_IDENTIFIER,
        CplusplusErrorCode::MISSING_LEFT_BRACKET,
        CplusplusErrorCode::MISSING_OF,
        CplusplusErrorCode::MISSING_PERIOD,
        CplusplusErrorCode::MISSING_PROGRAM,
        CplusplusErrorCode::MISSING_RIGHT_BRACKET,
        CplusplusErrorCode::MISSING_RIGHT_PAREN,
        CplusplusErrorCode::MISSING_SEMICOLON,
        CplusplusErrorCode::MISSING_THEN,
        CplusplusErrorCode::MISSING_TO_DOWNTO,
        CplusplusErrorCode::MISSING_UNTIL,
        CplusplusErrorCode::MISSING_VARIABLE,
        CplusplusErrorCode::NOT_CONSTANT_IDENTIFIER,
        CplusplusErrorCode::NOT_RECORD_VARIABLE,
        CplusplusErrorCode::NOT_TYPE_IDENTIFIER,
        CplusplusErrorCode::RANGE_INTEGER,
        CplusplusErrorCode::RANGE_REAL,
        CplusplusErrorCode::STACK_OVERFLOW,
        CplusplusErrorCode::TOO_MANY_LEVELS,
        CplusplusErrorCode::TOO_MANY_SUBSCRIPTS,
        CplusplusErrorCode::UNEXPECTED_EOF,
        CplusplusErrorCode::UNEXPECTED_TOKEN,
        CplusplusErrorCode::UNIMPLEMENTED,
        CplusplusErrorCode::UNRECOGNIZABLE,
        CplusplusErrorCode::WRONG_NUMBER_OF_PARMS,

        // Fatal errors.
        CplusplusErrorCode::IO_ERROR,
        CplusplusErrorCode::TOO_MANY_ERRORS
    };

    vector<string> error_messages =
    {
        "Already specified in FORWARD",
        "CASE constant reused",
        "Redefined identifier",
        "Undefined identifier",
        "Incompatible assignment",
        "Incompatible types",
        "Invalid assignment statement",
        "Invalid character",
        "Invalid constant",
        "Invalid exponent",
        "Invalid expression",
        "Invalid field",
        "Invalid fraction",
        "Invalid identifier usage",
        "Invalid index type",
        "Invalid number",
        "Invalid statement",
        "Invalid subrange type",
        "Invalid assignment target",
        "Invalid type",
        "Invalid VAR parameter",
        "Min limit greater than max limit",
        "Missing BEGIN",
        "Missing :",
        "Missing :=",
        "Missing ,",
        "Missing constant",
        "Missing DO",
        "Missing ..",
        "Missing END",
        "Missing =",
        "Invalid FOR control variable",
        "Missing identifier",
        "Missing [",
        "Missing OF",
        "Missing .",
        "Missing PROGRAM",
        "Missing ]",
        "Missing )",
        "Missing ;",
        "Missing THEN",
        "Missing TO or DOWNTO",
        "Missing UNTIL",
        "Missing variable",
        "Not a constant identifier",
        "Not a record variable",
        "Not a type identifier",
        "Integer literal out of range",
        "Real literal out of range",
        "Stack overflow",
        "Nesting level too deep",
        "Too many subscripts",
        "Unexpected end of file",
        "Unexpected token",
        "Unimplemented feature",
        "Unrecognizable input",
        "Wrong number of actual parameters",

        // Fatal errors.
        "Object I/O error",
        "Too many syntax errors"
    };

    for (int i = 0; i < error_codes.size(); i++)
    {
        SYNTAX_ERROR_MESSAGES[error_codes[i]] = error_messages[i];
    }

    INITIALIZED = true;
}

}}}  // namespace wci::frontend::Cplusplus
