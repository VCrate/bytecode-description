#include <vcrate/vcx/Executable.hpp>

#include <fstream>

using namespace vcrate::vcx;
using namespace vcrate;

ui32 to_ui32(const char(&a)[5]) {
    return a[3] << 24 | a[2] << 16 | a[1] << 8 | a[0];
}

int main() {
    Executable exe;

    exe.entry_point = 0x450;
    exe.jmp_table = std::vector<ui32> {
        0x200,
        0x210,
        0x422
    };

    exe.data = std::vector<ui32> {
        to_ui32("Hell"),
        to_ui32("o, W"),
        to_ui32("orld")
    };

    exe.code = std::vector<ui32> {
        0x123,
        0x456,
        0x789,
        0xffffffff
    };

    exe.symbols = std::map<std::string, ui32> {
        {"test", 0x200},
        {"ok", 0x25}
    };

    exe.dump(std::cout);
    std::ofstream os ("tmp/exe.vcx");
    os << exe;
    os.close();

    Executable from;
    std::ifstream is ("tmp/exe.vcx");
    is >> from;
    is.close();

    from.dump(std::cout);
}