#include <stdio.h>
#include <stdlib.h>

int task1();
int task2();

void flush_stdin();
void read_int(void* out);
void read_string(char** ptr, int max_len);
void read_int_range(int* out, int low, int high, const char* error_msg);

int int_len(int x);

void* mem_allocate(int size);
void* mem_reallocate(void* ptr, int size);
