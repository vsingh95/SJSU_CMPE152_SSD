/**
 * <h1>CplusplusErrorHandler</h1>
 *
 * <p>Error handler Cplusplus syntax errors.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_Cplusplus_CplusplusERRORHANDLER_H_
#define WCI_FRONTEND_Cplusplus_CplusplusERRORHANDLER_H_

#include "../Token.h"
#include "../Parser.h"
#include "CplusplusError.h"

namespace wci { namespace frontend { namespace Cplusplus {

using namespace std;
using namespace wci::frontend;

class CplusplusErrorHandler
{
public:
    /**
     * Getter.
     * @return the syntax error count.
     */
    int get_error_count() const;

    /**
     * Flag an error in the source line.
     * @param token the bad token.
     * @param errorCode the error code.
     * @param parser the parser.
     * @return the flagger string.
     */
    void flag(Token *token, CplusplusErrorCode error_code, Parser *parser);

    /**
     * Abort the translation.
     * @param errorCode the error code.
     * @param parser the parser.
     */
    void abort_translation(CplusplusErrorCode error_code, Parser *parser);

private:
    static int error_count;
    static const int MAX_ERRORS;
};

}}}  // namespace wci::frontend::Cplusplus

#endif /* WCI_FRONTEND_Cplusplus_CplusplusERRORHANDLER_H_ */
