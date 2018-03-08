#include <iostream>

#include <vcrate/bytecode/Helper.hpp>
#include <vcrate/Alias.hpp>

#include <ctime>
#include <cstdlib>

using namespace vcrate::bytecode;
using namespace vcrate;

void error(ui32 mask, std::string method, ui32 tested, ui32 right_value, ui32 wrong_value) {
    std::cout << "\033[31m\033[1mError:\033[0m ";
    std::ios old_state(nullptr);
    old_state.copyfmt(std::cout);
    std::cout << "0x" << std::hex << std::uppercase << mask;
    std::cout << "." << method << "( " << std::nouppercase << "0x" << std::uppercase << tested << " ) -> ";
    std::cout << std::nouppercase << "0x" << std::uppercase << wrong_value << ", ";
    std::cout << std::nouppercase << "0x" << std::uppercase << right_value << " expected\n";
    std::cout.copyfmt(old_state);
}

ui32 test_encoding(ui32 mask, ui32 test, ui32 expected) {
    Mask m { mask };
    ui32 value = m.encode(test);
    if (expected != value)
        error(mask, "encode", test, expected, value);

    return expected == value;
}

ui32 test_decoding(ui32 mask, ui32 test, ui32 expected) {
    Mask m { mask };
    ui32 value = m.decode(test);
    if (expected != value)
        error(mask, "decode", test, expected, value);

    return expected == value;
}

ui32 test_max(ui32 mask, ui32 expected) {
    Mask m { mask };
    ui32 value = m.max_value();
    if (expected != value) {
        std::cout << "\033[31m\033[1mError:\033[0m ";
        std::ios old_state(nullptr);
        old_state.copyfmt(std::cout);
        std::cout << "0x" << std::hex << std::uppercase << mask;
        std::cout << ".max_value() -> ";
        std::cout << std::nouppercase << "0x" << std::uppercase << value << ", ";
        std::cout << std::nouppercase << "0x" << std::uppercase << expected << " expected\n";
        std::cout.copyfmt(old_state);
    }
    return expected == value;
}

ui32 test_join_encoding(ui32 mask0, ui32 mask1, ui32 test) {
    Mask m0 { mask0 };
    Mask m1 { mask1 };
    Mask m = Mask::join(m0, m1);
    ui32 v0 = m0.encode(m1.encode(test));
    ui32 v1 = m.encode(test);

    if (v0 != v1) {
        std::cout << "\033[31m\033[1mError:\033[0m ";
        std::ios old_state(nullptr);
        old_state.copyfmt(std::cout);
        std::cout << "join( " << std::hex << std::uppercase << mask0 << ", " << mask1 << " ).encode( ";
        std::cout << std::nouppercase << "0x" << std::uppercase << test << " ) -> ";
        std::cout << std::nouppercase << "0x" << std::uppercase << v1 << ", ";
        std::cout << std::nouppercase << "0x" << std::uppercase << v0 << " expected\n";
        std::cout.copyfmt(old_state);
    }

    return v0 == v1;
}

ui32 test_join_decoding(ui32 mask0, ui32 mask1, ui32 test) {
    Mask m0 { mask0 };
    Mask m1 { mask1 };
    Mask m = Mask::join(m0, m1);
    ui32 v0 = m1.decode(m0.decode(test));
    ui32 v1 = m.decode(test);

    if (v0 != v1) {
        std::cout << "\033[31m\033[1mError:\033[0m ";
        std::ios old_state(nullptr);
        old_state.copyfmt(std::cout);
        std::cout << "join( " << std::hex << std::uppercase << mask0 << ", " << mask1 << " ).decode( ";
        std::cout << std::nouppercase << "0x" << std::uppercase << test << " ) -> ";
        std::cout << std::nouppercase << "0x" << std::uppercase << v1 << ", ";
        std::cout << std::nouppercase << "0x" << std::uppercase << v0 << " expected\n";
        std::cout.copyfmt(old_state);
    }

    return v0 == v1;
}

