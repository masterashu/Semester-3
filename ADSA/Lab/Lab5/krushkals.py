def find(i, parent):
    if (parent[i] == i):
        return i
    else:
        return find(parent[i], parent)

def union(i, j, parent, rank):
    i_top = find(i, parent)
    j_top = find(j, parent)

    if rank[i_top] > rank[j_top]:
        parent[j_top] = i_top
    elif rank[i_top] < rank[j_top]:
        parent[i_top] = j_top
    else:
        parent[i_top] = j_top
        rank[j_top] += 1


def krushkals_mst(G, V):
    # creating an edge list
    Edges = []
    for i,e in G.items():
        for j,w in G[i]:
            if (j,i,w) not in Edges:
                Edges.append((i,j,w))
    Edges = sorted(Edges, key = lambda x: x[2])
    print (Edges)
    parent = dict()
    rank = dict()
    for i in V:
        parent[i] = i   
        rank[i] = 0

    final = []
    f = 0
    for i,j,w in Edges:
        # check for cycle
        if find(i, parent) == find(j, parent):
            continue
        else:
            f += 1
            final.append((i,j,w))
            union(i,j,parent,rank)
    
    print (final)

if __name__ == "__main__":
    G = dict()
    V = set()
    for i in range(1,int(input("Enter No. of vertices: "))+1):
        G[i] = []
    for _ in range(int(input("Enter No. of Edges: "))):
        i,j,w = map(int, input().split())
        G[i].append((j,w))
        V.add(i)
        V.add(j)
    # print(G)
    # G = {1: [(3, 1), (4, 3), (2, 7)], 2: [(1, 7), (5, 3), (4, 8)], 3: [(1, 1), (4, 4)], 4: [(3, 4), (1, 3), (2, 8), (5, 5)], 5: [(2, 3), (4, 5)]}
    # V = set([1, 2, 3, 4, 5])
    krushkals_mst(G, V)


