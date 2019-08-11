#include <stdio.h>

int findMinimum(int arr[], int length){
    int min = arr[0];
    for (int i = 0; i < length; i++){
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main(){
    int n;
    printf("Enter length: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter numbers: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Miminum No is %d.\n", findMinimum(arr, n));
    printf("\n");
}
