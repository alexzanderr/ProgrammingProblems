


if __name__ == '__main__':

    # case1 -> only positives

    from andrew_packages.programming_problems.greedy.\
        expression_maximization.__init__ import first_positives, second

    print("First set:")
    print(first_positives)
    print("Second set:")
    print(second)
    from andrew_packages.util.algorithms import GenerateSubsets
    subsets_second_set = GenerateSubsets(second)
    subsets_second_set = list(filter(lambda sett: len(sett) == len(first_positives), subsets_second_set))
    print("Subsets of second set:")
    print(subsets_second_set)

    maximum_sum = 0
    solution = set()

    for subset in subsets_second_set:
        expression = 0
        for element_first, element_subset in zip(list(first_positives), list(subset)):
            expression += element_first * element_subset
        if expression >= maximum_sum:
            maximum_sum = expression
            solution = subset

    print(f"\nMaximum sum is: {maximum_sum} and the subset that contributed is: {solution}")