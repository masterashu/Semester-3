/*
 * Algorithm:
 * We Check All distinct pairs of people and
 * check if they were online at the same time
 * We check that person1 exited after person2 entered
 * and person2 exited after person 1 entered
 * for i in 0 to n:
 *    for j in (i+1) to n:
 *       if(person1.entry < person2.exit && person2.entry < person1.exit):
 *          no_of_pairs += 1
 */

#include <stdio.h>

typedef struct person
{
    int entry;
    int exit;
} Person;


int main(int argc, char const *argv[])
{
    int noOfPeople;
    scanf("%d", &noOfPeople);

    Person people[noOfPeople];

    for (int i = 0; i < noOfPeople; i++){
        scanf("%d %d", &people[i].entry, &people[i].exit);
    }

    int distinctPairs = 0;

    for (int i = 0; i < noOfPeople; i++){
        for (int j = i + 1; j < noOfPeople; j++){
            if(people[i].entry < people[j].exit && people[j].entry < people[i].exit){
                distinctPairs++;
            }
        }
    }

    printf("Possible distinct pairs are %d", distinctPairs);

    return 0;
}
