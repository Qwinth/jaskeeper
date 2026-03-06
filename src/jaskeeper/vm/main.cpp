#include <iostream>
#include <jaskeeper/vm/core/primitives.hpp>
#include <jaskeeper/vm/core/object.hpp>
#include <jaskeeper/vm/core/value.hpp>
#include <jaskeeper/vm/core/context.hpp>
#include <jaskeeper/vm/core/bytecode.hpp>

void JSExec(JSExecutionContext& context, const JSInstructionArray& program) {
    for (uint64_t& iptr = context.instrPointer; iptr < program.size(); iptr++) {
        const JSInstruction& instr = program[iptr];
        JSStackFrame& stframe = context.stack.top();

        switch (instr.opcode) {
            case JSOPCode::LOAD_PRIMITIVE: {
                stframe.tempValues.push_back({JSValueType::Primitive, instr.mainArg});

                break;
            }

            case JSOPCode::LOAD_OBJECT: {
                stframe.tempValues.push_back({JSValueType::Object, instr.mainArg});

                break;
            }
            
            default:
                break;
        }
    }
}

int main() {
    JSInstructionArray program{};
    JSExecutionContext context{};
    
    context.stack.push({});

    program.push_back({JSOPCode::LOAD_PRIMITIVE, "Hello from JSStringPrimitive running with JasKeeper!"});
    program.push_back({JSOPCode::LOAD_OBJECT, JSObjectHandle(49)});

    JSExec(context, program);
}