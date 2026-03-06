#include <variant>
#include <jaskeeper/vm/core/primitives.hpp>

bool isString(JSPrimitive& value) {
    return std::holds_alternative<JSStringPrimitive>(value);
}

bool isNumber(JSPrimitive& value) {
    return std::holds_alternative<JSNumberPrimitive>(value);
}

bool isBoolean(JSPrimitive& value) {
    return std::holds_alternative<JSBooleanPrimitive>(value);
}

bool isUndefined(JSPrimitive& value) {
    return std::holds_alternative<JSUndefined>(value);
}

bool isNull(JSPrimitive& value) {
    return std::holds_alternative<JSNull>(value);
}