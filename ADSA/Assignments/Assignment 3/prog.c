/* 
 * ADSA
 * Assignment 3
 * Ashutosh Chauhan
 * S20180010017
 * Section - B
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define index(x) tolower(x) - 'a'

// Structure to store Employee Details
typedef struct employee {
    // int employee_id;
    char name[20];
    int level;
    struct employee* boss;
    struct employee* child;
    struct employee* next;
} Employee;

// Temporary structure for Queue for Level Order Traversal
typedef struct node {
    Employee* employee;
    struct node* next;
} Node;

// Trie for O(m) name Lookup
typedef struct name_dict {
    struct name_dict* ch[26];
    Employee* emp;
    short child;
} NameDict;

// Creating a New Trie Object
NameDict* newNameDict() {
    NameDict* new = (NameDict*)malloc(sizeof(NameDict));
    for (int i = 0; i < 26; i++) {
        new->ch[i] = NULL;
    }
    new->emp = NULL;
    new->child = 0;
    return new;
}

// Creating a New Employee Object
Employee* newEmployee(char* name, int level) {
    Employee* new = (Employee*)malloc(sizeof(Employee));
    strcpy(new->name, name);
    new->level = level;
    new->boss = NULL;
    new->child = NULL;
    new->next = NULL;
    return new;
}

// Print an Employee's Detail
void printEmployee(Employee* employee) {
    printf("\nEmployee Name: %s\n", employee->name);
    printf("Employee Level: %d\n", employee->level);
    printf("Employee Boss: %s\n", employee->boss);
    printf("--------------------------------------\n");
}

// Search for a given Employee in the Tree using DFS (Not optimal)
// Employee* findEmployee(Employee* root, char* name) {
//     if (root != NULL) {
//         if (strcmp(root->name, name) == 0) {
//             return root;
//         }
//         if (root->child != NULL) {
//             Employee* tmp = findEmployee(root->child, name);
//             if (tmp != NULL) {
//                 return tmp;
//             }
//         }
//         if (root->next != NULL) {
//             Employee* tmp = findEmployee(root->next, name);
//             if (tmp != NULL) {
//                 return tmp;
//             }
//         }
//     }
//     return NULL;
// }

// Add Employee Entry in the Trie
void addNameDict(NameDict* root, char* name, Employee* employee) {
    while (*name != 0) {
        if (root->ch[index(*name)] == NULL) {
            root->ch[index(*name)] = newNameDict();
            root->child++;
        }
        root = root->ch[index(*name)];
        name++;
    }
    root->emp = employee;
}

// Find Employee Pointer from Trie
Employee* findEmployee(NameDict* Names, char* name) {
    while (*name != 0) {
        if (Names->ch[index(*name)] == NULL) {
            return NULL;
        }
        Names = Names->ch[index(*name)];
        name++;
    }
    return Names->emp;
}

// Delete a Entry from Trie
NameDict* deleteNameDict(NameDict* Names, char* name) {
    if (Names == NULL) {
        return NULL;
    } else {
        if (Names->ch[index(*name)] != NULL) {
            Names->ch[index(*name)] = deleteNameDict(Names->ch[index(*name)], name + 1);
            if (Names->ch[index(*name)] == NULL) {
                Names->child--;
            }
        }
    }
    if (*name == 0) {
        if (Names->emp != NULL) {
            if (Names->child == 0){
                free (Names);
                return NULL;
            }
            else {
                Names->emp = NULL;
            }
        }
    }
    else    {
        if (Names->child == 0 && Names->emp != NULL) {
            free(Names);
            return NULL;
        }
    }
    return Names;
}

// Add Employee to the Tree
void addEmployee(Employee* root, NameDict* Names, char* emp, char* boss) {
    Employee* Boss = findEmployee(Names, boss);
    if (Boss == NULL) {
        printf("Boss Doesn\'t Exist.\nAborting Adding Employee...\n");
        return;
    }
    // Employee doesn't have anyone under him
    if (Boss->child == NULL) {
        Boss->child = newEmployee(emp, Boss->level + 1);
        Boss->child->boss = Boss;
        addNameDict(Names, emp, Boss->child);
    } else {
        Employee* tmp = Boss->child;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newEmployee(emp, tmp->level);
        addNameDict(Names, emp, tmp->next);
        tmp->next->boss = Boss;
    }
}

void deleteEmployee(Employee* root, char* name, char* substitute, NameDict** Names) {
    Employee* Emp = findEmployee(*Names, name);
    if (Emp == NULL) {
        printf("Employee Doesn\'t Exist.\nAborting Adding Employee...\n");
        return;
    }
    // Finding Substitute at Same Level
    Employee* Sub = findEmployee(*Names, substitute);

    // Employee* Sub = Emp->boss->child;
    // while (Sub != NULL && strcmp(Sub->name, substitute)) {
    //     Sub = Sub->next;
    // }
    // Substitute with given name does not exist
    if (Sub == NULL) {
        printf("Error! The Substitute with that name does not exist!\n");
        return;
    }
    // Giving Child Elements to Substitute
    if (Emp->child != NULL) {
        Employee* tmp = Emp->child;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = Sub->child;
        Sub->child = Emp->child;
    }

    // Deleting the Employee
    // If Employee is the First one in Level-Wise Linked List
    if (Emp->boss->child == Emp) {
        Employee* boss = Emp->boss;
        boss->child = Emp->next;
        free(Emp);
        *Names = deleteNameDict(*Names, name);
    } else {
        Employee *tmp = Emp->boss->child, *tmp2;
        while (tmp != NULL) {
            if (tmp->next == Emp) {
                tmp2 = tmp->next;
                tmp->next = tmp2->next;
                free(tmp2);
                break;
            } else {
                tmp = tmp->next;
            }
        }
    }
}

Node* newNode(Employee* employee) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->employee = employee;
    tmp->next = NULL;
    return tmp;
}

void printLevelOrder(Employee* root) {
    // Initializing the Queue
    printf("--CEO--: ");
    Node* head = newNode(root);
    Node* tail = head;
    Node* tmp;
    int length = 1;
    int current_level = 1;
    while (length > 0) {
        if (head->employee->child != NULL) {
            Employee* tmp2 = head->employee->child;
            while (tmp2 != NULL) {
                tail->next = newNode(tmp2);
                tail = tail->next;
                length++;
                tmp2 = tmp2->next;
            }
        }

        if (head->employee->level > current_level) {
            printf("\nLevel %d: ", current_level);
            current_level++;
        }

        printf("%s ", head->employee->name);
        tmp = head;
        head = head->next;
        length--;
        free(tmp);
    }
    printf("\n");
    printf("--------------------------------------\n");
}

Employee* lowestCommonBoss(Employee* root, NameDict *Names, char* emp1, char* emp2) {
    // Creating Stacks for both Employees
    Employee* Emp1 = findEmployee(Names, emp1);
    if (Emp1 == NULL) {
        printf("Employee 1 Doesn\'t Exist.\nAborting Adding Employee...\n");
        return;
    }
    Employee* Emp2 = findEmployee(Names, emp2);
    if (Emp2 == NULL) {
        printf("Employee 2 Doesn\'t Exist.\nAborting Adding Employee...\n");
        return;
    }
    Node* Top1 = newNode(Emp1);
    Node* Top2 = newNode(Emp2);
    Node* tmp;

    // Push the Employees in the path from Employee1 to CEO
    while (Top1->employee->boss != NULL) {
        tmp = Top1;
        Top1 = newNode(tmp->employee->boss);
        Top1->next = tmp;
    }

    // Push the Employees in the path from Employee2 to CEO
    while (Top2->employee->boss != NULL) {
        tmp = Top2;
        Top2 = newNode(tmp->employee->boss);
        Top2->next = tmp;
    }

    Employee* lowest_common_boss = Top1->employee;

    // Pop Out Common Elements till any Difference Ocuur
    while (Top1 != NULL && Top2 != NULL && strcmp(Top1->employee->name, Top2->employee->name) == 0) {
        lowest_common_boss = Top1->employee;
        tmp = Top1;
        Top1 = Top1->next;
        free(tmp);
        tmp = Top2;
        Top2 = Top2->next;
        free(tmp);
    }

    // Free up Remaining Memory
    while (Top1 != NULL) {
        tmp = Top1;
        Top1 = Top1->next;
        free(tmp);
    }
    while (Top1 != NULL) {
        tmp = Top2;
        Top2 = Top2->next;
        free(tmp);
    }

    return lowest_common_boss;
}

int main(int argc, char const* argv[]) {
    char company[20];
    printf("Enter Name of CEO: ");
    scanf("%s", company);
    NameDict* Names = newNameDict();
    Employee* Employees = newEmployee(company, 1);
    addNameDict(Names, company, Employees);
    int choice = 1;

    while (choice != 0) {
        printf("Press 1 to Add an Employee\n");
        printf("Press 2 to Delete an Employee\n");
        printf("Press 3 to Find Lowest Common Boss of 2 Employees\n");
        printf("Press 4 to Print the Employees in Level Wise Order\n");
        printf("Press 0 to Quit\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        char emp[20], emp1[20], emp2[20], boss[20];

        switch (choice) {
            case 1:
                printf("Employee Name :> ");
                scanf("%s", emp);
                printf("Boss Name :> ");
                scanf("%s", boss);
                addEmployee(Employees, Names, emp, boss);
                break;
            case 2:
                printf("Employee Name :> ");
                scanf("%s", emp1);
                printf("Substitute Name :> ");
                scanf("%s", emp2);
                deleteEmployee(Employees, emp1, emp2, &Names);
                break;
            case 3:
                printf("Employee1 Name :> ");
                scanf("%s", emp1);
                printf("Employee2 Name :> ");
                scanf("%s", emp2);
                printf("Lowest Common Ancestor: %s\n", (lowestCommonBoss(Employees, Names, emp1, emp2)->name));
                break;
            case 4:
                printLevelOrder(Employees);
                break;
            default:
                break;
        }
    }
    printLevelOrder(Employees);

    return 0;
}
