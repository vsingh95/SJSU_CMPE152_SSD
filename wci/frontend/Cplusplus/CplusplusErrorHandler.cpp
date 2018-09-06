/**
 * <h1>CplusplusErrorHandler</h1>
 *
 * <p>Error handler Cplusplus syntax errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "CplusplusErrorHandler.h"
#include "../Token.h"
#include "../Parser.h"
#include "CplusplusError.h"
#include "../../message/Message.h"

namespace wci { namespace frontend { namespace Cplusplus {

using namespace std;
using namespace wci::frontend;

const int CplusplusErrorHandler::MAX_ERRORS = 25;
int CplusplusErrorHandler::error_count = 0;

int CplusplusErrorHandler::get_error_count() const { return error_count; }

void CplusplusErrorHandler::flag(Token *token, CplusplusErrorCode error_code,
                              Parser *parser)
{
    // Notify the parser's listeners.
    string error_message = CplusplusError::SYNTAX_ERROR_MESSAGES[error_code];
    Message message(SYNTAX_ERROR,
                    LINE_NUMBER, to_string(token->get_line_number()),
                    POSITION, to_string(token->get_position()),
                    TOKEN_TEXT, token->get_text(),
                    ERROR_MESSAGE, error_message);
    parser->send_message(message);

    if (++error_count > MAX_ERRORS)
    {
        abort_translation(TOO_MANY_ERRORS, parser);
    }
}

void CplusplusErrorHandler::abort_translation(CplusplusErrorCode error_code,
                                           Parser *parser)
{
    // Notify the parser's listeners and then abort.
    string error_message = "FATAL ERROR: " +
                           CplusplusError::SYNTAX_ERROR_MESSAGES[error_code];
    Message message(SYNTAX_ERROR,
                    LINE_NUMBER, "0",
                    POSITION, "0",
                    TOKEN_TEXT, "",
                    ERROR_MESSAGE, error_message);
    parser->send_message(message);
    exit(-2);
}

}}}  // namespace wci::frontend::Cplusplus
