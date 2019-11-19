def FloydWarshall(G):
    n = len(G)
    Edges = []
    V = G.keys()
    for i,e in G.items():
        for j,w in G[i]:
            if (j,i,w) not in Edges:
                Edges.append((i,j,w))
    dist = dict()
    for i in V:
        for j in V:
            dist[(i,j)] = float("Inf")    
        dist[(i,i)] = 0
    for i,j,w in Edges:
        dist[(i,j)] = w
    for i in V:
        for j in V:
            for k in V:
                if dist[(i,k)] + dist[(k,j)] < dist[(i,j)]:
                    dist[(i,j)] = dist[(i,k)] + dist[(k,j)]
    for i in V:
        for j in V:
            print("({} to {}) = {}".format(i,j,dist[(i,j)]))
if __name__ == "__main__":
    G = dict()
    # for i in range(1, int(input("Enter No. of vertices: "))+1):
    #     G[i] = []
    # for _ in range(int(input("Enter No. of Edges: "))):
    #     i, j, w = map(int, input().split())
    #     G[i].append((j, w))
    # print(G)
    G = {1: [(3, 1), (4, 3), (2, 7)], 2: [(1, 7), (5, 3), (4, 8)], 3: [(1, 1), (4, 4)], 4: [(3, 4), (1, 3), (2, 8), (5, 5)], 5: [(2, 3), (4, 5)]}
    FloydWarshall(G)

