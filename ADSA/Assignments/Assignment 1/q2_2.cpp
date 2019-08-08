#include <stdio.h>

typedef struct person
{
    int entry;
    int exit;
} Person;

int compare(Person p1, Person p2){
    return 1;
}

void mergeSort(int Array[], int start, int end) 
{ 
    if (start == end) {
        return;
    }
    int mid = (start + end - 1) / 2; 

    mergeSort(Array, start, mid); 
    mergeSort(Array, mid + 1, end); 

    // Merging Arrayay
    int length = end - start + 1;
    int Temp[length];
    for (int i = 0; i < length; i++){
        Temp[i] = Array[i + start];
    }

    int i = 0, j = 0, m = mid - start + 1;

    for (int c = start; c <= end; c++){
        if(i > m){
            Array[c] = Temp[m + j++];
        }
        else if (j + m > end)
        {
            Array[c] = Temp[i++];
        }
        else if (Temp[i] < Temp[j])
        {
            Array[c] = Temp[i++];
        }
        else
        {
            Array[c] = Temp[m + j++];
        }       
    }

} 

int main(int argc, char const *argv[])
{
    // int noOfPeople;
    // scanf("%d", &noOfPeople);

    // Person people[noOfPeople];

    // for (int i = 0; i < noOfPeople; i++){
    //     scanf("%d %d", &people[i].entry, &people[i].exit);
    // }

    // int distinctPairs = 0;

    int array[] = {3,5,2,1,7,8,6,4};
    mergeSort(array, 0, 7);
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

}