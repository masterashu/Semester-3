def BellmanFord(G, start):
    old, new = dict(), dict()
    for i in G.keys():
        old[i] = float('inf')
        new[i] = float('inf')
    old[start] = 0
    new[start] = 0
    unchanged = 0
    for _ in range(len(G)-1):
        for i in G.keys():
            for neighbour, weight in G[i]:
                new[neighbour] = min(old[neighbour], new[neighbour], old[i] + weight)
        flag = True
        for i in old.keys():
            flag = flag and (old[i] == new[i])
            old[i] = new[i]
        if flag and unchanged >= 1:
            break
    # extra iteration
    for i in G.keys():
        for neighbour, weight in G[i]:
            new[neighbour] = min(old[neighbour], new[neighbour], old[i] + weight)
    flag = True
    for i in old.keys():
        flag = flag and (old[i] == new[i])
        old[i] = new[i]
    if not flag:
        print("Negetive cycle found")
        return
    # output
    for i,j in old.items():
        print(f"{i} => {j}")


if __name__ == "__main__":
    # G = dict()
    # for i in range(1,int(input("Enter No. of vertices: "))+1):
    #     G[i] = []
    # for _ in range(int(input("Enter No. of Edges: "))):
    #     i,j,w = map(int, input().split())
    #     G[i].append((j,w))
    # print(G)
    G = {1: [(3, 1), (4, 3), (2, 7)], 2: [(1, 7), (5, 3), (4, 8)], 3: [(1, 1), (4, 4)], 4: [(3, 4), (1, 3), (2, 8), (5, 5)], 5: [(2, 3), (4, 5)]}
    BellmanFord(G, int(input("Enter Starting Vertex: ")))


