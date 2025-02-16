#include "Registers.hh"

#include "Registers.hh"

namespace Hardwares {

    // Flag registers toggling
    void Registers::toggleZeroFlag() {
        this->registers.FA_struct.F ^= (1 << 7);
    }   

    void Registers::toggleSubFlag() {
        this->registers.FA_struct.F ^= (1 << 6);
    }   

    void Registers::toggleHalfCarryFlag() {
        this->registers.FA_struct.F ^= (1 << 5);
    }   

    void Registers::toggleCarryFlag() {
        this->registers.FA_struct.F ^= (1 << 4);
    }   

    uint8_t Registers::getZeroFlag() {
        return (this->registers.FA_struct.F >> 7) & 1;
    }

    uint8_t Registers::getSubFlag() {
        return (this->registers.FA_struct.F >> 6) & 1;
    }

    uint8_t Registers::getHalfCarryFlag() {
        return (this->registers.FA_struct.F >> 5) & 1;
    }

    uint8_t Registers::getCarryFlag() {
        return (this->registers.FA_struct.F >> 4) & 1;
    }

    uint16_t Registers::AF() {
        return this->registers.AF;
    }
}
