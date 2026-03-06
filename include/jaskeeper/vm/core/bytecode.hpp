#pragma once
#include <vector>
#include <variant>
#include <cstdint>
#include <jaskeeper/vm/core/value.hpp>

enum class JSOPCode {
    LOAD_PRIMITIVE,
    LOAD_OBJECT
};

struct JSInstruction {
    JSOPCode opcode;

    JSPrimitive mainArg;
    JSPrimitive extraArg;

    uint16_t stackArgs;
};

using JSInstructionArray = std::vector<JSInstruction>;