#include <stdio.h>

void print_multiplication_table(int row, int col) {
    if (row < 10) {
        if (col < 10) {
            printf("%d x %d = %d\n", row, col, row * col);
            print_multiplication_table(row, col + 1);
        } else {
            print_multiplication_table(row + 1, 1);
        }
    }
}

int main() {
    print_multiplication_table(1, 1);
    return 0;
}
