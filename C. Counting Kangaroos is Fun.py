if __name__ == "__main__":

    N = int(input())

    kangoroos = []

    for i in range(N):
        k = int(input())
        kangoroos.append(k)

    kangoroos.sort(reverse=True)

    holding = 0
    held = 1

    while (held < N):

        if (kangoroos[holding] >= kangoroos[held] * 2):
            holding += 1
            held = max(held + 1,  (holding + 1) * 2 - 1) 
            
            
        else:
            held += 1

    print(N - holding)