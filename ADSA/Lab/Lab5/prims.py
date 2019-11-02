def find_edges(v, Edges):
    cutting_edge = []
    for i, j, w in Edges:
        if (i in v and j not in v) or (i not in v and j in v):
            cutting_edge.append((i, j, w))
    return cutting_edge


def prims(G, V):
    # creating an edge list
    Edges = []
    for i, e in G.items():
        for j, w in G[i]:
            if (j, i, w) not in Edges:
                Edges.append((i, j, w))
    Edges = sorted(Edges, key=lambda x: x[2])
    print(Edges)
    final = []
    v = set()
    v.add(list(V)[0])
    while len(v) < len(V):
        cutting_edge = find_edges(v, Edges)
        i,j,w = min(cutting_edge, key=lambda i:i[2])
        final.append((i,j,w))
        v.add(i)
        v.add(j)

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
    # G = {1: [(3, 1), (4, 3), (2, 7)], 2: [(1, 7), (5, 3), (4, 8)], 3: [
    #     (1, 1), (4, 4)], 4: [(3, 4), (1, 3), (2, 8), (5, 5)], 5: [(2, 3), (4, 5)]}
    # V = set([1, 2, 3, 4, 5])
    prims(G, V)
