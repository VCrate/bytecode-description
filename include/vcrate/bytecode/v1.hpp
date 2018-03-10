#pragma once

#include <vcrate/bytecode/Helper.hpp>

namespace vcrate { namespace bytecode {
namespace v1 {

constexpr Mask instruction            (0xFF00'0000);

constexpr Mask arg_12a                (0x00FF'F000);
constexpr Mask arg_12b                (0x0000'0FFF);
constexpr Mask arg_24                 (0x00FF'FFFF);

constexpr Mask arg_24_type            = Mask::join(arg_24, Mask(0x00E0'0000));
constexpr Mask arg_24_register        = Mask::join(arg_24, Mask(0x001E'0000));
constexpr Mask arg_24_signed_disp     = Mask::join(arg_24, Mask(0x0001'FFFF));
constexpr Mask arg_24_unsigned_disp   = Mask::join(arg_24, Mask(0x0000'FFFF));
constexpr Mask arg_24_sign_disp       = Mask::join(arg_24, Mask(0x0001'0000));
constexpr Mask arg_24_signed_value    = Mask::join(arg_24, Mask(0x001F'FFFF));
constexpr Mask arg_24_unsigned_value  = Mask::join(arg_24, Mask(0x000F'FFFF));
constexpr Mask arg_24_sign_value      = Mask::join(arg_24, Mask(0x0010'0000));

constexpr Mask arg_12_type            (0x0000'0E00);
constexpr Mask arg_12_register        (0x0000'01E0);
constexpr Mask arg_12_signed_disp     (0x0000'001F);
constexpr Mask arg_12_unsigned_disp   (0x0000'000F);
constexpr Mask arg_12_sign_disp       (0x0000'0010);
constexpr Mask arg_12_signed_value    (0x0000'01FF);
constexpr Mask arg_12_unsigned_value  (0x0000'00FF);
constexpr Mask arg_12_sign_value      (0x0000'0100);

constexpr Mask arg_12a_type           = Mask::join(arg_12a, arg_12_type);
constexpr Mask arg_12a_register       = Mask::join(arg_12a, arg_12_register);
constexpr Mask arg_12a_signed_disp    = Mask::join(arg_12a, arg_12_signed_disp);
constexpr Mask arg_12a_unsigned_disp  = Mask::join(arg_12a, arg_12_unsigned_disp);
constexpr Mask arg_12a_sign_disp      = Mask::join(arg_12a, arg_12_sign_disp);
constexpr Mask arg_12a_signed_value   = Mask::join(arg_12a, arg_12_signed_value);
constexpr Mask arg_12a_unsigned_value = Mask::join(arg_12a, arg_12_unsigned_value);
constexpr Mask arg_12a_sign_value     = Mask::join(arg_12a, arg_12_sign_value);

constexpr Mask arg_12b_type           = Mask::join(arg_12b, arg_12_type);
constexpr Mask arg_12b_register       = Mask::join(arg_12b, arg_12_register);
constexpr Mask arg_12b_signed_disp    = Mask::join(arg_12b, arg_12_signed_disp);
constexpr Mask arg_12b_unsigned_disp  = Mask::join(arg_12b, arg_12_unsigned_disp);
constexpr Mask arg_12b_sign_disp      = Mask::join(arg_12b, arg_12_sign_disp);
constexpr Mask arg_12b_signed_value   = Mask::join(arg_12b, arg_12_signed_value);
constexpr Mask arg_12b_unsigned_value = Mask::join(arg_12b, arg_12_unsigned_value);
constexpr Mask arg_12b_sign_value     = Mask::join(arg_12b, arg_12_sign_value);

constexpr ui32 register_a = 0x0;
constexpr ui32 register_b = 0x1;
constexpr ui32 register_c = 0x2;
constexpr ui32 register_d = 0x3;
constexpr ui32 register_e = 0x4;
constexpr ui32 register_f = 0x5;
constexpr ui32 register_g = 0x6;
constexpr ui32 register_h = 0x7;
constexpr ui32 register_i = 0x8;
constexpr ui32 register_j = 0x9;
constexpr ui32 register_k = 0xA;
constexpr ui32 register_l = 0xB;
constexpr ui32 register_pc = 0xC;
constexpr ui32 register_fg = 0xD;
constexpr ui32 register_bp = 0xE;
constexpr ui32 register_sp = 0xF;

constexpr ui32 arg_type_register = 0x0;
constexpr ui32 arg_type_defer_register = 0x1;
constexpr ui32 arg_type_defer_register_disp = 0x2;
constexpr ui32 arg_type_defer_register_disp_next = 0x3;
constexpr ui32 arg_type_address = 0x4;
constexpr ui32 arg_type_address_next = 0x5;
constexpr ui32 arg_type_value = 0x6;
constexpr ui32 arg_type_value_next = 0x7;

constexpr ui32 flag_zero = 1 << 0;
constexpr ui32 flag_greater = 1 << 1;

}
}}