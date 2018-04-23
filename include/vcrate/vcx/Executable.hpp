#pragma once

#include <vcrate/Alias.hpp>

#include <iostream>
#include <vector>
#include <map>

namespace vcrate { namespace vcx {

class Executable {
public:

    ui32 entry_point;

    std::vector<ui32> jmp_table;
    std::vector<ui32> data;
    std::vector<ui32> code;

    std::map<std::string, ui32> symbols;

    void dump(std::ostream& os = std::cout) const;

private:

    friend std::istream& operator >> (std::istream& is, Executable& exe);
    friend std::ostream& operator << (std::ostream& os, Executable& exe);

    void read_header(std::istream& is, ui32& size_symbols, ui32& size_jmp_table, ui32& size_data, ui32& size_code);
    void read_symbols(std::istream& is, ui32 size);
    void read_jmp_table(std::istream& is, ui32 size);
    void read_data(std::istream& is, ui32 size);
    void read_code(std::istream& is, ui32 size);

    void write_header(std::ostream& os);
    void write_symbols(std::ostream& os);
    void write_jmp_table(std::ostream& os);
    void write_data(std::ostream& os);
    void write_code(std::ostream& os);
};

std::istream& operator >> (std::istream& is, Executable& exe);
std::ostream& operator << (std::ostream& os, Executable& exe);

}}