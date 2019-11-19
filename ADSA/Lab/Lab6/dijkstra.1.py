def get_weight(u,v,Edges):
    for i,j,w in Edges:
        if i == u and j == v:
            return w
    return float("Inf")


def Dijkstra(G, V):
    n = len(G)
    final = set()
    not_final = set(G.keys())
    dist = dict()
    for i in G.keys():
        dist[i] = float("Inf")    
    dist[V] = 0

    while len(final) < n:
        # Getting unsure vertex with minimun distance 
        u = min(not_final, key = lambda i: dist[i])
        # Making u final
        not_final.remove(u)
        final.add(u)
        # Updating all the non final neighbours of u
        for v,w in G[u]:
            if v not in final:
                dist[v] = min(dist[v], dist[u] + w)
    
    for i, w in dist.items():
        print(i, "=>", w)


if __name__ == "__main__":
    G = dict()
    for i in range(1, int(input("Enter No. of vertices: "))+1):
        G[i] = []
    for _ in range(int(input("Enter No. of Edges: "))):
        i, j, w = map(int, input().split())
        G[i].append((j, w))
    print(G)
    # G = {1: [(3, 1), (4, 3), (2, 7)], 2: [(1, 7), (5, 3), (4, 8)], 3: [(1, 1), (4, 4)], 4: [(3, 4), (1, 3), (2, 8), (5, 5)], 5: [(2, 3), (4, 5)]}
    Dijkstra(G, int(input("Enter Starting Vertex: ")))

