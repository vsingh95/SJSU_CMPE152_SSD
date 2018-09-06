/**
 * <h1>CplusplusSpecialSymbolToken</h1>
 *
 * <p> Cplusplus special symbol tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "CplusplusSpecialSymbolToken.h"
#include "../CplusplusError.h"

namespace wci { namespace frontend { namespace Cplusplus { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cplusplus;

CplusplusSpecialSymbolToken::CplusplusSpecialSymbolToken(Source *source) throw (string)
    : CplusplusToken(source)
{
    extract();
}

void CplusplusSpecialSymbolToken::extract() throw (string)
{
    char current_ch = current_char();
    bool good_symbol = true;

    text = current_ch;

    switch (current_ch)
    {
        // Single-character special symbols.
        case '+':  case '-':  case '*':  case '/':  case ',':
        case ';':  case '\'': case '=':  case '(':  case ')':
        case '[':  case ']':  case '{':  case '}':  case '^':
        {
            next_char();  // consume character
            break;
        }

        // : or :=
        case ':':
        {
            current_ch = next_char();  // consume ':';

            if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }

            break;
        }

        // < or <= or <>
        case '<':
        {
            current_ch = next_char();  // consume '<';

            if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }
            else if (current_ch == '>')
            {
                text += current_ch;
                next_char();  // consume '>'
            }

            break;
        }

        // > or >=
        case '>':
        {
            current_ch = next_char();  // consume '>';

            if (current_ch == '=')
            {
                text += current_ch;
                next_char();  // consume '='
            }

            break;
        }

        // . or ..
        case '.':
        {
            current_ch = next_char();  // consume '.';

            if (current_ch == '.')
            {
                text += current_ch;
                next_char();  // consume '.'
            }

            break;
        }

        default:
        {
            next_char();  // consume bad character
            type = (TokenType) (PT_ERROR);
            value = (int) INVALID_CHARACTER;
            good_symbol = false;
        }
    }

    // Set the type if it wasn't an error.
    if (good_symbol) {
        type = (TokenType) (CplusplusToken::SPECIAL_SYMBOLS[text]);
    }
}

}}}}  // namespace wci::frontend::Cplusplus::tokens