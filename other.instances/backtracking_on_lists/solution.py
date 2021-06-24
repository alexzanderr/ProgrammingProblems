

# THE FAST SOLUTION AND MODERN ONE

# from itertools import combinations

# number = 10
# lister = [1, 4, 5, 6, 1, 1, 2, 3]
# solution = []

# comb = []
# for i in range(1, len(lister)):
#     items = list(combinations(lister, i))
#     for it in items:
#         comb.append(it)
        
# # for c in comb:
# #     print(c)
    
# for c in comb:
#     if sum(c) == number:
#         solution.append(c)
        
# for s in solution:
#     print(s)    







# THE CLASSIC SOLUTION
# def CombinationsFromNumber(dim, k):
#     """ 
#         this is old method of using 
#         backtracking for generating all
#         combiations
        
#         returns a list with all combinations
#     """
#     dim = 10
#     k = 2
#     pos = 0
#     sol = [0] * dim # [0, 0, 0, 0, 0, 0, 0, 0, 0]
#     solutions = []
    
#     def Init():
#         if pos == 0:
#             sol[0] = 0
#         else:
#             sol[pos] = sol[pos - 1]

#     def Succesor():
#         if sol[pos] < dim:
#             sol[pos] += 1
#             return True
#         return False
        
#     def Valid():
#         for i in range(pos):
#             if sol[i] == sol[pos]:
#                 return False
#         return True    

#     while pos > - 1:
#         succ = Succesor()
#         while succ and not Valid():
#             succ = Succesor()
#         if succ:
#             if k - 1 == pos:
#                 # print(sol[:k])
#                 solutions.append(sol[:k])
#             else:
#                 pos += 1
#                 Init()
#         else:
#             pos -= 1
#     return solutions    
    
    
def CombinationsFromList(original_list, k):
    """ 
        this is old method of using 
        backtracking for generating all
        combiations
        
        returns a list with all combinations 
        made on the original list
    """
    dim = len(original_list)
    pos = 0
    sol = [0] * k
    solutions = []
    
    def Init():
        if pos == 0:
            sol[0] = 0
        else:
            sol[pos] = sol[pos - 1]

    def Succesor():
        if sol[pos] < dim:
            sol[pos] += 1
            return True
        return False
        
    def Valid():
        for i in range(pos):
            if sol[i] == sol[pos]:
                return False
        return True    

    while pos > - 1:
        succ = Succesor()
        while succ and not Valid():
            succ = Succesor()
        if succ:
            if k - 1 == pos:
                # print(sol[:k])
                # aici trebuie sa printam
                # print("[ ", end="")
                # for i in range(k):
                #     print(original_list[sol[i] - 1], end=" ")
                # print("]")    
                
                new_sol = []
                for i in range(k):          
                    new_sol.append(original_list[sol[i] - 1])      
                solutions.append(new_sol)
            else:
                pos += 1
                Init()
        else:
            pos -= 1
    return solutions    
    
from itertools import combinations
    
example = [1, 4, 5, 6, 1, 1, 2, 3]
number = 10 

combs = list()
for i in range(2, len(example) + 1):
    comb = CombinationsFromList(example, i)
    # print(combs)
    combs.append(comb)

solutions = []
for comb in combs:
    for c in comb:
        if sum(c) == number:
            solutions.append(c)


for sol in solutions:
    print(sol)


# result2 = list(combinations(lister, 4))
    
    
# """
# 1 2 3
# 1 3 2
# 2 1 3
# 2 3 1
# 3 1 2
# 3 2 1
# """

# dim = 3
# sol = [0] * dim 
# pos = 0

# def Succesor():
#     if sol[pos] < dim:
#         sol[pos] += 1
#         return True
#     return False
    
# def Valid():
#     for i in range(pos):
#         if sol[i] == sol[pos]:
#             return False
#     return True    
       
# while pos > -1:
#     succ = Succesor()
#     while succ and not Valid():
#         succ = Succesor()
#     if succ:
#         if dim - 1 == pos:
#             print(sol)
#         else:
#             pos += 1
#             sol[pos] = 0
#     else:
#         pos -= 1