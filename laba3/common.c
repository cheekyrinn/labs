#include "common.h"

void flush_stdin() {
    while (getchar() != '\n');
}

void read_int(void* out) {
    while (scanf_s("%d", out) != 1) {
        printf("invalid number\n");
        flush_stdin();
    }
}

void read_string(char** ptr, int max_size) {
    char c;
    int size = 0;

    flush_stdin();
    while ((c = (char) getchar()) != '\n' && c != EOF) {
        if (max_size != -1 && size >= max_size) break;

        *ptr = mem_reallocate(*ptr, (size + 1) * sizeof(char));
        (*ptr)[size++] = c;
    }
    *ptr = mem_reallocate(*ptr, (size + 1) * sizeof(char));
    (*ptr)[size] = '\0';
}

void read_int_range(int* out, int low, int high, const char* error_msg) {
    while (1) {
        read_int(out);
        if (*out < low || *out > high) {
            if (error_msg != NULL) {
                printf("%s\n", error_msg);
            } else {
                printf("this number must be between %d and %d\n", low, high);
            }
        } else {
            break;
        }
    }
}

int int_len(int x) {
    int result = 0;
    while (x != 0) {
        result++;
        x /= 10;
    }
    return result;
}


void* mem_allocate(int size) {
    void* result = malloc(size);
    if (result == NULL) {
        printf("error while allocating memory\n");
        exit(1);
    }
    return result;
}

void* mem_reallocate(void* ptr, int size) {
    void* result = realloc(ptr, size);
    if (result == NULL) {
        printf("error while allocating memory\n");
        exit(1);
    }
    return result;
}

int random_range(int min, int max) {
    return rand() % (max + 1 - min) + min;
}
