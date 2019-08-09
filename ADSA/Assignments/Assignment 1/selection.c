#include <stdio.h>

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void sort(int arr[], int length){
    for (int i = 0; i < length; i++){
        int pos = i;
        for (int j = i + 1; j < length; j++){
            if(arr[j] < arr[pos]){
                pos = j;
            }
        }
        if(i != pos){
            swap(&arr[i], &arr[pos]);
        }
    }
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
    sort(arr, n);
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
