#pragma once

#include "Register.hh"

namespace Hardwares {

    inline void Register::setHigh(uint8_t high) {
        this->high = high;
    }   

    inline void Register::setLow(uint8_t low) {
        this->low = low;
    }   

    inline void Register::setVal(uint16_t val) {
        this->val = val;
    }   

    inline uint8_t Register::getHigh() {
        return this->high;
    }   

    inline uint8_t Register::getLow() {
        return this->low;
    }   

    inline uint16_t Register::getVal() {
        return this->val;
    }   

}
