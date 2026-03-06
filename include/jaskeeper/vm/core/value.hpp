#pragma once
#include <variant>
#include <cstdint>
#include <jaskeeper/vm/core/primitives.hpp>

enum class JSValueType {
    Primitive,
    Object
};

struct JSValue {
    JSValueType type;

    std::variant<JSPrimitive, uint32_t> value;
};