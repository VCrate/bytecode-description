#include <vcrate/instruction/Instruction.hpp>

#include <vcrate/bytecode/v1.hpp>

#include <stdexcept>

namespace vcrate { namespace instruction {

Instruction::Instruction(ui32 main, ui32 extra0, ui32 extra1) {
    namespace btc = ::vcrate::bytecode::v1;

    auto ope = static_cast<bytecode::Operations>(btc::instruction.decode(main));
    auto def = bytecode::OpDefinition::get(ope);
    switch(def.arg_count()) {
        case 0:
            first = main;
            return;
        case 1:
        {
            auto type = btc::arg_24_type.decode(main);
            if (require_complete_instruction(type))
                second = extra0;
            first = main;
            return;
        }
        case 2:
        {
            auto type0 = btc::arg_12a_type.decode(main);
            auto type1 = btc::arg_12b_type.decode(main);
            if (require_complete_instruction(type0)) {
                second = extra0;
                if (require_complete_instruction(type1))
                    third = extra1;
            } else {
                if (require_complete_instruction(type1))
                    second = extra0;
            }
            first = main;
            return;
        }
        default:
            throw std::runtime_error("OperationDefinition return an argument count above 2");
    }
}

}}