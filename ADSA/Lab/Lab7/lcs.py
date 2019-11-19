def lcs(a, b):
    n, m = len(a), len(b)
    mat = [[0]*(m+1) for _ in range(n+1)]
    # print(mat)
    for i in range(n):
        for j in range(m):
            if a[i] == b[j]:
                mat[i+1][j+1] = 1 + mat[i][j]
            else:
                mat[i+1][j+1] = max(mat[i][j+1], mat[i+1][j])
    
    print("Max Length of Subsequence:", mat[-1][-1])
    # print('\n'.join(list(map(lambda x: ' '.join(map(str,x)), mat))))
    i,j = n,m
    LCS = []
   
    # if mat[-1][-1] is not 0:
    #     while i > 0 and j > 0:
    #         if mat[i-1][j] == mat[i][j]:
    #             i-=1
    #         elif mat[i][j-1] == mat[i][j-1]:
    #             j-=1
    #         elif mat[i-1][j-1] < mat[i][j]:
    #             LCS.append(a[j-1])
    #             i,j= i-1,j-1
    #     ans = ''.join(LCS)
    #     print(ans)
    



if __name__ == "__main__":
    a = input("Enter first String: ")
    b = input("Enter second String: ")
    lcs(a, b)
