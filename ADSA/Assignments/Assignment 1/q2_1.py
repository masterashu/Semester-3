# Algorithm:
# We check for each distint pair 
# if they both share common screen time
# We see if a.entry < b.exit and b.entry < a.exit

# Reading input No. of users
n = int(input())

# Read entry and exit time of users
times = [tuple(map(int, input().split())) for i in range(n)]

count = 0

for i in range(len(times)):
    for j in range(i+1, len(times)):
        if (times[i][0] < times[j][1] and times[j][0] < times[i][1]):
            count += 1

print("Possible distinct pairs are ", count)




