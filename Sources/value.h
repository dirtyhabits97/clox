#ifndef clox_value_h
#define clox_value_h

#include "common.h"

// NOTE: For small fixed-size values (e.g. integers)
// many instructions sets store the value directly in the code stream
// right after the opcode.
//
// These are called **immediate instruction**

typedef double Value;

typedef struct {
  int capacity;
  int count;
  Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array, Value value);
void freeValueArray(ValueArray* array);

#endif
