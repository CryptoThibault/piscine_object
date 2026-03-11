#ifndef THUESDAYDISCOUNT_HPP
#define THUESDAYDISCOUNT_HPP

#include "Command.hpp"

class ThuesdayDiscount : public Command {
public:
    ThuesdayDiscount(int i, int d, const std::string& c, const std::vector<Article>& a)
        : Command(i, d, c, a) {}

    float apply_discount(float total) const {
        return date == 2 ? total * 0.9f : total;
    }
};

#endif
