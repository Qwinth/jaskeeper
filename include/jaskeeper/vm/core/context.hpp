#pragma once
#include <stack>
#include <unordered_map>
#include <cstdint>
#include <jaskeeper/vm/core/object.hpp>
#include <jaskeeper/vm/core/stackframe.hpp>

struct JSExecutionContext {
    std::stack<JSStackFrame> stack;
    std::unordered_map<uint32_t, JSObject> objPool;

    uint64_t instrPointer;
};