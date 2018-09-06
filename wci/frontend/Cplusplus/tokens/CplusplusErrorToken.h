/**
 * <h1>CplusplusErrorToken</h1>
 *
 * <p>Cplusplus error token.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_Cplusplus_TOKENS_CplusplusERRORTOKEN_H_
#define WCI_FRONTEND_Cplusplus_TOKENS_CplusplusERRORTOKEN_H_

#include <string>
#include "../CplusplusError.h"
#include "../CplusplusToken.h"

namespace wci { namespace frontend { namespace Cplusplus { namespace tokens {

using namespace std;
using namespace wci::frontend::Cplusplus;

class CplusplusErrorToken : public CplusplusToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch subsequent characters.
     * @param errorCode the error code.
     * @param tokenText the text of the erroneous token.
     * @throw a string message if an error occurred.
     */
    CplusplusErrorToken(Source *source, CplusplusErrorCode error_code,
                     string token_text)
        throw (string);

protected:
    /**
     * Do nothing.  Do not consume any source characters.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::Cplusplus::tokens

#endif /* WCI_FRONTEND_Cplusplus_TOKENS_CplusplusERRORTOKEN_H_ */
