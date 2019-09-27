#include <stdio.h>
#include <stdlib.h>

typedef struct vertex {
    int val;
    /* Some other details about edge
    ...
     */
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
    v->next = NULL;
    v->link = NULL;
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

int InList(List* l, V* v) {
    while (l != NULL) {
        if (l->v == v) {
            return 1;
        }
        l = l->next;
    }
    return 0;
}

void AddToList(List** list, V* v) {
    if (*list == NULL) {
        *list = CreateNode(v);
    } else {
        List* tmp = *list;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = CreateNode(v);
    }
}

void FindAll(V* Graph, List** visited) {
    // Using D.F.S.
    if (Graph == NULL) {
        return;
    }
    if (InList(*visited, Graph) == 0) {
        AddToList(visited, Graph);
        if (Graph->link != NULL) {
            E* edge = Graph->link;
            while (edge != NULL) {
                FindAll(edge->v, visited);
                edge = edge->link;
            }
        }
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
            printf("Press 5 to Find all Vertex which can be reached from a given vertex\n");
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
                V* ver = SearchVertex(Graph, val1);
                List* list = NULL;
                FindAll(ver, &list);
                printf("Possible Nodes that can be visited: ");
                while (list != NULL) {
                    printf("%d ", list->v->val);
                    list = list->next;
                }
                printf("\n");
                break;
            default:
                break;
        }
    }

    return 0;
}
