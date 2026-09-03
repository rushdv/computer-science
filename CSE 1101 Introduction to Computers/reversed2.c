#include <stdio.h>
#include <string.h>

int main() {
    char str[50];
    int i, len;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0';
    }

    len = strlen(str);

    printf("Reversed: ");
    for (i = len - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}

