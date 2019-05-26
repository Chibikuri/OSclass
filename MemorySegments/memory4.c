#include<stdio.h>

void func(void);

int main() {
        void (*pointer)() = func;
        pointer();
        printf("%p\n", &pointer);
        return 0;
}

void func() {}
