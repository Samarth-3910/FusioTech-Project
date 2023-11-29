#include <stdio.h>

int main() {
    int choice;
    int decimalNum, octalNum;
    long long binaryNum;
    char hexNum[50];

    do {
        printf("\nChoose Conversion:\n");
        printf("1. Decimal to Binary\n");
        printf("2. Binary to Decimal\n");
        printf("3. Decimal to Octal\n");
        printf("4. Octal to Decimal\n");
        printf("5. Hexadecimal to Binary\n");
        printf("6. Binary to Hexadecimal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNum);
                printf("Binary: ");
                if (decimalNum == 0) {
                    printf("0");
                } else {
                    int binaryArr[32], i = 0;
                    while (decimalNum > 0) {
                        binaryArr[i] = decimalNum % 2;
                        decimalNum /= 2;
                        i++;
                    }
                    for (int j = i - 1; j >= 0; j--) {
                        printf("%d", binaryArr[j]);
                    }
                }
                printf("\n");
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%lld", &binaryNum);
                int decimalNum2 = 0, base = 1;
                while (binaryNum > 0) {
                    decimalNum2 += (binaryNum % 10) * base;
                    binaryNum /= 10;
                    base *= 2;
                }
                printf("Decimal: %d\n", decimalNum2);
                break;

            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &decimalNum);
                printf("Octal: %o\n", decimalNum);
                break;

            case 4:
                printf("Enter an octal number: ");
                scanf("%o", &octalNum);
                printf("Decimal: %d\n", octalNum);
                break;

            case 5:
                printf("Enter a hexadecimal number: ");
                scanf("%s", hexNum);
                printf("Binary: ");
                for (int i = 0; hexNum[i] != '\0'; i++) {
                    switch (hexNum[i]) {
                        case '0': printf("0000"); break;
                        case '1': printf("0001"); break;
                        case '2': printf("0010"); break;
                        case '3': printf("0011"); break;
                        case '4': printf("0100"); break;
                        case '5': printf("0101"); break;
                        case '6': printf("0110"); break;
                        case '7': printf("0111"); break;
                        case '8': printf("1000"); break;
                        case '9': printf("1001"); break;
                        case 'A': case 'a': printf("1010"); break;
                        case 'B': case 'b': printf("1011"); break;
                        case 'C': case 'c': printf("1100"); break;
                        case 'D': case 'd': printf("1101"); break;
                        case 'E': case 'e': printf("1110"); break;
                        case 'F': case 'f': printf("1111"); break;
                        default: printf("\nInvalid hexadecimal digit %c\n", hexNum[i]); return 1;
                    }
                }
                printf("\n");
                break;

            case 6:
                printf("Enter a binary number: ");
                scanf("%lld", &binaryNum);
                printf("Hexadecimal: ");
                int hexDigit = 0, base2 = 1;
                while (binaryNum > 0) {
                    hexDigit += (binaryNum % 10) * base2;
                    binaryNum /= 10;
                    base2 *= 2;
                    if (base2 == 10000) {
                        switch (hexDigit) {
                            case 0: printf("0"); break;
                            case 1: printf("1"); break;
                            case 10: printf("2"); break;
                            case 11: printf("3"); break;
                            case 100: printf("4"); break;
                            case 101: printf("5"); break;
                            case 110: printf("6"); break;
                            case 111: printf("7"); break;
                            case 1000: printf("8"); break;
                            case 1001: printf("9"); break;
                            case 1010: printf("A"); break;
                            case 1011: printf("B"); break;
                            case 1100: printf("C"); break;
                            case 1101: printf("D"); break;
                            case 1110: printf("E"); break;
                            case 1111: printf("F"); break;
                            default: printf("\nInvalid hexadecimal digit\n"); return 1;
                        }
                        base2 = 1;
                        hexDigit = 0;
                    }
                }
                printf("\n");
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 0);

    return 0;
}
