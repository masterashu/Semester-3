#include <stdio.h>

int local_minima(int arr[], int low, int high, int length){
    int mid = low + (high - low)/2;
    if ((mid == 0 || arr[mid-1] > arr[mid]) && 
            (mid == length-1 || arr[mid+1] > arr[mid])) 
        return mid; 
    else if (mid > 0 && arr[mid-1] < arr[mid]) 
        return local_minima(arr, low, (mid -1), length); 
    return local_minima(arr, (mid + 1), high, length); 
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
    printf("Local Mimima is %d.\n", local_minima(arr, 0, n-1, n));
    printf("\n");

}