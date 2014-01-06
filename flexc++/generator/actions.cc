#include "generator.ih"

void Generator::actions(ostream &out) const
{
    key(out);

    size_t idx = 0;

    for (auto &rule: ranger(d_rules.ruleBegin(), d_rules.ruleEnd()))
    {
        if (not rule.isLopRule())
            ruleAction(rule.block(), out, idx);
    }
}
