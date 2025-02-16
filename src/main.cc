#include "cpu/Registers.hh"
#include <iostream>

using namespace Hardwares;

int main() {
    Registers a;
    uint8_t b = a.getZeroFlag();
    std::cout << +b;
    return 0;
}