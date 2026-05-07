#include <stdio.h>

int main(){

    char str[50];
    int i, len;

    printf("Enter a string: ");
    gets(str);

    len = strlen(str);

    printf("Reversed: ");
    for (i = len-1; i >= 0; i--){
        printf("%c", str[i]);
    }

    return 0;
}
