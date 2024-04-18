#include <stdio.h>


typedef struct {
    int* pointers[10];
} my_mm_t;

int g_mem[10];
my_mm_t mms;

char* my_calloc(int n, int size);
void my_free(char* p);

void init_my_mm() {
    for (int i = 0; i < 10; i++) {
        mms.pointers[i] = NULL;
    }
}

char* my_calloc(int n, int size) {
    int index = -1;
    for (int i = 0; i < 10; i++) {
        if (mms.pointers[i] == NULL) {
            index = i;
            break;
        }
    }
    

    if (index != -1) {
        char* ptr = (char*)&g_mem[index];
        for (int i = 0; i < n * size; i++) {
            ptr[i] = 0;
        }
        mms.pointers[index] = (int*)ptr;
        printf("1");
        for (int i = 0; i < index; i++) {
            printf("1");
        }
        for (int i = index + 1; i < 10; i++) {
            printf("0");
        }
        printf("\n");
        return ptr;
    }
    

    printf("Cannot allocate memory\n");
    return NULL;
}


void my_free(char* p) {
    int index = (p - (char*)&g_mem[0]) / sizeof(int);
    if (index >= 0 && index < 10) {
        mms.pointers[index] = NULL;
        printf("0");
        for (int i = 0; i < index; i++) {
            printf("1");
        }
        for (int i = index + 1; i < 10; i++) {
            printf("0");
        }
        printf("\n");
    } else {
        printf("Invalid memory address\n");
    }
}

int main() {
    init_my_mm();
    
    char* np1 = my_calloc(1, 1);
    char* np2 = my_calloc(1, 2);
    char* np3 = my_calloc(1, 3);
    char* np4 = my_calloc(1, 4);
    my_free(np1);
    my_free(np4);
    char* np5 = my_calloc(1, 5);
    char* np6 = my_calloc(1, 3);
    
    return 0;
}
