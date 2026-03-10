#include "Shovel.hpp"
#include <iostream>

Shovel::Shovel() : Tool() {}

void Shovel::use() {
   setNumberOfUses(getNumberOfUses() + 1);
   std::cout << "Use of a shovel..." << std::endl;
}
