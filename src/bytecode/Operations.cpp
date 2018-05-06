#include <vcrate/bytecode/Operations.hpp>

#include <map>
#include <iostream>

namespace vcrate { namespace bytecode {

OpDefinition::OpDefinition(std::string const& name, Operations ope, std::vector<ui8> const& args_constraints)
    : name(name), ope(ope), args_constraints(args_constraints) {}

ui32 OpDefinition::arg_count() const {
    return args_constraints.size();
}

ui8 OpDefinition::value() const {
    return static_cast<ui8>(ope);
}

bool OpDefinition::should_be_readable(ui32 arg) const {
    return args_constraints[arg] & ArgConstraint::Readable;
}

bool OpDefinition::should_be_writable(ui32 arg) const {
    return args_constraints[arg] & ArgConstraint::Writable;
}

bool OpDefinition::should_be_addressable(ui32 arg) const {
    return args_constraints[arg] & ArgConstraint::Adressable;
}

const OpDefinition& OpDefinition::get(Operations ope) {

#define OP(op, cs...) { Operations::op, OpDefinition(#op, Operations::op, cs) }

    constexpr ui8 R = ArgConstraint::Readable;
    constexpr ui8 W = ArgConstraint::Writable;
    constexpr ui8 A = ArgConstraint::Adressable;
    constexpr ui8 RW = R | W;

    static std::map<Operations, OpDefinition> def = {
        OP(MOV, {W, R}),
        OP(LEA, {W, A}),
        OP(SWP, {RW, RW}),
        OP(CMP, {R, R}),
        OP(CMPU, {R, R}),

        OP(ADD, {RW, R}),
        OP(SUB, {RW, R}),
        OP(MOD, {RW, R}),
        OP(MUL, {RW, R}),
        OP(MULU, {RW, R}),
        OP(DIV, {RW, R}),
        OP(DIVU, {RW, R}),
        OP(INC, {RW}),
        OP(DEC, {RW}),

        OP(AND, {RW, R}),
        OP(OR, {RW, R}),
        OP(NOT, {RW}),
        OP(XOR, {RW, R}),
        OP(SHL, {RW, R}),
        OP(SHR, {RW, R}),
        OP(RTL, {RW, R}),
        OP(RTR, {RW, R}),

        OP(JMP, {R}),
        OP(JMPE, {R}),
        OP(JMPNE, {R}),
        OP(JMPG, {R}),
        OP(JMPGE, {R}),
        OP(CALL, {R}),
        OP(RET, {}),
        OP(HLT, {}),

        OP(PUSH, {R}),
        OP(POP, {W}),
        OP(ETR, {}),
        OP(LVE, {}),

        OP(NEW, {W, R}),
        OP(DEL, {R}),

        OP(OUT, {R}),
        OP(DBG, {R})
    };

#undef OP

    try {
        return def.at(ope);
    } catch(...) {
        std::cout << "Operation unknown : " << static_cast<ui32>(ope) << '\n';
        throw;
    }
}
}}