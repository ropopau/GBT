#pragma once
#include <cstdint>


namespace Hardwares {
    union Register {
        private:
        struct {
            uint8_t low;
            uint8_t high;
        };
        uint16_t val;
        
        public:
        Register();

        inline void setVal(uint16_t val);
        inline void setLow(uint8_t low);
        inline void setHigh(uint8_t high);

        inline uint16_t getVal();
        inline uint8_t getLow();
        inline uint8_t getHigh();

    };
}