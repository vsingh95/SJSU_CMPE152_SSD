/*
 * CppCharToken.cpp
 *
 *  Created on: Sep 10, 2018
 *      Author: hmmm
 */

#include <string>
#include "CppCharToken.h"
#include "../CppError.h"

namespace wci { namespace frontend { namespace Cpp { namespace tokens {

using namespace std;
using namespace wci::frontend;
using namespace wci::frontend::Cpp;

CppCharToken::CppCharToken(Source *source) throw (string)
    : CppToken(source)
{
    extract();
}

void CppCharToken::extract() throw (string)
{
    string value_str = "";

    char current_ch = next_char();  // consume initial quote
    text += "\'";

    // Get string characters.
    do
    {
        if ((current_ch != '\'') && (current_ch != Source::END_OF_FILE) && (current_ch != '\\')) {
            text += current_ch;
            value_str  += current_ch;
            current_ch = next_char();  // consume character
        }

        if (current_ch == '\\') {
            text  += current_ch;
            current_ch = next_char();
            if(current_ch == 't')
                value_str += '\t';
            else if(current_ch == 'n')
                value_str += '\n';
            else
                value_str += current_ch;
            text  += current_ch;
            current_ch = next_char();
        }
    } while((current_ch != '\'') && (current_ch != Source::END_OF_FILE));


    if (current_ch == '\'')
    {
        next_char();  // consume final quote
        text += '\'';
        type = (TokenType) PT_CHARACTER;
        value = value_str;
    }
    else
    {
        type = (TokenType) PT_ERROR;
        value = (int) UNEXPECTED_EOF;
    }
}

}}}}  // namespace wci::frontend::Cpp::tokens
