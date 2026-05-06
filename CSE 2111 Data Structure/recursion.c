#include <stdio.h>

int rec(int k)
{
    if (k==1)
        return 2*k;
    else
        return 2*k+rec(k-1);
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);


    printf("Result is: %d", rec(n));

    return 0;
}
