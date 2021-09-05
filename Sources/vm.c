#include <stdio.h>
#include "common.h"
#include "debug.h"
#include "vm.h"

VM vm;

static void resetSTack() {
  vm.stackTop = vm.stack;
}

void initVM() {
  resetStack();
}

void freeVM() {
}

void push(Value value) {
  *vm.stackTop = value;
  vm.stackTop++;
}

Value pop() {
  vm.stackTop--;
  return *vm.stackTop;
}

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk->constants.values[READ_BYTE()])
  for (;;) {

#ifdef DEBUG_TRACE_EXECUTION
    // Since disassembleInstruction() takes an integer byte offset 
    // and we store the current instruction reference as a direct pointer, 
    // we first do a little pointer math to convert ip back to a relative 
    // offset from the beginning of the bytecode. 
    // Then we disassemble the instruction that begins at that byte.
    disassembleInstruction(
      vm.chunk,
      (int)(vm.ip - vm.chunk->code)
    );
#endif

    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
      case OP_CONSTANT: {
        Value constant = READ_CONSTANT();
        printValue(constant);
        printf("\n");
        break;
      }
      case OP_RETURN: {
        return INTERPRET_OK;
      }
    }
  }
#undef READ_BYTE
#undef READ_CONSTANT
}

InterpretResult interpret(Chunk* chunk) {
  vm.chunk = chunk;
  // ip: instruction pointer
  vm.ip = vm.chunk->code;
  // internal helper that runs the bytecode instructions
  return run();
}
