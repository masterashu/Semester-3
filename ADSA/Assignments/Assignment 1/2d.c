#include <stdio.h>
#include <stdlib.h>

int isMinima(int *arr[], int x, int y, int len){
    int is_minima = 1;
    if(x + 1 <= len){
        if(arr[y][x + 1] < arr[y][x]){
            is_minima = 0;
        }    
    }
    if(y + 1 <= len){
        if(arr[y + 1][x] < arr[y][x]){
            is_minima = 0;
        }
    }
    if(y - 1 >= 0){
        if(arr[y - 1][x] < arr[y][x]){
            is_minima = 0;
        }
    }
    if(x - 1 >= 0){
        if(arr[y][x - 1] < arr[y][x]){
            is_minima = 0;
        }
    }
    return is_minima;
}

int localMinima(int *arr[], int x0, int y0, int x1, int ActualLen){

    if(x0 >= x1){
        return arr[y0][x0];
    }

    int min = arr[y0][x0];
    int minIndX = x0, minIndY = y0;
    int midX = x0 + (x1 - x0)/2;
    int midY = y0 + (x1 - x0)/2, lastY = y0 + (x1 - x0);
    int len = x1 - x0;

    //Checking through the columns

    for(int i = x0; i <= x0 + len; i+=(x1-x0)/2){
        for(int j = y0; j <= y0 + len; j++){
            if(isMinima(arr, i, j, ActualLen)){
                return arr[j][i];
            }
            else if(arr[j][i] < min){
                min = arr[j][i];
                minIndX = i;
                minIndY = j;
            }
        }
    }

    //Checking through the rows

    for(int j = y0; j <= y0 + len; j+=(x1-x0)/2){
        for(int i = x0; i <= x0 + len; i++){
            if(isMinima(arr, i, j, ActualLen)){
                return arr[j][i];
            }
            else if(arr[j][i] < min){
                min = arr[j][i];
                minIndX = i;
                minIndY = j;
            }
        }
    }

    if(minIndX - 1 >= 0){
        if(arr[minIndY][minIndX] > arr[minIndY][minIndX - 1]){
            if(minIndY < midY){
                return localMinima(arr, minIndX - midX, y0, minIndX, ActualLen);
            }
            else
            {
                return localMinima(arr, minIndX - midX, y0 + midY, minIndX, ActualLen);
            } 
        }
    }
    else if(minIndX + 1 < ActualLen){
        if(arr[minIndY][minIndX] > arr[minIndY][minIndX + 1]){
            if(minIndY < midY){
                return localMinima(arr, minIndX, y0, minIndX + midX, ActualLen);
            }
            else
            {
                return localMinima(arr, minIndX, y0 + midY, minIndX + midX, ActualLen);
            } 
        }
    }
    else if(minIndY - 1 >= 0){
        if(arr[minIndY][minIndX] > arr[minIndY - 1][minIndX]){
            if(minIndX < midX){
                return localMinima(arr, x0, minIndY - midY, midX, ActualLen);
            }
            else
            {
                return localMinima(arr, midX, minIndY - midY, x1, ActualLen);
            } 
        }           
    }   
    else if(minIndY + 1 < ActualLen){
        if(arr[minIndY][minIndX] > arr[minIndY + 1][minIndX]){
            if(minIndX < midX){
                return localMinima(arr, x0, minIndY + midY, midX, ActualLen);
            }
            else
            {
                return localMinima(arr, midX, minIndY + midY, x1, ActualLen);
            } 
        }
    }  

    return 0;
     
}

int main(){
        int n;
    printf("Enter length: ");
    scanf("%d", &n);
    int **arr = (void*)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        *(arr + i) = (void*)malloc(sizeof(int) * n);
    }
    for(int i = 0; i < n; i++){
        printf("Enter Row: ");
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
        }  
    }
    printf("Miminum No is %d.\n", localMinima(arr, 0, 0, n-1, n));
    printf("\n");
}