ui32 test_getters(ui32 right_mask, ui32 shift) {
    ui32 mask = right_mask << shift;
    Mask m { mask };
    ui32 m_shift = m.get_shift();
    ui32 m_lmask = m.get_shifted_mask();
    ui32 m_rmask = m.get_mask();

    if (m_shift != shift) {
        std::cout << "\033[31m\033[1mError:\033[0m ";
        std::ios old_state(nullptr);
        old_state.copyfmt(std::cout);
        std::cout << "0x" << std::hex << std::uppercase << mask;
        std::cout << ".get_shift() -> ";
        std::cout.copyfmt(old_state);
        std::cout << m_shift << ", " << shift << " expected\n";
    }
    if (m_lmask != mask) {
        std::cout << "\033[31m\033[1mError:\033[0m ";
        std::ios old_state(nullptr);
        old_state.copyfmt(std::cout);
        std::cout << "0x" << std::hex << std::uppercase << mask;
        std::cout << ".get_shifted_mask() -> ";
        std::cout << std::nouppercase << "0x" << std::uppercase << m_lmask << ", ";
        std::cout << std::nouppercase << "0x" << std::uppercase << mask << " expected\n";
        std::cout.copyfmt(old_state);
    }
    if (m_rmask != right_mask) {
        std::cout << "\033[31m\033[1mError:\033[0m ";
        std::ios old_state(nullptr);
        old_state.copyfmt(std::cout);
        std::cout << "0x" << std::hex << std::uppercase << mask;
        std::cout << ".get_mask() -> ";
        std::cout << std::nouppercase << "0x" << std::uppercase << m_rmask << ", ";
        std::cout << std::nouppercase << "0x" << std::uppercase << right_mask << " expected\n";
        std::cout.copyfmt(old_state);
    }

    return (m_shift == shift) + (m_lmask == mask) + (m_rmask == right_mask);
}

ui32 test_all(ui32 rmask, ui32 shift, ui32 value, ui32 after_encoding, ui32 after_decoding, ui32 max) {
    ui32 mask = rmask << shift;
    ui32 correct = 0;
    correct += test_encoding(mask, value, after_encoding);
    correct += test_decoding(mask, value, after_decoding);
    correct += test_max(mask, max);
    correct += test_getters(rmask, shift);
    return correct;
}

ui32 test_join(ui32 m0, ui32 m1, ui32 test) {
    return test_join_decoding(m0, m1, test) + test_join_encoding(m0, m1, test);
}

constexpr ui32 num_test_join = 2;
constexpr ui32 num_test_all = 6;

int main() {

    std::srand(std::time(nullptr));
    constexpr ui32 iter_join = 1000;
    constexpr ui32 iter_all = 100000;
    constexpr ui32 possible_mask = 32 * 33 / 2;

    ui32 correct_test = 0;

    for(ui32 i = 0; i < iter_join; ++i) {
        for(ui32 j0 = 0; j0 < 32; ++j0) {
            ui32 m0 = (~0u) >> j0;
            for(ui32 s0 = 0; s0 <= j0; ++s0) {
                ui32 mm0 = m0 << s0;
                for(ui32 j1 = 0; j1 < 32; ++j1) {
                    ui32 m1 = (~0) >> j1;
                    for(ui32 s1 = 0; s1 <= j1; ++s1) {
                        ui32 mm1 = m1 << s1;
                        correct_test += test_join(mm0, mm1, rand());
                    }
                }
            }
        }
    }

    std::cout << "Join Test : \033[1m";
    if (correct_test == iter_join * num_test_join * possible_mask * possible_mask) {
        std::cout << "\033[30mOK";
    } else {
        std::cout << "\033[31mERROR";
    }
    std::cout << "\033[0m ( " << correct_test << "/" << iter_join * num_test_join * possible_mask * possible_mask<< " )\n";

    correct_test = 0;
    for(ui32 i = 0; i < iter_all; ++i) {
        for(ui32 j0 = 0; j0 < 32; ++j0) {
            ui32 m0 = (~0u) >> j0;
            for(ui32 s0 = 0; s0 <= j0; ++s0) {
                ui32 rd = rand();
                correct_test += test_all(m0, s0, rd, (rd & m0) << s0, (rd >> s0) & m0, m0);
            }
        }
    }

    std::cout << "All Test : \033[1m";
    if (correct_test == iter_all * num_test_all * possible_mask) {
        std::cout << "\033[30mOK";
    } else {
        std::cout << "\033[31mERROR";
    }
    std::cout << "\033[0m ( " << correct_test << "/" << iter_all * num_test_all * possible_mask << " )\n";

}