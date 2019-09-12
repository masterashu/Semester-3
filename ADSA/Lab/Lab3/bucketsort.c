#include <stdio.h>
#include <stdlib.h>
// Considering max number to between 0 to 99

typedef struct list{
    int val;
    struct list* next;
} List;

List* create_node(int num){
    List* new = (List*)malloc(sizeof(List));
    new->val = num;
    new->next = NULL;
    return new;
}

void bucket_sort(int *arr, int n){
    List *buckets[10];
    for(int i = 0; i < 10; i++){
        buckets[i] = NULL;
    }
    for (int i = 0; i < n; i++){
        // Insert into correct bucket
        int pos = (arr[i]/10);
        // If Empty bucket
        if (buckets[pos] == NULL){
            buckets[pos] = create_node(arr[i]);
        }
        // If bucket is not empty insert into correct position
        else{
            List *tmp = buckets[pos];
            // Putting in the beginning
            if (tmp->val > arr[i]){
                buckets[pos] = create_node(arr[i]);
                buckets[pos]->next = tmp;
            }
            // Putting in the middle or last
            else {
                while(tmp->next != NULL && tmp->next->val < arr[i]){
                    tmp = tmp->next;
                }
                List *new = create_node(arr[i]);
                new->next = tmp->next;
                tmp->next = new;
            }
        }
    }
    int i = 0, j = 0;
    while(i < n){
        if(buckets[j] != NULL){
            arr[i++] = buckets[j]->val;
            buckets[j] = buckets[j]->next;
        }
        else {
            j++;
        }
    }
}

int main(){
    int arr[10] = {76, 38, 32, 53, 64, 14, 56 ,35 ,34, 12};
    bucket_sort(arr, 10);
    for (int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
