#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//#include "stringIdentifierV1.c"
#include "stringIdentifierV2.c"

int main()
{
    int result[2];

    //Testing same string as the suffix and prefix
    putchar('\n');
    stringIdentifier("up", "up", "up", result);
    printf("Result Comparison : \n");
    printf("Actual result   - prefix: %d - sufix: %d\n", result[0], result[1]);
    printf("Expected result - prefix: %d - sufix: %d\n", 1, 1);

    //Testing Empty string comparison
    putchar('\n');
    stringIdentifier("", "", "", result);
    printf("Result Comparison : \n");
    printf("Actual result   - prefix: %d - sufix: %d\n", result[0], result[1]);
    printf("Expected result - prefix: %d - sufix: %d\n", -1, -1);

    //Testing Case sensitive
    putchar('\n');
    stringIdentifier("Hello World", "h", "D", result);
    printf("Result Comparison : \n");
    printf("Actual result   - prefix: %d - sufix: %d\n", result[0], result[1]);
    printf("Expected result - prefix: %d - sufix: %d\n", 0, 0);

    //Testing same characters in different order
    putchar('\n');
    stringIdentifier("pude", "up", "ed", result);
    printf("Result Comparison : \n");
    printf("Actual result   - prefix: %d - sufix: %d\n", result[0], result[1]);
    printf("Expected result - prefix: %d - sufix: %d\n", 0, 0);

    // Testing Scape sequences functionality
    putchar('\n');
    stringIdentifier("A\072\065\'", "A:5", "5\'", result);
    printf("Result Comparison : \n");
    printf("Actual result   - prefix: %d - sufix: %d\n", result[0], result[1]);
    printf("Expected result - prefix: %d - sufix: %d\n", 1, 1);

    //Testing character termination character against null terminator
    putchar('\n');
    stringIdentifier("A", "A", "", result);
    printf("Result Comparison : \n");
    printf("Actual result   - prefix: %d - sufix: %d\n", result[0], result[1]);
    printf("Expected result - prefix: %d - sufix: %d\n", 1, -1);

    //Testing space charater against nothing or empty string
    putchar('\n');
    stringIdentifier("A", "", "A", result);
    printf("Result Comparison : \n");
    printf("Actual result   - prefix: %d - sufix: %d\n", result[0], result[1]);
    printf("Expected result - prefix: %d - sufix: %d\n", -1, 1);

    //Testing bigger sufix than string
    putchar('\n');
    stringIdentifier("A", "A", "AAA", result);
    printf("Result Comparison : \n");
    printf("Actual result   - prefix: %d - sufix: %d\n", result[0], result[1]);
    printf("Expected result - prefix: %d - sufix: %d\n", 1, 0);

    //Testing oversized string
    putchar('\n');
    printf("Result Comparison : \n");
    stringIdentifier("00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000", result);
    printf("Actual result   - prefix: %d - sufix: %d\n", result[0], result[1]);
    printf("Expected result - prefix: %d - sufix: %d\n", -1, -1);

    //Testing NULL pointer
    putchar('\n');
    printf("Result Comparison : \n");
    stringIdentifier(NULL, NULL, NULL, result);
    printf("Actual result   - prefix: %d - sufix: %d\n", result[0], result[1]);
    printf("Expected result - prefix: %d - sufix: %d\n", -1, -1);
    return 0;
}
