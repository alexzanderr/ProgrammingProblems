
def PropertyFunction(sett):
    if sett == set():
        return 1
    else:
        from random import choice
        from andrew_packages.util.algorithms import GenerateSubsets
        return PropertyFunction(set(choice(GenerateSubsets(sett))))

if __name__ == '__main__':

    # sub set with max sum
    from andrew_packages.util.algorithms import *
    sett = RandomSet(5)
    print("Initial set:")
    print(sett)

    # method 1 wtf makes no sense
    print("method 1 wtf makes no sense")
    solution1 = set()
    for _ in range(len(sett)):
        x = RandomItemFromSet(sett)
        sett.discard(x)
        union1 = solution1.union({x})
        if PropertyFunction(union1) == 1:
            print(solution1)
            solution1 = union1

    print("Final solution is:")
    print(solution1)


    # method 2 andrew's method
    sett = RandomSet(5)
    print("\n\nInitial set:")
    print(sett)
    print("method 2 andrew's method")
    subsets_of_sett = GenerateSubsets(sett)
    subsets_of_sett.remove(sett)

    print(f"Subsets of length {len(sett) - 1} of sett:")
    print(subsets_of_sett)

    maximum_sum = 0
    solution2 = set()
    for subset in subsets_of_sett:
        if sum(subset) >= maximum_sum:
            maximum_sum = sum(subset)
            solution2 = subset

    print(f"The subset of {sett} with maximum sum of {maximum_sum} is {solution2}")

