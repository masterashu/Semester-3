def OneZeroKnapsack(I, cost):
    I.sort()
    n = len(I)  # no of Items
    arr = [[0]*(cost+1) for _ in range(n+1)]
    for i in range(1, n+1):
        for j in range(1, cost+1):
            if I[i-1][0] <= j:
                arr[i][j] = max(arr[i-1][j-I[i-1][0]] + I[i-1][1], arr[i-1][j])
            else:
                arr[i][j] = arr[i-1][j]

    print("Max Value:", arr[n][cost])
    print(arr[i])

if __name__ == "__main__":
    print("One-Zero Knapsack")
    n = int(input("Enter No of Items: "))
    I = []
    print("Enter weight and value: ")
    for _ in range(n):
        i, j = map(int, input().split())
        I.append((i, j))
    # print(I)
    # I = [(10, 60), (20, 100), (30, 120)]
    OneZeroKnapsack(I, int(input("Enter Total Cost: ")))
