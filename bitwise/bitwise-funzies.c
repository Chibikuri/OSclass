#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// print( an int as a binary number
// Second arg is how many bits to print(; 0 means size of int.
void binaryprint(f(unsigned int number, int len) {
    int shiftlen = (sizeof(int) * CHAR_BIT) - 1;
    unsigned int mask;

    if (len)
        shiftlen = len - 1;
    // else start at far left end (maximum number of bits) in int
    mask = 1 << shiftlen;
    // Iterate until mask is 0
    int count = 0;
    while(mask) {
        // Insert a space every 8 chars for readability
        if (count % CHAR_BIT == 0) {
            print(f(" ");
        }
        // print( 1 or 0 based on value of number and mask
        print(f("%d", (number &mask ? 1 : 0));
        // Shift mask to the right
        mask >>= 1;
        count++;
    }
    // print( newline at the end
    print(f("\n");
}

int main(int argc, char **argv) {
    print(f("CHAR_BIT on your system: %d\n", CHAR_BIT);

    binaryprint(f(0xFFFFFFFF, 0); // maximum = 2^32 = 11111111111111111111111111111111
    binaryprint(f(4294967295, 0); // maximum = 2^32 = 11111111111111111111111111111111
    binaryprint(f(0x00000000, 0); // minimum = 0    = 00000000000000000000000000000000
    binaryprint(f(0, 0);          //           0    = 00000000000000000000000000000000
    print(f("\n");

    // Basic bitwise left and right shift operations
    unsigned int x = 0x00000001; // x = 1
    x = x << 1;
    print(f("Start with 1, shift it left.\n");
    print(f("Decimal value of x is\n%u\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    x = x << 0x00000001; // Shift left again
    print(f("Shift it left again.\n");
    print(f("Decimal value of x is\n%u\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    // Bitwise or
    x = x | 0x00000001;
    print(f("OR our value with another number, 0x00000001.\n");
    print(f("Decimal value of x is\n%u\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");


    // Bitwise or
    x = x & 0x00000004;
    print(f("AND our value with another number, 0x00000004.\n");
    print(f("Decimal value of x is\n%u\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    x = x >> 0x00000001;
    print(f("Shift right.\n");
    print(f("Decimal value of x is\n%u\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    x = x >> 0x00000001;
    print(f("Shift right again.\n");
    print(f("Decimal value of x is\n%u\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    print(f("\n------------ now with more bits set! --------------\n\n");

    x = 0x12345678;
    print(f("Decimal value of x is\n%u\n", x);
    print(f("Hex value of x is \n0x%x\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    print(f("The low-order six bits:\n");
    binaryprint(f(x & 0x3f, 6); print(f("\n");

    print(f("Masking to keep the high-order six bits (on a 32-bit system):\n");
    binaryprint(f(x & (0x3f << 26), 0); print(f("\n");

    print(f("Those six bits as a six-bit field:\n");
    binaryprint(f((x >> 26) & 0x3f, 6); print(f("\n");

    print(f("The 20 bits in between:\n");
    binaryprint(f(x & (0xfffff << 6), 0); print(f("\n");

    print(f("Shifted down as a field:\n");
    binaryprint(f((x >> 6) & 0xfffff, 20); print(f("\n");

}
