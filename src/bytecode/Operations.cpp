#include <vcrate/bytecode/Operations.hpp>

#include <map>
#include <iostream>
#include <algorithm>

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

const OpDefinition& OpDefinition::get(std::string ope) {

    std::transform(std::begin(ope), std::end(ope), std::begin(ope), [] (char c) { return std::toupper(c); });

#define OP(op, cs...) { #op, Operations::op }

    static std::map<std::string, Operations> map = {
        OP(MOV),
        OP(LEA),
        OP(SWP),
        OP(CMP),
        OP(CMPU),

        OP(ADD),
        OP(ADDF),
        OP(SUB),
        OP(SUBF),
        OP(MOD),
        OP(MODF),
        OP(MUL),
        OP(MULF),
        OP(MULU),
        OP(DIV),
        OP(DIVF),
        OP(DIVU),
        OP(INC),
        OP(INCF),
        OP(DEC),
        OP(DECF),

        OP(ITU),
        OP(ITF),
        OP(UTF),
        OP(UTI),
        OP(FTI),
        OP(FTU),

        OP(AND),
        OP(OR),
        OP(NOT),
        OP(XOR),
        OP(SHL),
        OP(SHR),
        OP(RTL),
        OP(RTR),

        OP(JMP),
        OP(JMPE),
        OP(JMPNE),
        OP(JMPG),
        OP(JMPGE),
        OP(CALL),
        OP(RET),
        OP(HLT),

        OP(PUSH),
        OP(POP),
        OP(ETR),
        OP(LVE),

        OP(NEW),
        OP(DEL),

        OP(OUT),
        OP(DBG),
        OP(DBGU),
        OP(DBGF)
    };

#undef OP

    try {
        return get(map.at(ope));
    } catch(...) {
        std::cerr << "Operation unknown : " << ope << '\n';
        throw;
    }

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
        OP(ADDF, {RW, R}),
        OP(SUB, {RW, R}),
        OP(SUBF, {RW, R}),
        OP(MOD, {RW, R}),
        OP(MODF, {RW, R}),
        OP(MUL, {RW, R}),
        OP(MULF, {RW, R}),
        OP(MULU, {RW, R}),
        OP(DIV, {RW, R}),
        OP(DIVF, {RW, R}),
        OP(DIVU, {RW, R}),
        OP(INC, {RW}),
        OP(INCF, {RW}),
        OP(DEC, {RW}),
        OP(DECF, {RW}),

        OP(ITU, {RW}),
        OP(ITF, {RW}),
        OP(UTF, {RW}),
        OP(UTI, {RW}),
        OP(FTI, {RW}),
        OP(FTU, {RW}),

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
        OP(DBG, {R}),
        OP(DBGU, {R}),
        OP(DBGF, {R})
    };

#undef OP

    try {
        return def.at(ope);
    } catch(...) {
        std::cerr << "Operation unknown : " << static_cast<ui32>(ope) << '\n';
        throw;
    }
}
}}