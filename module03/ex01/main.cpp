#include "Command.hpp"
#include "ThuesdayDiscount.hpp"
#include "PackageReductionDiscount.hpp"
#include <iostream>

int main() {
    std::vector<Article> arts;
    Article laptop("Laptop", 1, 120.0f);
    Article mouse("Mouse", 2, 25.0f);
    arts.push_back(laptop);
    arts.push_back(mouse);

    Command base(1, 2, "Alice", arts);
    std::cout << "Base price: " << base.get_total_price() << std::endl;
    ThuesdayDiscount td(1, 2, "Alice", arts);
    std::cout << "Thesday Discount: " << td.get_total_price() << std::endl;
    PackageReductionDiscount prd(1, 2, "Alice", arts);
    std::cout << "Package Reduction Discount: " << prd.get_total_price() << std::endl;
    return 0;
}
