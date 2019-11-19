def get_max(I, cost):
    m = 0
    for w,v in I:
        if w == cost:
            m = max(m, v)
    return m
    
def UnboundedKnapsack(I, cost):
    I.sort()
    arr = [0]*(cost+1)
    for i in range(1, cost+1):
        arr[i] = max(arr[i], get_max(I, i))
        for j in range(i):
            arr[i] = max(arr[i], arr[i-j] + arr[j])

    print("Max Value:", arr[cost])

if __name__ == "__main__":
    print("Unbounded Knapsack")
    n = int(input("Enter No of Items: "))
    I = []
    print("Enter weight and value: ")
    for _ in range(n):
        i,j = map(int, input().split())
        I.append((i,j))
    # print(I)
    # I = [(5, 10), (10,30), (15,20)]
    UnboundedKnapsack(I, int(input("Enter Total Cost: ")))
