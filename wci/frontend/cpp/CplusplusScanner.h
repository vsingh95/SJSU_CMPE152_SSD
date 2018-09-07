/**
 * <h1>CplusplusScanner</h1>
 *
 * <p>The Cplusplus scanner.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_Cplusplus_CplusplusSCANNER_H_
#define WCI_FRONTEND_Cplusplus_CplusplusSCANNER_H_

#include "../Scanner.h"
#include "../Source.h"
#include "../Token.h"

namespace wci { namespace frontend { namespace Cplusplus {

using namespace std;
using namespace wci::frontend;

class CplusplusScanner : public Scanner
{
public:
    /**
     * Constructor
     * @param source the source to be used with this scanner.
     */
    CplusplusScanner(Source *source);

protected:
    /**
     * Extract and return the next Cplusplus token from the source.
     * @return the next token.
     * @throw a string message if an error occurred.
     */
    Token *extract_token() throw (string);

private:
    /**
     * Skip whitespace characters by consuming them.  A comment is whitespace.
     * @throw a string message if an error occurred.
     */
    void skip_white_space() throw (string);
};

}}} // namespace wci::frontend::Cplusplus

#endif /* WCI_FRONTEND_Cplusplus_CplusplusSCANNER_H_ */
