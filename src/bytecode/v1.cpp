#include <vcrate/bytecode/v1.hpp>

namespace vcrate { namespace bytecode {
namespace v1 {

Mask instruction            (0xFF00'0000);

Mask arg_12a                (0x00FF'F000);
Mask arg_12b                (0x0000'0FFF);
Mask arg_24                 (0x00FF'FFFF);

Mask arg_24_type            = Mask::join(arg_24, Mask(0x00E0'0000));
Mask arg_24_register        = Mask::join(arg_24, Mask(0x001E'0000));
Mask arg_24_signed_disp     = Mask::join(arg_24, Mask(0x0001'FFFF));
Mask arg_24_unsigned_disp   = Mask::join(arg_24, Mask(0x0000'FFFF));
Mask arg_24_sign_disp       = Mask::join(arg_24, Mask(0x0001'0000));
Mask arg_24_signed_value    = Mask::join(arg_24, Mask(0x001F'FFFF));
Mask arg_24_unsigned_value  = Mask::join(arg_24, Mask(0x000F'FFFF));
Mask arg_24_sign_value      = Mask::join(arg_24, Mask(0x0010'0000));

Mask arg_12_type            (0x0000'0E00);
Mask arg_12_register        (0x0000'01E0);
Mask arg_12_signed_disp     (0x0000'001F);
Mask arg_12_unsigned_disp   (0x0000'000F);
Mask arg_12_sign_disp       (0x0000'0010);
Mask arg_12_signed_value    (0x0000'01FF);
Mask arg_12_unsigned_value  (0x0000'00FF);
Mask arg_12_sign_value      (0x0000'0100);

Mask arg_12a_type           = Mask::join(arg_12a, arg_12_type);
Mask arg_12a_register       = Mask::join(arg_12a, arg_12_register);
Mask arg_12a_signed_disp    = Mask::join(arg_12a, arg_12_signed_disp);
Mask arg_12a_unsigned_disp  = Mask::join(arg_12a, arg_12_unsigned_disp);
Mask arg_12a_sign_disp      = Mask::join(arg_12a, arg_12_sign_disp);
Mask arg_12a_signed_value   = Mask::join(arg_12a, arg_12_signed_value);
Mask arg_12a_unsigned_value = Mask::join(arg_12a, arg_12_unsigned_value);
Mask arg_12a_sign_value     = Mask::join(arg_12a, arg_12_sign_value);

Mask arg_12b_type           = Mask::join(arg_12b, arg_12_type);
Mask arg_12b_register       = Mask::join(arg_12b, arg_12_register);
Mask arg_12b_signed_disp    = Mask::join(arg_12b, arg_12_signed_disp);
Mask arg_12b_unsigned_disp  = Mask::join(arg_12b, arg_12_unsigned_disp);
Mask arg_12b_sign_disp      = Mask::join(arg_12b, arg_12_sign_disp);
Mask arg_12b_signed_value   = Mask::join(arg_12b, arg_12_signed_value);
Mask arg_12b_unsigned_value = Mask::join(arg_12b, arg_12_unsigned_value);
Mask arg_12b_sign_value     = Mask::join(arg_12b, arg_12_sign_value);

}
}}