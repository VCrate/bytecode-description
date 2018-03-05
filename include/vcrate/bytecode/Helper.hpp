#pragma once

#include <vcrate/Alias.hpp>

namespace vcrate { namespace bytecode {

using instruction_t = ui32;
constexpr ui32 instruction_size = sizeof(instruction_t);

class Mask {
public:
    Mask(ui32 mask);

    void set_mask(ui32 mask);
    
    ui32 get_left_mask() const;
    ui32 get_mask() const;
    ui32 get_shift() const;

    // set masked bits of 'base' to 'value'
    ui32 encode(ui32 value, ui32 base = 0) const;

    // get masked bits of 'value'
    ui32 decode(ui32 value) const;

    ui32 max_value() const;

    // returns a mask that is equivalent as applying the first mask, then the second
    static Mask join(Mask const& first, Mask const& second);

private:

    static ui32 get_leading_zero(ui32 mask);

    ui32 mask;
    ui32 shift;

};

}}