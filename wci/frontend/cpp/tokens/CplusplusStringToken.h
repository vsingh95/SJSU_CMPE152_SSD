/**
 * <h1>CplusplusStringToken</h1>
 *
 * <p> Cplusplus string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_Cplusplus_TOKENS_CplusplusSTRINGTOKEN_H_
#define WCI_FRONTEND_Cplusplus_TOKENS_CplusplusSTRINGTOKEN_H_

#include <string>
#include "../CplusplusToken.h"

namespace wci { namespace frontend { namespace Cplusplus { namespace tokens {

using namespace std;
using namespace wci::frontend::Cplusplus;

class CplusplusStringToken : public CplusplusToken
{
public:
    /**
     * Constructor.
     * @param source the source from where to fetch the token's characters.
     * @throw a string message if an error occurred.
     */
    CplusplusStringToken(Source *source) throw (string);

protected:
    /**
     * Extract a Cplusplus string token from the source.
     * Override of wci::frontend::Token.
     * @throw a string message if an error occurred.
     */
    void extract() throw (string);
};

}}}}  // namespace wci::frontend::Cplusplus::tokens

#endif /* WCI_FRONTEND_Cplusplus_TOKENS_CplusplusSTRINGTOKEN_H_ */
