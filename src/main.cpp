#include <iostream>

#include <vcrate/bytecode/Helper.hpp>

int main() {

    using namespace vcrate::bytecode;

    Mask m(0xF, 3);

    std::cout << std::hex << 12 << " -> " << m.max_value() << " " << m.encode(12) << " " << m.decode(12) << " " << m.decode(m.encode(42)) << '\n';
    
}