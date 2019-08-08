# Algorithm:
# We maintain two indexes i.e. starting and ending 
# indexes for the total no. of users we have at a 
# certain point in time
# 

# Reading input No. of users
n = int(input())

# Read entry and exit time of users
times = [tuple(map(int, input().split())) for i in range(n)]

count = 0
i,j = 0,1
current = 0

for (a, b) in times:
    pass


print("Possible distinct pairs are ", count)




