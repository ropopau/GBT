#pragma once
#include <cstdint>


namespace Hardwares {

    // Registers defined in one structure because I want contiguous addresses in the memory
    typedef union {
        struct { uint8_t F, A; } FA_struct;
        uint16_t AF;
        
        struct { uint8_t C, B; } CB_struct;
        uint16_t BC;

        struct { uint8_t E, D; } ED_struct;
        uint16_t DE;

        struct { uint8_t L, H; } LH_struct;
        uint16_t HL;
        
        uint16_t SP;  // Stack pointer register
        uint16_t PC;  // Program counter register
    } CPU_Registers;


    class Registers {
        private:
        CPU_Registers registers;

        public:

        void toggleZeroFlag(); // Z
        void toggleSubFlag(); // N
        void toggleHalfCarryFlag(); // H
        void toggleCarryFlag(); // C

        uint8_t getZeroFlag();
        uint8_t getSubFlag();
        uint8_t getHalfCarryFlag();
        uint8_t getCarryFlag();


        uint16_t AF();
        uint16_t BC();
        uint16_t DE();
        uint16_t HL();
        uint16_t SP();
        uint16_t PC();

        uint8_t A();
        uint8_t F();
        uint8_t B();
        uint8_t C();
        uint8_t D();
        uint8_t E();
        uint8_t H();
        uint8_t L();
        
    };
}