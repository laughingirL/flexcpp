#include "scannerbase.ih"

// The queue may be empty or not, but we just read a char. that cannot be
// processed at this time, since the LA info comes first. So return d_char to
// the queue's front, followed by (in reverse order) the LA characters.
// then reduce the match-size and d_length by the LA length.

void ScannerBase::saveLookahead()
{
    retain(d_LAsize);

    d_bol = false;                      // prevent BOL from being returned
    next();                             // get the next character to
                                        // handle by callExecute. 
}
