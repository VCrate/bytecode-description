#pragma once

#include <vcrate/Alias.hpp>
#include <vector>
#include <string>

namespace vcrate { namespace bytecode {

enum class Operations : ui8 {
    ADD,  // Add (RRW)
    SUB,  // Subtract (RRW)
    MOD,  // Modulo (RRW)
    MUL,  // Multiply (RRW)
    MULU, // Multiply unsigned (RRW)
    DIV,  // Divide (RRW)
    DIVU, // Divide unsigned (RRW)
    MOV,  // Move (RW)
    LEA,  // Load effective address
    POP,  // Pop from stack (W)
    PUSH, // Push to stack (R)
    JMP,  // Jump to (R)
    JMPE, // Jump to _ if zero flag (R)
    JMPNE, // Jump to _ if !zero flag (R)
    JMPG, // Jump to _ if greater flag (R)
    JMPGE, // Jump to _ if greater and zero flag (R)
    AND,  // And (RRW)
    OR,   // Or (RRW)
    XOR,  // Xor (RRW)
    NOT,  // Not (RW)
    SHL,  // Shift left (RRW)
    RTL,  // Rotate left (RRW)
    SHR,  // Shift right (RRW)
    RTR,  // Rotate right (RRW)
    SWP,  // Swap (WW)
    CMP,  // set zero/greater flags
    CMPU, // Comapre unsigned
    INC,  // Increment (RW)
    DEC,  // Decrement (RW)

    NEW,  // New (RW)
    DEL,  // Delete (R)

    CALL, // Call (R)
    RET,  // Return
    ETR,  // Enter
    LVE,  // Leave

    HLT,  // Halt the program

    OUT,
    DBG
};

struct ArgConstraint {
    static constexpr ui8 Readable = 0x01;
    static constexpr ui8 Writable = 0x02;
    static constexpr ui8 Adressable = 0x04;
};

class OpDefinition {
public:

    OpDefinition(std::string const& name, Operations ope, std::vector<ui8> const& args_constraints = {});

    std::string name;
    Operations ope;
    std::vector<ui8> args_constraints;

    ui32 arg_count() const;
    ui8 value() const;
    bool should_be_writable(ui32 arg) const;
    bool should_be_addressable(ui32 arg) const;
    bool should_be_readable(ui32 arg) const;

    static const OpDefinition& get(Operations ope); 

};

}}