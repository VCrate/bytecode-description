#pragma once

#include <vcrate/Alias.hpp>

#include <cmath>

namespace vcrate { namespace bytecode {

using instruction_t = ui32;
constexpr ui32 instruction_size = sizeof(instruction_t);

class Mask {
public:
    constexpr Mask(ui32 mask) :
        shift(get_leading_zero(mask)),
        mask(mask >> shift) {}

    constexpr void set_mask(ui32 mask)  {
        this->shift = get_leading_zero(mask);
        this->mask = mask >> shift;
    }
    
    constexpr ui32 get_shifted_mask() const    { return mask << shift; }
    constexpr ui32 get_mask() const         { return mask; }
    constexpr ui32 get_shift() const        { return shift; }

    // set masked bits of 'base' to 'value'
    constexpr ui32 encode(ui32 value, ui32 base = 0) const {
        base &= ~get_mask(); // reset base
        return base | (value & mask) << shift;
    }

    // get masked bits of 'value'
    constexpr ui32 decode(ui32 value) const {
        return (value >> shift) & mask;
    }

    constexpr ui32 max_value() const { return mask; }

    // returns a mask that is equivalent as applying the first mask, then the second
    static constexpr Mask join(Mask const& first, Mask const& second) {
        return Mask(first.get_shifted_mask() & (second.get_shifted_mask() << first.get_shift()));
    }

private:

    static constexpr ui32 get_leading_zero(ui32 mask) {
        return __builtin_ctz(mask);
    }

    ui32 shift;
    ui32 mask;

};

constexpr ui32 encode_signed_value(Mask const& unsigned_part, Mask const& sign, i32 value, ui32 base = 0x00) {
    base = unsigned_part.encode(std::abs(value), base);
    base = sign.encode(value < 0, base);
    return base;
}

constexpr i32 decode_signed_value(Mask const& unsigned_part, Mask const& sign, ui32 value) {
    i32 res = unsigned_part.decode(value);
    if (sign.decode(value))
        res = -res;
    return res;
}

}}