from itertools import combinations

def solution(num_buns, num_required):
    # Your code here
    buns = [[] for i in range(num_buns)]
    #print(buns)
    if num_required == 0:
        return buns
    k = 0
    for c in combinations(buns, num_buns - num_required + 1):
        print(buns)
        #print(c)
        for i in c:
            i.append(k)
        #print(i)
        #print("-------------------")
        k = k + 1
    print(buns)

solution(5, 3)
        