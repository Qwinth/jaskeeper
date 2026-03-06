#pragma once
#include <deque>
#include <unordered_map>
#include <cstdint>
#include <jaskeeper/vm/core/value.hpp>
#include <jaskeeper/vm/core/variable.hpp>

struct JSStackFrame {
    std::deque<JSValue> tempValues;
    std::unordered_map<uint16_t, JSVariable> variables;

    uint64_t returnPointer;
};