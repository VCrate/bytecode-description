#include <vcrate/vcx/Executable.hpp>

namespace vcrate { namespace vcx {

void Executable::dump(std::ostream& os) const {
    os << "Executable: \n";

    os << "Entry point: " << entry_point << "\n";

    ui32 size_header = sizeof(ui32) * 4;
    ui32 size_symbols = 0;
    for(auto const& pair : symbols)
        size_symbols += pair.first.size() + 1 + sizeof(pair.second);
    ui32 size_jmp_table = sizeof(ui32) * jmp_table.size();
    ui32 size_data = sizeof(ui32) * data.size();
    ui32 size_code = sizeof(ui32) * code.size();

    ui32 size_total = size_header + size_symbols + size_jmp_table + size_data + size_code;

    os << "Size: " << size_total << "\n";
    os << "\t[Header] " << size_header << "\n";
    os << "\t[Symbols] " << size_symbols << " (" << symbols.size() <<" elements)" << "\n";
    os << "\t[Jump Table] " << size_jmp_table << " (" << jmp_table.size() <<" elements)" << "\n";
    os << "\t[Data] " << size_data << "\n";
    os << "\t[Code] " << size_code << " (" << code.size() <<" instructions max)" << "\n";

    os << "Symbols: \n";
    for(auto const& pair : symbols)
        os << "\t\"" << pair.first << "\" -> " << pair.second << "\n";
}

void Executable::read_header(std::istream& is, 
    ui32& size_symbols, ui32& size_jmp_table, ui32& size_data, ui32& size_code) {

    is.read(reinterpret_cast<char*>(&size_symbols), sizeof(size_symbols));
    is.read(reinterpret_cast<char*>(&size_jmp_table), sizeof(size_jmp_table));
    is.read(reinterpret_cast<char*>(&size_data), sizeof(size_data));
    is.read(reinterpret_cast<char*>(&size_code), sizeof(size_code));
    is.read(reinterpret_cast<char*>(&entry_point), sizeof(entry_point));
}

void Executable::read_symbols(std::istream& is, ui32 size) {
    std::string symbol;
    ui32 address;
    for(ui32 i = 0; i < size; ++i) {
        std::getline(is, symbol, '\0');
        is.read(reinterpret_cast<char*>(&address), sizeof(address));

        symbols.insert(std::make_pair(symbol, address));
    }
}

void Executable::read_jmp_table(std::istream& is, ui32 size) {
    jmp_table.resize(size);
    ui32 address;
    for(ui32 i = 0; i < size; ++i) {
        is.read(reinterpret_cast<char*>(&address), sizeof(address));
        jmp_table[i] = address;
    }
}

void Executable::read_data(std::istream& is, ui32 size) {
    data.resize(size);
    ui32 value;
    for(ui32 i = 0; i < size; ++i) {
        is.read(reinterpret_cast<char*>(&value), sizeof(value));
        data[i] = value;
    }
}

void Executable::read_code(std::istream& is, ui32 size) {
    code.resize(size);
    ui32 instruction;
    for(ui32 i = 0; i < size; ++i) {
        is.read(reinterpret_cast<char*>(&instruction), sizeof(instruction));
        code[i] = instruction;
    }

}

void Executable::write_header(std::ostream& os) {
    ui32 size_jmp_table = jmp_table.size();
    ui32 size_data = data.size();
    ui32 size_symbols = symbols.size();
    ui32 size_code = code.size();

    os.write(reinterpret_cast<char*>(&size_symbols), sizeof(size_symbols));
    os.write(reinterpret_cast<char*>(&size_jmp_table), sizeof(size_jmp_table));
    os.write(reinterpret_cast<char*>(&size_data), sizeof(size_data));
    os.write(reinterpret_cast<char*>(&size_code), sizeof(size_code));
    os.write(reinterpret_cast<char*>(&entry_point), sizeof(entry_point));
}

void Executable::write_symbols(std::ostream& os) {
    for(auto const& p : symbols) {
        const char* symbol = p.first.c_str();
        ui32 address = p.second;
        os.write(symbol, (p.first.size() + 1) / sizeof(char));
        os.write(reinterpret_cast<char*>(&address), sizeof(address));
    }
}

void Executable::write_jmp_table(std::ostream& os) {
    for(auto address : jmp_table)
        os.write(reinterpret_cast<char*>(&address), sizeof(address));
}

void Executable::write_data(std::ostream& os) {
    for(auto value : data)
        os.write(reinterpret_cast<char*>(&value), sizeof(value));
}

void Executable::write_code(std::ostream& os) {
    for(auto instruction : code)
        os.write(reinterpret_cast<char*>(&instruction), sizeof(instruction));
}

std::istream& operator >> (std::istream& is, Executable& exe) {
    ui32 size_jmp_table, size_data, size_symbols, size_code;

    exe.read_header(is, size_symbols, size_jmp_table, size_data, size_code);
    exe.read_symbols(is, size_symbols);
    exe.read_jmp_table(is, size_jmp_table);
    exe.read_data(is, size_data);
    exe.read_code(is, size_code);

    return is;
}

std::ostream& operator << (std::ostream& os, Executable& exe) {
    exe.write_header(os);
    exe.write_symbols(os);
    exe.write_jmp_table(os);
    exe.write_data(os);
    exe.write_code(os);
    
    return os;
}

}}