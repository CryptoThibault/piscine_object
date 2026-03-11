#ifndef PACKAGEREDUCTIONDISCOUNT_HPP
#define PACKAGEREDUCTIONDISCOUNT_HPP

#include "Command.hpp"

class PackageReductionDiscount : public Command {
public:
    PackageReductionDiscount(int i, int d, const std::string& c, const std::vector<Article>& a)
        : Command(i, d, c, a) {}

    float apply_discount(float total) const {
        return total > 150 ? total - 10 : total;
    }
};

#endif
