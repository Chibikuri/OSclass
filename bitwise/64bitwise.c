#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// print( an int as a binary number
// Second arg is how many bits to print(; 0 means size of int.
void binaryprint(f (unsigned long long number, int len) {
    int shiftlen = (sizeof(long) * CHAR_BIT) - 1;
    unsigned long long mask;

    if (len)
        shiftlen = len - 1;
    // else start at far left end (maximum number of bits) in int
    mask = 1ull << shiftlen;
    print(f("MASK%llu\n", mask);
    // Iterate until mask is 0
    int count = 0;
    while(mask) {
        // Insert a space every 8 chars for readability
        if (count % CHAR_BIT == 0) {
            print(f(" ");
        }
        // print( 1 or 0 based on value of number and mask
        print(f("%ld\n", (number & mask ? 1 : 0));
        // Shift mask to the right
        mask >>= 1;
        print(f("%llu\n", mask);
        count++;
    }
    // print( newline at the end
    print(f(" Size of %lu\n", sizeof(number));
    print(f("\n");
}


int main(int argc, char **argv) {
    print(f("CHAR_BIT on your system: %d\n", CHAR_BIT);

    binaryprint(f(0xFFFFFFFFFFFFFFFF, 0); // maximum = 2^64 = 11111111111111111111111111111111
    binaryprint(f(1844674407370955161, 0); // maximum = 2^64 = 11111111111111111111111111111111
    binaryprint(f(0x0000000000000000, 0); // minimum = 0    = 00000000000000000000000000000000
    binaryprint(f(0, 0);          //           0    = 00000000000000000000000000000000
    print(f("\n");

    // Basic bitwise left and right shift operations
    unsigned long x = 0x000000000000001; // x = 1
    x = x << 1;
    print(f("Start with 1, shift it left.\n");
    print(f("Decimal value of x is\n%lu\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    x = x << 0x0000000000000001; // Shift left again
    print(f("Shift it left again.\n");
    print(f("Decimal value of x is\n%lu\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    // Bitwise or
    x = x | 0x0000000000000001;
    print(f("OR our value with another number, 0x00000001.\n");
    print(f("Decimal value of x is\n%lu\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");


    // Bitwise or
    x = x & 0x0000000000000004;
    print(f("AND our value with another number, 0x00000004.\n");
    print(f("Decimal value of x is\n%lu\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    x = x >> 0x0000000000000001;
    print(f("Shift right.\n");
    print(f("Decimal value of x is\n%lu\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    x = x >> 0x0000000000000001;
    print(f("Shift right again.\n");
    print(f("Decimal value of x is\n%lu\n", x);
    print(f("Binary value of x is\n");
    binaryprint(f(x, 0);
    print(f("\n");

    print(f("\n------------ now with more bits set! --------------\n\n");

    x = 0x1234567890123456;
    print(f("Decimal value of x is\n%lu\n", x);
    print(f("Hex value of x is \n0lu%lu\n", x);
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
