if __name__ == "__main__":

    N, M = list(map(int, input().split()))

    functions = []

    for inter in range(N):
        a, b = list(map(int, input().split()))
        functions.append([a, b, inter + 1])

    functions.sort(key=lambda x: (x[0], -x[1]))

    left = 0
    right = 1
    versions = []

    left_range = 1

    if (functions[0][0] > left_range):
        print("NO")
        exit()    

    while (right < N):

        if (left_range >= functions[right][0] and functions[left][1] < functions[right][1]):
            left = right
            right += 1
            
        elif (functions[left][1] >= functions[right][1]):
            right += 1

        else:
            versions.append(functions[left][2])
            left_range = functions[left][1] + 1
            left = right
            right += 1

            if (functions[left][0] > left_range):
                print("NO")
                exit()    

    if (left_range <= M):
        versions.append(functions[left][2])

    if (functions[left][1] != M):
        print("NO")
        exit()
        
    print("YES")

    print(len(versions))

    for v in versions:
        print(v, end=" ")

    print()

    exit()