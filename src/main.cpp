#include <iostream>

#include <vcrate/bytecode/Helper.hpp>

int main() {

    using namespace vcrate::bytecode;
    using namespace vcrate;

    Mask ma(0b01111000);
    Mask mb(0b00000100);
    Mask mc = Mask::join(ma, mb);

    ui32 value = 1;
    std::cout << "Mask: " << std::hex << ma.get_mask() << " = ";
    std::cout << ma.get_left_mask() << " << " << std::dec << ma.get_shift() << '\n';
    std::cout << "Max : " << ma.max_value() << '\n';
    std::cout << "Value : " << std::hex << value << '\n';
    std::cout << "\tEncode : " << std::hex << ma.encode(value) << '\n';
    std::cout << "\tDecode : " << std::hex << ma.decode(value) << '\n';
    std::cout << "\tEncode-Decode : " << std::hex << ma.decode(ma.encode(value)) << '\n';

    std::cout << "Mask: " << std::hex << mb.get_mask() << " = ";
    std::cout << mb.get_left_mask() << " << " << std::dec << mb.get_shift() << '\n';
    std::cout << "Max : " << mb.max_value() << '\n';
    std::cout << "Value : " << std::hex << value << '\n';
    std::cout << "\tEncode : " << std::hex << mb.encode(value) << '\n';
    std::cout << "\tDecode : " << std::hex << mb.decode(value) << '\n';
    std::cout << "\tEncode-Decode : " << std::hex << mb.decode(mb.encode(value)) << '\n';

    std::cout << "Mask: " << std::hex << mc.get_mask() << " = ";
    std::cout << mc.get_left_mask() << " << " << std::dec << mc.get_shift() << '\n';
    std::cout << "Max : " << mc.max_value() << '\n';
    std::cout << "Value : " << std::hex << value << '\n';
    std::cout << "\tEncode : " << std::hex << mc.encode(value) << '\n';
    std::cout << "\tDecode : " << std::hex << mc.decode(value) << '\n';
    std::cout << "\tEncode-Decode : " << std::hex << mc.decode(mc.encode(value)) << '\n';
}