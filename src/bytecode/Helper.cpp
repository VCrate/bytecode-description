#include <vcrate/bytecode/Helper.hpp>

#include <cmath>

namespace vcrate { namespace bytecode {

Mask::Mask(ui32 mask) {
    set_mask(mask);
}

void Mask::set_mask(ui32 mask) {
    this->shift = get_leading_zero(mask);
    this->mask = mask >> shift;
}

ui32 Mask::get_left_mask() const {
    return  mask;
}

ui32 Mask::get_mask() const {
    return mask << shift;
}

ui32 Mask::get_shift() const {
    return shift;
}

ui32 Mask::encode(ui32 value, ui32 base) const {
    base &= ~get_mask(); // reset base
    return base | (value & mask) << shift;
}

ui32 Mask::decode(ui32 value) const {
    return (value >> shift) & mask;
}

ui32 Mask::max_value() const {
    return mask;
}

Mask Mask::join(Mask const& first, Mask const& second) {
    return Mask(first.get_mask() & (second.get_mask() << first.get_shift()));
}

ui32 Mask::get_leading_zero(ui32 mask) {
    return __builtin_ctz(mask);
}

ui32 encode_signed_value(Mask const& unsigned_part, Mask const& sign, i32 value, ui32 base) {
    base = unsigned_part.encode(std::abs(value), base);
    base = sign.encode(value < 0, base);
    return base;
}

i32 decode_signed_value(Mask const& unsigned_part, Mask const& sign, ui32 value) {
    i32 res = unsigned_part.decode(value);
    if (sign.decode(value))
        res = -res;
    return res;
}

}}