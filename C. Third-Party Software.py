if __name__ == "__main__":

    N = int(input())


    functions = []

    for inter in range(N):
        a, b = list(map(int, input().split()))
        functions.append([a, b])

    functions.sort(key=lambda x: x[1])

    left = 0
    right = 1
    versions = []

    while (right < N):
        if (functions[left][1] >= functions[right][0]):
            right += 1

        else:
            versions.append(functions[left][1])
            left = right
            right += 1

    versions.append(functions[left][1])

    print(len(versions))

    for v in versions:
        print(v, end=" ")

    print()