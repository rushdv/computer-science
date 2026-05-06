#include <stdio.h>
int main()
{
    int arr1[] = {11,12,13,14,15,16};
    int add_value, add_position, add_index;
    int i;
    int arr1_size = sizeof(arr1) / sizeof(int);

    printf("Array: \n");
    for(i=0; i<arr1_size; i++){
        printf("%d ", arr1[i]);
    }

    printf("\n\n Enter value: ");
    scanf("%d", &add_value);
    printf("\n Enter Position: ");
    scanf("%d", &add_position);

    add_index = add_position - 1;

    for(i=arr1_size-2; i>=add_index; i--){
        arr1[i+1] = arr1[i];
    }

    arr1[arr1_size-1] = add_value;

    printf("\n\n Array: \n");
    for(i=0; i<arr1_size; i++){
        printf("%d ", arr1[i]);
    }

    return 0;

}
