
#include <stdio.h>
#include <math.h>
#include <string.h>

int commandList(void) {
    printf("\n\n|- Command List -------------------------------------|");
    printf("\n| 0 - Exit the Program                               |");
    printf("\n| 1 - Convert a Decimal                              |");
    printf("\n| 2 - Convert a Binary                               |");
    printf("\n| 3 - Convert a Hexadecimal                          |");
    printf("\n| 4 - Convert a Octal                                |");
    printf("\n|----------------------------------------------------|");
    printf("\n");

    int command;
    printf("\nEnter Command: ");
    scanf("%d", &command);

    return command;
}

int DecToBinary(int num) {
    int bin = 0, rem, i = 1;

    while (num != 0) {
        rem = num % 2;
        bin += (rem * i);
        num /= 2;
        i *= 10;
    }

    return bin;
}; // Decimal to Binary

int DecToOctal(int num) {
    int oct = 0, rem, i = 0;

    while (num != 0) {
        rem = num % 8;
        oct += (rem * pow(10, i));
        num /= 8;
        i++;
    }

    return oct;
}; // Decimal to Octal

int DecToHex(int num) {
    int rem, pos = 0, i;
    char hex[32], temp[32];

    while (num > 0) {
        rem = num % 16;
        switch (rem) {
        case 10:
            temp[pos] = 'A';
            break;
        case 11:
            temp[pos] = 'B';
            break;
        case 12:
            temp[pos] = 'C';
            break;
        case 13:
            temp[pos] = 'D';
            break;
        case 14:
            temp[pos] = 'E';
            break;
        case 15:
            temp[pos] = 'F';
            break;
        default:
            temp[pos] = rem + 0x30; // ACSII
            break;
        }

        num /= 16;
        pos++;
    }

    for (i = (pos - 1); i >= 0; i--) {
        printf("%c", temp[i]);
    }

    return 0;
}; // Decimal to Hex

int BinaryToDec(int num) {
    int rem, i = 0, dec = 0;

    while (num != 0) {
        rem = num % 10;
        dec += (rem * pow(2, i));
        num /= 10;
        i++;
    }

    return dec;
}; // Binary to Decimal
int BinaryToOctal(int num) {
    // Convert Binary to Decimal
    int dec = BinaryToDec(num);
    // Convert Decimal to Octal
    int octal = DecToOctal(dec);

    return octal;
}; // Binary to Octal

int BinaryToHex(int num) {
    // Convert Binary to Decimal
    int dec = BinaryToDec(num);
    // Convert Decimal to Hex
    DecToHex(dec);

    return 0;
}; // Binary To Hex

int OctalToDec(int num) {
    int dec = 0, rem, i = 0;

    while (num != 0) {
        rem = num % 10;
        dec += (rem * pow(8, i));
        num /= 10;
        i++;
    }

    return dec;

}; // Octal to Decimal
int OctalToBinary(int num) {
    // convert octal to decimal
    int dec = OctalToDec(num);
    // now convert decimal to binary
    int binary = DecToBinary(dec);

    return binary;
}; // Octal to Binary

int OctalToHex(int num) {
    // convert octal to decimal
    int dec = OctalToDec(num);
    // decimal to hex
    DecToHex(dec);

    return 0;
}; // Octal To Hex

int HexToDec(char num[]) {
    int i = 0, dec = 0, base = 1, length;

    length = strlen(num); // get length of hex
    for (i = length - 1; i >= 0; i--) {
        if (num[i] >= '0' && num[i] <= '9') {
            dec += (num[i] - 48) * base;
            base *= 16;
        } else if (num[i] >= 'A' && num[i] <= 'F') {
            dec += (num[i] - 55) * base;
            base *= 16;
        } else if (num[i] >= 'a' && num[i] <= 'f') {
            dec += (num[i] - 87) * base;
            base *= 16;
        }
    }
    return dec;
}; // Hex to Char

int HexToOctal(char num[]) {
    int dec = HexToDec(num);

    int octal = DecToOctal(dec);

    return octal;
}; // Hex To Octal

int HexToBinary(char num[]) {
    
    int dec = HexToDec(num);

    int binary = DecToBinary(dec);

    return binary;
}; // Hex To Binary



