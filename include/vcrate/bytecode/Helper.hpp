#pragma once

#include <vcrate/Alias.hpp>

namespace vcrate { namespace bytecode {

using instruction_t = ui32;
constexpr ui32 instruction_size = sizeof(instruction_t);

struct Mask {
    ui32 mask;
    ui32 shift;
    /*
        0b000x000 -> mask = 0x1; shift = 0x03
        0b00xxx00 -> mask = 0x7; shift = 0x02
    */

    Mask(ui32 mask, ui32 shift);

    // set masked bits of 'base' to 'value'
    ui32 encode(ui32 value, ui32 base = 0) const;

    // get masked bits of 'value'
    ui32 decode(ui32 value) const;

    ui32 max_value() const;

    // returns a mask that is equivalent as applying the first mask, then the second
    static Mask join(Mask const& first, Mask const& second);

};

}}