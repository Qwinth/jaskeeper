#pragma once
#include <string>
#include <jaskeeper/vm/core/value.hpp>

struct JSVariable {
    std::string name;
    JSValue value;
};