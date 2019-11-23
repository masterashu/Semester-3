def bfs(G, L, s, t, n, parent):
    Q = []
    visited = dict()
    for i in range(1,n+1):
        visited[i] = False
    visited[s] = True
    parent[s] = -1
    Q.append(s)

    while len(Q) > 0:
        u = Q[0]
        Q = Q[1:]
        for i in range(1,n+1):
            if G[(u,i)] > 0 and visited[i] is False:
                Q.append(i)
                visited[i] = True
                parent[i] = u
    return visited[t]


def FordFulkersion(G, n, s, t):
    max_flow = 0
    Res = dict()
    L = []
    # Initial Residual Network
    for x,y in G.items():
        Res[x] = y
    
    while(True):
        path = dict()
        # If BFS is Success full
        if bfs(Res, L, s, t, n, path):
            min_flow = float("inf")
            u = t
            while u != s:
                min_flow = min(min_flow, Res[(path[u], u)])
                u = path[u]
            u = t
            while u != s:
                Res[(path[u], u)] -= min_flow
                Res[(u, path[u])] += min_flow
                u = path[u]
            
            max_flow += min_flow
        else:
            break

    return max_flow


if __name__ == "__main__":
    # n = int(input("Enter No. of Vertices: "))
    # e = int(input("Enter No. of Edges: "))
    # Edges = []
    # for _ in range(e):
    #     i, j, c = map(int, input().split())
    #     Edges.append((i, j, c))
    # s, t = map(int, input("Enter Source and Sink: ").split())
    G = {1: [(2, 16), (3, 13)], 2: [(4, 12), (3, 10)], 3: [
        (2, 4), (5, 14)], 4: [(3, 7), (6, 20)], 5: [(6, 4), (4, 7)]}
    Edges = []
    for i, e in G.items():
        for j, w in G[i]:
            Edges.append((i, j, w))
    
    # Edges = [(1, 2, 16), (1, 3, 13), (2, 4, 12), (2, 3, 10), (3, 2, 4),
            #  (3, 5, 14), (4, 3, 7), (4, 6, 20), (5, 4, 7), (5, 6, 4)]
    G = dict()
    n, s, t = 6, 1, 6
    for i in range(1,n+1):
        for j in range(1,n+1):
            G[(i,j)] = 0
    for i,j,c in Edges:
        G[(i,j)] = c
    print(FordFulkersion(G, n, s, t))

    