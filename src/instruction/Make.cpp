#include <vcrate/instruction/Make.hpp>

namespace vcrate { namespace instruction {

using bytecode::Operations;

Instruction make_add(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::ADD, lhs, rhs); }
Instruction make_addf(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::ADDF, lhs, rhs); }
Instruction make_sub(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::SUB, lhs, rhs); }
Instruction make_subf(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::SUBF, lhs, rhs); }
Instruction make_mod(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::MOD, lhs, rhs); }
Instruction make_modf(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::MODF, lhs, rhs); }
Instruction make_mul(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::MUL, lhs, rhs); }
Instruction make_mulu(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::MULU, lhs, rhs); }
Instruction make_mulf(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::MULF, lhs, rhs); }
Instruction make_div(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::DIV, lhs, rhs); }
Instruction make_divu(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::DIVU, lhs, rhs); }
Instruction make_divf(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::DIVF, lhs, rhs); }
Instruction make_mov(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::MOV, lhs, rhs); }
Instruction make_lea(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::LEA, lhs, rhs); }
Instruction make_pop(Argument const& lhs) { return Instruction(Operations::POP, lhs); }
Instruction make_push(Argument const& lhs) { return Instruction(Operations::PUSH, lhs); }
Instruction make_jmp(Argument const& lhs) { return Instruction(Operations::JMP, lhs); }
Instruction make_jmpe(Argument const& lhs) { return Instruction(Operations::JMPE, lhs); }
Instruction make_jmpne(Argument const& lhs) { return Instruction(Operations::JMPNE, lhs); }
Instruction make_jmpg(Argument const& lhs) { return Instruction(Operations::JMPG, lhs); }
Instruction make_jmpge(Argument const& lhs) { return Instruction(Operations::JMPGE, lhs); }
Instruction make_and(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::AND, lhs, rhs); }
Instruction make_or(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::OR, lhs, rhs); }
Instruction make_xor(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::XOR, lhs, rhs); }
Instruction make_not(Argument const& lhs) { return Instruction(Operations::NOT, lhs); }
Instruction make_shl(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::SHL, lhs, rhs); }
Instruction make_rtl(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::RTL, lhs, rhs); }
Instruction make_shr(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::SHR, lhs, rhs); }
Instruction make_rtr(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::RTR, lhs, rhs); }
Instruction make_swp(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::SWP, lhs, rhs); }
Instruction make_cmp(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::CMP, lhs, rhs); }
Instruction make_cpmu(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::CMPU, lhs, rhs); }
Instruction make_inc(Argument const& lhs) { return Instruction(Operations::INC, lhs); }
Instruction make_incf(Argument const& lhs) { return Instruction(Operations::INCF, lhs); }
Instruction make_dec(Argument const& lhs) { return Instruction(Operations::DEC, lhs); }
Instruction make_decf(Argument const& lhs) { return Instruction(Operations::DECF, lhs); }
Instruction make_new(Argument const& lhs, Argument const& rhs) { return Instruction(Operations::NEW, lhs, rhs); }
Instruction make_del(Argument const& lhs) { return Instruction(Operations::DEL, lhs); }
Instruction make_call(Argument const& lhs) { return Instruction(Operations::CALL, lhs); }
Instruction make_ret() { return Instruction(Operations::RET); }
Instruction make_etr() { return Instruction(Operations::ETR); }
Instruction make_lve() { return Instruction(Operations::LVE); }
Instruction make_hlt() { return Instruction(Operations::HLT); }
Instruction make_out(Argument const& lhs) { return Instruction(Operations::OUT, lhs); }
Instruction make_dbg(Argument const& lhs) { return Instruction(Operations::DBG, lhs); }
Instruction make_dbgu(Argument const& lhs) { return Instruction(Operations::DBGU, lhs); }
Instruction make_dbgf(Argument const& lhs) { return Instruction(Operations::DBGF, lhs); }

}}