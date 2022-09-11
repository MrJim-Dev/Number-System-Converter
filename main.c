#include <stdio.h>
#include "convert.h"
#include "convert.c" // For Non-C compilers


int main() {

    int command, exit = 0;
    int dec, binary, octal;
    char hex[32];

    while (exit == 0) {
        command = commandList();
        switch (command) {
        case 0:
            printf("Thank you for using the program!");
            exit = 1;
            break;
        case 1:
            printf("Enter a decimal number: ");
            scanf("%d", &dec);

            printf("\nBinary = %d", DecToBinary(dec));
            printf("\nOctal Value = %d", DecToOctal(dec));
            printf("\nHexadecimal = ");
            DecToHex(dec);

            break;
        case 2:
            printf("Enter a binary number: ");
            scanf("%d", &binary);

            printf("\nDecimal = %d", BinaryToDec(binary));
            printf("\nOctal Value = %d", BinaryToOctal(binary));
            printf("\nHexadecimal = ");
            BinaryToHex(binary);

            break;
        case 3:
            printf("Enter a Hexadecimal number: ");
            scanf("%s", &hex);

            printf("\nDecimal = %d", HexToDec(hex));
            printf("\nBinary = %d", HexToBinary(hex));
            printf("\nOctal Value = %d", HexToOctal(hex));

            break;
        case 4:
            printf("Enter a octal number: ");
            scanf("%d", &octal);

            printf("\nDecimal = %d", OctalToDec(octal));
            printf("\nBinary = %d", OctalToBinary(octal));
            printf("\nHexadecimal = ");
            OctalToHex(octal);

            break;
        default:
            printf("Invalid Command! Please try again.");
            break;
        }
    }

    return 0;
}