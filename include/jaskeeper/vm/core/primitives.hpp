#pragma once
#include <string>
#include <vector>
#include <variant>
#include <cstdint>

using JSStringPrimitive = std::string;
using JSNumberPrimitive = double;
using JSBooleanPrimitive = bool;

class JSUndefined {};
class JSNull {};

using JSObjectHandle = uint32_t;

using JSPrimitive = std::variant<JSStringPrimitive, JSNumberPrimitive, JSBooleanPrimitive, JSUndefined, JSNull, JSObjectHandle>;

enum class JSPrimitiveType {
    String,
    Number,
    Boolean,
    Undefined,
    Null
};

bool isString(JSPrimitive& value);
bool isNumber(JSPrimitive& value);
bool isBoolean(JSPrimitive& value);
bool isUndefined(JSPrimitive& value);
bool isNull(JSPrimitive& value);