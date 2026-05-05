#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
void reverse(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}
void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}
void print_usage() {
    printf("Usage: utility <string> <operation>\n");
    printf("Operations: reverse, uppercase, lowercase\n");
}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }
    char str[MAX];
    strncpy(str, argv[1], MAX);
    if (strcmp(argv[2], "reverse") == 0) {
        reverse(str);
    } else if (strcmp(argv[2], "uppercase") == 0) {
        to_uppercase(str);
    } else if (strcmp(argv[2], "lowercase") == 0) {
        to_lowercase(str);
    } else {
        print_usage();
        return 1;
    }
    printf("Result: %s\n", str);
    return 0;
}
