#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include <optional>
#include <variant>
#include <cstdint>
#include <jaskeeper/vm/core/value.hpp>

enum class JSObjectType {
    Function,
    Array,
    String,
    Number,
    Boolean,
    Map,
    Error
};

struct JSObject {
    JSObjectType type;
    std::string typeName;

    std::unordered_map<std::string, JSValue> properties;
};