#include "Hammer.hpp"
#include <iostream>

Hammer::Hammer() : Tool() {}

void Hammer::use() {
   setNumberOfUses(getNumberOfUses() + 1);
   std::cout << "Use of a hammer..." << std::endl;
}
