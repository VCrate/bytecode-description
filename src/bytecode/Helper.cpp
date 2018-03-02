#include <vcrate/bytecode/Helper.hpp>

namespace vcrate { namespace bytecode {

Mask::Mask(ui32 mask, ui32 shift)
    : mask(mask), shift(shift) {}

ui32 Mask::encode(ui32 value, ui32 base) const {
    base &= ~(mask << shift); // reset base
    return base | (value & mask) << shift;
}

ui32 Mask::decode(ui32 value) const {
    return value >> shift & mask;
}

ui32 Mask::max_value() const {
    return mask;
}

Mask Mask::join(Mask const& first, Mask const& second) {
    return Mask(first.mask & second.mask, first.shift + second.shift);
}

}}