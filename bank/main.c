#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 32

enum { // defines the options so the program will know
    // how the input_validation function should work
    OPTION,
    CREDENTIALS,
    MONEY
};

void input_validation(char *str, int input_type);

int main(void) {

    int option = 0;
    char str[LEN] = {'\0'};

    printf("Welcome! Please choose an option:\n"); // this should run only
    // once at the start of the program

    while (1) {
        option = 0;
        printf("1. Create account.\n");
        printf("2. Log into your account.\n");
        printf("3. Transfer money to your account.\n");
        printf("4. Check your balance.\n");
        fgets(str, sizeof(str), stdin);
        input_validation(str, OPTION);
        option = atoi(str);
        if (option == -1) continue;
        printf("%s %d\n", str, option);
    }

    return 0;
}

void input_validation(char *str, int input_type) {
    char *p = NULL;
    int ch = 0;
    p = strchr(str, '\n');

    if (p == NULL) { // check if what the user typed is longer than the buffer
        while (ch != EOF) {
            ch = getc(stdin);
        }
    } else {
        switch (input_type) {
            case 0:
                if ((str[0] - '0' >= 1 && str[0] - '0' <= 4) && str[1] == '\n') {
                    str[1] = '\0';
                } else {
                    printf("Invalid input. Please choose one of the options:\n");
                    str[0] = '-';
                    str[1] = '1';
                    str[2] = '\0';
                }
                break;
            case 1:
                break;
            case 2:
                break;
            default:
                break;
        }
    }
    return;
}

