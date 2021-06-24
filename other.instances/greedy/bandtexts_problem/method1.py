

def RandomLengths(size):
    from random import randint
    result = []
    counter = 0
    while True:
        value = randint(0, 100)
        if value not in result:
            result.append(value)
            counter += 1
        if counter == size:
            return result



if __name__ == '__main__':

    # sorting with quicksort
    size = 20
    text_lengths = RandomLengths(size)
    print("Initial data:")
    print(text_lengths)

    import matplotlib.pyplot as plt
    plt.plot(text_lengths)
    plt.show()

    from andrew_packages.util.algorithms import Sorting
    sort = Sorting()
    sort.QuickSort(text_lengths)

    print("Sorted data:")
    print(text_lengths)

    plt.plot(text_lengths)
    plt.show()
