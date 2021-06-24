

if __name__ == '__main__':

    data = [6, 1, 2, 4, 5, 6, 2, 67, 234]

    print("Initial data:")
    print(data)
    # circular permutation to left
    data.append(data[0])
    data = data[1:]

    print(data)

    from andrew_packages.programming_problems.\
        greedy.subset_with_max_sum import *

    solution = set()
    for index in range(len(data)):
        union = solution.union({data[index]})
        if PropertyFunction(union) == 1:
            solution = union

    print("The solution is:")
    print(solution) # incorrect, but its teacher's solution