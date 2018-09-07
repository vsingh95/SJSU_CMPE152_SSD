/**
 * <h1>CplusplusWordToken</h1>
 *
 * <p> Cplusplus word tokens (identifiers and reserved words).</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <iostream>
#include <string>
#include <map>
#include "CplusplusWordToken.h"
#include "../CplusplusError.h"

namespace wci { namespace frontend { namespace Cplusplus { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cplusplus;

CplusplusWordToken::CplusplusWordToken(Source *source) throw (string)
    : CplusplusToken(source)
{
    extract();
}

/**
 * Extract a Cplusplus word token from the source.
 * @throws Exception if an error occurred.
 */
void CplusplusWordToken::extract() throw (string)
{
    char current_ch = current_char();

    // Get the word characters (letter or digit). The scanner has
    // already determined that the first character is a letter.
    while (isalnum(current_ch))
    {
        text += current_ch;
        current_ch = next_char();  // consume character
    }

    // Is it a reserved word or an identifier?
    string upper_case = to_upper(text);
    if (CplusplusToken::RESERVED_WORDS.find(upper_case)
            != CplusplusToken::RESERVED_WORDS.end())
    {
        // Reserved word.
        type = (TokenType) CplusplusToken::RESERVED_WORDS[upper_case];
        value = upper_case;
    }
    else
    {
        // Identifier.
        type = (TokenType) PT_IDENTIFIER;
    }
}

}}}}  // namespace wci::frontend::Cplusplus::tokens
