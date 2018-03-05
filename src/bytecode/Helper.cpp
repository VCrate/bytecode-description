#include <vcrate/bytecode/Helper.hpp>

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

}}