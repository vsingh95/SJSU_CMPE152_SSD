/**
 * <h1>CppStringToken</h1>
 *
 * <p> Cpp string tokens.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#include <string>
#include "CppStringToken.h"
#include "../CppError.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cpp;

CppStringToken::CppStringToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}

void CppStringToken::extract() throw (string)
{
    string value_str = "";

    char current_ch = next_char();  // consume initial quote
    text += "\"";

    // Get string characters.
    do
    {
        // Replace any whitespace character with a blank.
        if (isspace(current_ch)) current_ch = ' ';

        if ((current_ch != '\"') && (current_ch != Source::END_OF_FILE))
        {
            text += current_ch;
            if(current_ch != '\\')
                value_str  += current_ch;
            if(current_ch == '\\')
            {
                current_ch = next_char();
                text += current_ch;
                if(current_ch == 't')
                    value_str += '\t';
                if(current_ch == 'n')
                    value_str += '\n';
                if(current_ch == '"')
                    value_str += '\"';
                current_ch = next_char();
            }
            else
                current_ch = next_char();  // consume character
        }


    } while ((current_ch != '\"') && (current_ch != Source::END_OF_FILE));


    if (current_ch == '\'')
    {
        next_char();  // consume final quote
        text += '\"';
        type = (TokenType) PT_STRING;
        value = value_str;
    }
    else
    {
        type = (TokenType) PT_ERROR;
        value = (int) UNEXPECTED_EOF;
    }
}

}}}}  // namespace wci::frontend::Cpp::tokens
