def Karger(Edges, vertices):
    V = []
    for v in vertices:
        V.append(set([v]))

    while len(V) > 2:
        s1, s2 = V[0], V[-1]
        x = []
        for i, j in Edges:
            if (i in s1 and j in s2) or (i in s2 and j in s1):
                pass
            else:
                x.append((i, j))
        V = V[1:-1] + [s1.union(s2)]
        Edges = x
    print(V)
    print(Edges)
    return len(Edges)


if __name__ == "__main__":
    Edges = [(1, 2), (2, 1), (1, 3), (3, 1), (2, 4), (4, 2), (2, 3), (3, 2), (3, 2), (2, 3),
             (3, 5), (5, 3), (4, 3), (3, 4), (4, 6), (6, 4), (5, 4), (4, 5), (5, 6), (6, 5)]
    n = 6
    V = list(range(1, n+1))
    G = dict()
    for i in range(1, n+1):
        for j in range(1, n+1):
            if (i, j) in Edges:
                G[(i, j)] = True
            else:
                G[(i, j)] = False

    print(Karger(Edges, V))
