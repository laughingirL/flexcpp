#include "dfa.ih"

void DFA::transitAccCount(DFARow::MapValue const &rangeToRow, size_t fmRow, 
                          size_t fmCount, DFA &dfa)
{
    int toRow = rangeToRow.second;

    if (toRow == -1)        // no transition
        return;

//cout << " transiting from row " << fmRow << " to " << toRow << '\n';

    std::vector<AccCount> &accCounts = dfa.d_row[toRow].accCounts();
    auto endIter = accCounts.end();
    auto iter = find(accCounts.begin(), endIter, dfa.d_rule);

    if (iter == endIter)
        return;

//cout << "Next accCount...\n";

    determineAccCount(*iter, toRow, fmRow, fmCount, dfa);
}
