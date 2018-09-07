/**
 * <h1>CplusplusErrorToken</h1>
 *
 * <p>Cplusplus error token.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include "CplusplusErrorToken.h"
#include "../../Token.h"
#include "../CplusplusToken.h"

namespace wci { namespace frontend { namespace Cplusplus { namespace tokens {

using namespace std;
using namespace wci::frontend::Cplusplus;

CplusplusErrorToken::CplusplusErrorToken(Source *source, CplusplusErrorCode error_code,
                                   string token_text)
    throw (string)
    : CplusplusToken(source)
{
    type = (TokenType) PT_ERROR;
    text = token_text;
    value = (int) error_code;
}

void CplusplusErrorToken::extract() throw (string)
{
    // do nothing
}

}}}}  // namespace wci::frontend::Cplusplus::tokens
