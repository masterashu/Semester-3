#include <stdio.h>

typedef struct person {
    int entry;
    int exit;
} Person;

int binarySearchPersonEntry(Person Array[], int val, int start, int end) 
{ 
    while (start <= end) { 
        int m = start + (end - start) / 2; 
          if (Array[m].entry == val) 
            return m; 
          if (Array[m].entry < val) 
            start = m + 1; 
          else
            end = m - 1; 
    } 
    return start - 1; 
}

int compare(Person p1, Person p2){
    if (p1.entry < p2.entry) {
        return 1;
    }
    else {
        if (p1.exit < p2.exit) {
            return 1;
        }
        else {
            return 0;
        }
    }
}

void mergeSort(Person Array[], int start, int end) 
{ 
    if (start == end) {
        return;
    }
    int mid = (start + end - 1) / 2; 

    mergeSort(Array, start, mid); 
    mergeSort(Array, mid + 1, end); 

    // Merging Arrayay
    int length = end - start + 1;
    Person Temp[length];
    for (int i = 0; i < length; i++){
        Temp[i] = Array[i + start];
    }

    int i = 0, j = 0, m = mid - start + 1;

    for (int c = start; c <= end; c++){
        if(i >= m){
            Array[c] = Temp[m + j++];
        }
        else if (j + mid >= end)
        {
            Array[c] = Temp[i++];
        }
        else if (compare(Temp[i], Temp[m + j]))
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
    int noOfPeople;
    scanf("%d", &noOfPeople);

    Person people[noOfPeople];

    for (int i = 0; i < noOfPeople; i++){
        scanf("%d %d", &people[i].entry, &people[i].exit);
    }

    mergeSort(people, 0, noOfPeople - 1);

    int distinctPairs = 0;

    int begin = 0, end = 0, current_online = 0;
    for (int i = 0; i < noOfPeople; i++){
        distinctPairs += binarySearchPersonEntry(people, people[i].exit - 1, i + 1, noOfPeople - 1) - i;
    }
    
    printf("No. of distinct pairs are: %d.\n", distinctPairs);

}