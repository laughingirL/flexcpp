#include "dfarow.ih"

void DFARow::tabulateAccepts(Table &table) const
{
    ostringstream out;
    for 
    (
        auto iter = d_LARule.begin(), end = d_LARule.end(); 
            iter != end;
                ++iter
    )
    {
        if (iter->accept() >= 0)
            out << iter->rule() << ':' << 
                   (iter->inc() ? "++" : "") << iter->accept();
    }
    table << out.str();
}
