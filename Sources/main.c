#include "common.h"
#include "chunk.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
  Chunk chunk;
  initChunk(&chunk);

  // test
  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT);
  writeChunk(&chunk, constant);

  writeChunk(&chunk, OP_RETURN);

  // disassemble all of the instructions 
  // in the entire chunk
  disassembleChunk(&chunk, "test chunk");

  freeChunk(&chunk);
  return 0;
}
