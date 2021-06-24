
def PrintMatrixes(matrix1, matrix2):
    """ Cool visualization of two matrixes. """
    print(f"Initial matrix: \t Sums matrix:")
    for line1, line2 in zip(matrix1, matrix2):
        print(f"{line1}".ljust(25) + f"{line2}".ljust(25))
    print()

def TriangleMatrix(dimension):
    from random import randint
    return [[randint(1, 10) for _ in range(index + 1)] for index in range(dimension)]

def PrintMatrix(matrix):
    for line in matrix:
        print(line)
    print()

if __name__ == '__main__':
    dimension = 4
    initial_matrix = TriangleMatrix(dimension)
    #PrintMatrix(initial_matrix)

    sum_matrix = [[0 for _ in range(index + 1)] for index in range(dimension - 1)]
    sum_matrix.append(initial_matrix[dimension - 1])

    #PrintMatrix(sum_matrix)

    PrintMatrixes(initial_matrix, sum_matrix)

    for index in range(dimension - 2, -1, -1):
        for jndex in range(index + 1):
            sum_matrix[index][jndex] = \
                initial_matrix[index][jndex] + \
                max(sum_matrix[index + 1][jndex], sum_matrix[index + 1][jndex + 1])

    PrintMatrixes(initial_matrix, sum_matrix)

    # constructing the road
    road = [{initial_matrix[0][0]: (0, 0)}]
    start_column = 0
    for index in range(1, dimension):
        for jndex in range(start_column, index):
            if sum_matrix[index][jndex] > sum_matrix[index][jndex + 1]:
                road.append({initial_matrix[index][jndex]: (index, jndex)})
                break
            else:
                road.append({initial_matrix[index][jndex + 1]: (index, jndex + 1)})
                start_column += 1
                break

    PrintMatrixes(initial_matrix, sum_matrix)

    print("The road with maximum possible sum is:")
    for pair in road:
        value = list(pair.keys())[0]
        print(f"Element: {value} with coordinates: {pair[value]}")
