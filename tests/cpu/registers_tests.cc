#include <criterion/criterion.h>
#include "../../src/cpu/Registers.hh"  // Update with your actual path
#include <iostream>

#include <bitset>

using namespace Hardwares;

void printBits(uint16_t value) {
    for (int i = 15; i >= 0; --i) {
        std::cout << ((value >> i) & 1);
    }
    std::cout << std::endl;
}
// Fixture for setting up test cases
TestSuite(RegistersTests);

Test(RegistersTests, Registers_FlagsToggle) {
    Registers regs;
    uint16_t af1 = regs.AF();
    cr_assert_eq(+af1, 0, "AF register should be initialized to 0");

    uint8_t z_before = regs.getZeroFlag();
    cr_assert_eq(+z_before, 0, "Zero Flag should be initialized to 0");
    regs.toggleZeroFlag();
    uint8_t z_after = regs.getZeroFlag();
    cr_assert_eq(+z_after, 1, "Zero Flag should be equal to 1");

    uint8_t n_before = regs.getSubFlag();
    cr_assert_eq(+n_before, 0, "Substract Flag should be initialized to 0");
    regs.toggleSubFlag();
    uint8_t n_after = regs.getSubFlag();
    cr_assert_eq(+n_after, 1, "Substract Flag should be equal to 1");

    uint8_t h_before = regs.getHalfCarryFlag();
    cr_assert_eq(+h_before, 0, "Half Carry Flag should be initialized to 0");
    regs.toggleHalfCarryFlag();
    uint8_t h_after = regs.getZeroFlag();
    cr_assert_eq(+h_after, 1, "Half Carry Flag should be equal to 1");

    uint8_t c_before = regs.getCarryFlag();
    cr_assert_eq(+c_before, 0, "Carry Flag should be initialized to 0");
    regs.toggleCarryFlag();
    uint8_t c_after = regs.getCarryFlag();
    cr_assert_eq(+c_after, 1, "Carry Flag should be equal to 1");

    uint16_t af2 = regs.AF();
    cr_assert_eq(+af2, 0b0000000011110000, "AF register should be equal to 0b0000000011110000");
}
