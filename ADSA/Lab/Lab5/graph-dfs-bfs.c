/* 
 * ADSA
 * Assignment 3
 * Ashutosh Chauhan
 * S20180010017
 * Section - B
 */
  
#include <stdio.h>
#include <stdlib.h>
   
typedef struct vertex {
    int val;
    /* Some other details about edge
    ...
     */
    int visited;
    struct vertex* next;
    struct edge* link;
} V;
   
typedef struct edge {
    struct vertex* v;
    struct edge* link;
} E;
   
typedef struct list {
    struct vertex* v;
    struct list* next;
} List;
   
V* CreateVertex(int val) {
    V* v = (V*)malloc(sizeof(V));
    v->val = val;
    v->visited = 0;
    v->next = NULL;
    v->link = NULL;
    return v;
}
   
E* CreateEdge(V* aVertex) {
    E* e = (E*)malloc(sizeof(E));
    e->link = NULL;
    e->v = aVertex;
    return e;
}
   
List* CreateNode(V* v) {
    List* new_node = (List*)malloc(sizeof(List));
    new_node->v = v;
    new_node->next = NULL;
    return new_node;
}
   
void AddVertex(V** pGraph, int val) {
    V* Graph = *pGraph;
    V* newV = CreateVertex(val);
    newV->next = Graph;
    *pGraph = newV;
}
   
V* SearchVertex(V* Graph, int val) {
    while (Graph != NULL && Graph->val != val) {
        Graph = Graph->next;
    }
    return Graph;
}
   
void InitiatlizeGraph(V* Graph) {
    while (Graph != NULL) {
        Graph->visited = 0;
        Graph = Graph->next;
    }
}
   
void AddEdgeDirected(V** pGraph, int val1, int val2) {
    V* v1 = SearchVertex(*pGraph, val1);
    V* v2 = SearchVertex(*pGraph, val2);
    if (v1 == NULL || v2 == NULL) {
        printf("Vertex doesn't Exist!\n");
        return;
    }
    E* tmp = v1->link;
    v1->link = CreateEdge(v2);
    v1->link->link = tmp;
}
   
void AddEdgeUndirected(V** pGraph, int val1, int val2) {
    V* v1 = SearchVertex(*pGraph, val1);
    V* v2 = SearchVertex(*pGraph, val2);
    if (v1 == NULL || v2 == NULL) {
        printf("Vertex doesn't Exist!\n");
        return;
    }
   
    E* tmp = v1->link;
    v1->link = CreateEdge(v2);
    v1->link->link = tmp;
   
    tmp = v2->link;
    v2->link = CreateEdge(v1);
    v2->link->link = tmp;
}
   
void PrintGraph(V* Graph) {
    while (Graph != NULL) {
        E* tmp = Graph->link;
        if (tmp == NULL) {
            printf("!disconnected node: %d\n", Graph->val);
        }
        while (tmp != NULL) {
            printf("%d -> %d\n", Graph->val, tmp->v->val);
            tmp = tmp->link;
        }
        Graph = Graph->next;
    }
}
   
// Using D.F.S.
void DFS(V* Graph) {
    if (Graph == NULL) {
        return;
    }
    // If Vertex Not Visited
    if (Graph->visited == 0) {
        // Printing
        printf("<Node:%d>\t", Graph->val);
        Graph->visited = 1;  // Making Vertex Visited
   
        // DFS of chilren
        if (Graph->link != NULL) {
            E* edge = Graph->link;
            while (edge != NULL) {
                DFS(edge->v);
                edge = edge->link;
            }
        }
    }
}
   
void BFS(V* Graph) {
    // If Graph is empty
    if (Graph == NULL) {
        return;
    }
    // Making all visited 0
    InitiatlizeGraph(Graph);
    // Creating the Queue
    List *begin, *end;
    // Enter the Root Node in the Queue
    begin = CreateNode(Graph);
    end = begin;
  
    // While Queue is not empty
    while (begin != NULL) {
        if (begin->v->visited == 0) {
            // Printing
            printf("<Node:%d>\t", begin->v->val);
            begin->v->visited = 1;  // Making Vertex Visited
            // For all children
            if (begin->v->link != NULL) {
                E* edge = begin->v->link;
                while (edge != NULL) {
                    if (edge->v->visited == 0) {
                        end->next = CreateNode(edge->v);
                        end = end->next;
                    }
                    edge = edge->link;
                }
            }
        }
        List* tmp = begin;
        begin = begin->next;
        free(tmp);
    }
}
  
int main(int argc, char const* argv[]) {
    V* Graph = NULL;
  
    int choice = 1;
    while (choice != 0) {
        {
            printf("Press 1 to Add a Vertex\n");
            printf("Press 2 to Add a Directed Edge\n");
            printf("Press 3 to Add a Undirected Edge\n");
            printf("Press 4 to Print the Graph\n");
            printf("Press 5 to DFS Search from Vertex V\n");
            printf("Press 6 to BFS Search from Vertex V\n");
            printf("Press 0 to Quit\n");
        }
        printf("Enter Choice: ");
        scanf("%d", &choice);
        int val1, val2;
        switch (choice) {
            case 1:
                printf("Vertex Value :> ");
                scanf("%d", &val1);
                AddVertex(&Graph, val1);
                break;
            case 2:
                printf("From Vertex Value :> ");
                scanf("%d", &val1);
                printf("To Vertex Value :> ");
                scanf("%d", &val2);
                AddEdgeDirected(&Graph, val1, val2);
                break;
            case 3:
                printf("Vertex 1 Value :> ");
                scanf("%d", &val1);
                printf("Vertex 2 Value :> ");
                scanf("%d", &val2);
                AddEdgeUndirected(&Graph, val1, val2);
                break;
            case 4:
                printf("\n");
                PrintGraph(Graph);
                break;
            case 5:
                printf("Vertex Value :> ");
                scanf("%d", &val1);
                InitiatlizeGraph(Graph);
                DFS(SearchVertex(Graph, val1));
                printf("\n");
                break;
            case 6:
                printf("Vertex Value :> ");
                scanf("%d", &val1);
                BFS(SearchVertex(Graph, val1));
                printf("\n");
                break;
            default:
                break;
        }
    }
  
    return 0;
}
  