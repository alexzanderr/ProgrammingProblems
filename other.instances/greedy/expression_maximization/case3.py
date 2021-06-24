
if __name__ == '__main__':
    # case 3 ->> both

    from andrew_packages.programming_problems.greedy.\
        expression_maximization.__init__ import first_both, second

    print("First set:")
    print(first_both)
    print("Second set:")
    print(second)
    from andrew_packages.util.algorithms import GenerateSubsets
    subsets_second_set = GenerateSubsets(second)
    subsets_second_set = list(filter(lambda sett: len(sett) == len(first_both), subsets_second_set))
    print("Subsets of second set:")
    print(subsets_second_set)

    expression = 0
    for elem_first, elem_subset in zip(list(first_both), list(subsets_second_set[0])):
        expression += elem_first * elem_subset
    maximum_sum = expression
    solution = subsets_second_set[0]

    for subset in subsets_second_set[1:]:
        expression = 0
        for element_first, element_subset in zip(list(first_both), list(subset)):
            expression += element_first * element_subset
        if expression >= maximum_sum:
            maximum_sum = expression
            solution = subset

    print(f"\nMaximum sum is: {maximum_sum} and the subset that contributed is: {solution}")