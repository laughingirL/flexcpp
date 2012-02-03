#include "scanner.ih"

int Scanner::handleCharAfterBlanks()
{
    redo(1);

    if (d_inCharClass)
        return Parser::CHAR;

    if (d_inBlock)
        return ' ';

    d_inBlock = true;
    return Parser::BLOCK;
}
