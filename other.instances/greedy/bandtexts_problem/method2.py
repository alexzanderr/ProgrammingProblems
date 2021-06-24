



if __name__ == '__main__':

    from andrew_packages.programming_problems.greedy.bandtexts_problem.method1 import RandomLengths
    size = 20
    text_lengths = RandomLengths(size)
    print("Initial data:")
    print(text_lengths)

    import matplotlib.pyplot as plt

    plt.plot(text_lengths)
    plt.show()

    # generating opposite waves
    wave1 = [text_lengths[index] for index in range(0, len(text_lengths), 2)]
    wave2 = [text_lengths[index] for index in range(1, len(text_lengths), 2)]

    from andrew_packages.util.algorithms import Sorting
    sort = Sorting()
    sort.QuickSort(wave1)
    sort.QuickSort(wave2, reverse=True)

    solution = []
    for item_ascending, item_descending in zip(wave1, wave2):
        solution.append(item_ascending)
        solution.append(item_descending)

    print("Optimal order for texts is:")
    print(solution)