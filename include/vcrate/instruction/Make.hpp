#pragma once

#include <vcrate/bytecode/Operations.hpp>
#include <vcrate/instruction/Instruction.hpp>
#include <vcrate/instruction/Argument.hpp>

namespace vcrate { namespace instruction {

Instruction make_add(Argument const& lhs, Argument const& rhs);
Instruction make_addf(Argument const& lhs, Argument const& rhs);
Instruction make_sub(Argument const& lhs, Argument const& rhs);
Instruction make_subf(Argument const& lhs, Argument const& rhs);
Instruction make_mod(Argument const& lhs, Argument const& rhs);
Instruction make_modf(Argument const& lhs, Argument const& rhs);
Instruction make_mul(Argument const& lhs, Argument const& rhs);
Instruction make_mulu(Argument const& lhs, Argument const& rhs);
Instruction make_mulf(Argument const& lhs, Argument const& rhs);
Instruction make_div(Argument const& lhs, Argument const& rhs);
Instruction make_divu(Argument const& lhs, Argument const& rhs);
Instruction make_divf(Argument const& lhs, Argument const& rhs);
Instruction make_mov(Argument const& lhs, Argument const& rhs);
Instruction make_lea(Argument const& lhs, Argument const& rhs);
Instruction make_pop(Argument const& lhs);
Instruction make_push(Argument const& lhs);
Instruction make_jmp(Argument const& lhs);
Instruction make_jmpe(Argument const& lhs);
Instruction make_jmpne(Argument const& lhs);
Instruction make_jmpg(Argument const& lhs);
Instruction make_jmpge(Argument const& lhs);
Instruction make_and(Argument const& lhs, Argument const& rhs);
Instruction make_or(Argument const& lhs, Argument const& rhs);
Instruction make_xor(Argument const& lhs, Argument const& rhs);
Instruction make_not(Argument const& lhs);
Instruction make_shl(Argument const& lhs, Argument const& rhs);
Instruction make_rtl(Argument const& lhs, Argument const& rhs);
Instruction make_shr(Argument const& lhs, Argument const& rhs);
Instruction make_rtr(Argument const& lhs, Argument const& rhs);
Instruction make_swp(Argument const& lhs, Argument const& rhs);
Instruction make_cmp(Argument const& lhs, Argument const& rhs);
Instruction make_cpmu(Argument const& lhs, Argument const& rhs);
Instruction make_inc(Argument const& lhs);
Instruction make_incf(Argument const& lhs);
Instruction make_dec(Argument const& lhs);
Instruction make_decf(Argument const& lhs);
Instruction make_new(Argument const& lhs, Argument const& rhs);
Instruction make_del(Argument const& lhs);
Instruction make_call(Argument const& lhs);
Instruction make_ret();
Instruction make_etr();
Instruction make_lve();
Instruction make_hlt();
Instruction make_out(Argument const& lhs);
Instruction make_dbg(Argument const& lhs);
Instruction make_dbgu(Argument const& lhs);
Instruction make_dbgf(Argument const& lhs);

}}