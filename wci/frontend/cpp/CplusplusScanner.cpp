/**
 * <h1>CplusplusScanner</h1>
 *
 * <p>The Cplusplus scanner.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <iostream>
#include "CplusplusScanner.h"
#include "CplusplusToken.h"
#include "CplusplusError.h"
#include "../Source.h"
#include "tokens/CplusplusWordToken.h"
#include "tokens/CplusplusNumberToken.h"
#include "tokens/CplusplusStringToken.h"
#include "tokens/CplusplusSpecialSymbolToken.h"
#include "tokens/CplusplusErrorToken.h"

namespace wci { namespace frontend { namespace Cplusplus {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cplusplus::tokens;

CplusplusScanner::CplusplusScanner(Source *source) : Scanner(source)
{
}

Token *CplusplusScanner::extract_token() throw (string)
{
    skip_white_space();

    Token *token;
    char current_ch = current_char();
    string string_ch = " ";

    string_ch[0] = current_ch;

    // Construct the next token.  The current character determines the
    // token type.
    if (current_ch == Source::END_OF_FILE)
    {
        token = nullptr;
    }
    else if (isalpha(current_ch))
    {
        token = new CplusplusWordToken(source);
    }
    else if (isdigit(current_ch))
    {
        token = new CplusplusNumberToken(source);
    }
    else if (current_ch == '\'')
    {
        token = new CplusplusStringToken(source);
    }
    else if (CplusplusToken::SPECIAL_SYMBOLS.find(string_ch)
                != CplusplusToken::SPECIAL_SYMBOLS.end())
    {
        token = new CplusplusSpecialSymbolToken(source);
    }
    else
    {
        token = new CplusplusErrorToken(source, INVALID_CHARACTER, string_ch);
        next_char();  // consume character
    }

    return token;
}

void CplusplusScanner::skip_white_space() throw (string)
{
    char current_ch = current_char();

    while (isspace(current_ch) || (current_ch == '{')) {

        // Start of a comment?
        if (current_ch == '{')
        {
            do
            {
                current_ch = next_char();  // consume comment characters
            } while ((current_ch != '}') &&
                     (current_ch != Source::END_OF_FILE));

            // Found closing '}'?
            if (current_ch == '}')
            {
                current_ch = next_char();  // consume the '}'
            }
        }

        // Not a comment.
        else current_ch = next_char();  // consume whitespace character
    }
}

}}} // namespace wci::frontend::Cplusplus
