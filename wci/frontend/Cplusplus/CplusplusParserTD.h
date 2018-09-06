/**
 * <h1>CplusplusParserTD</h1>
 *
 * <p>The top-down Cplusplus parser.</p>
 *
 * <p>Copyright (c) 2017 by Ronald Mak</p>
 * <p>For instructional purposes only.  No warranties.</p>
 */
#ifndef WCI_FRONTEND_Cplusplus_CplusplusPARSERTD_H_
#define WCI_FRONTEND_Cplusplus_CplusplusPARSERTD_H_

#include "../Parser.h"
#include "../Scanner.h"
#include "CplusplusErrorHandler.h"

namespace wci { namespace frontend { namespace Cplusplus {

using namespace std;
using namespace wci::frontend;

class CplusplusParserTD : public Parser
{
public:
    /**
     * Constructor.
     * @param scanner the scanner to be used with this parser.
     */
    CplusplusParserTD(Scanner *scanner);

    /**
     * Constructor for subclasses.
     * @param parent the parent parser.
     */
    CplusplusParserTD(CplusplusParserTD *parent);

    /**
     * Parse a Cplusplus source program and generate the symbol table
     * and the intermediate code.
     * Implementation of wci::frontend::Parser.
     * @throw a string message if an error occurred.
     */
    void parse() throw (string);

    /**
     * Return the number of syntax errors found by the parser.
     * Implementation of wci::frontend::Parser.
     * @return the error count.
     */
    int get_error_count() const;

protected:
    static CplusplusErrorHandler error_handler;
};

}}} // namespace wci::frontend::Cplusplus


#endif /* WCI_FRONTEND_Cplusplus_CplusplusPARSERTD_H_ */
