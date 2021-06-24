
class PizzaType:

    def __init__(self, type, slices):
        self.type = type
        self.slices = slices

    def __str__(self):
        result = f"Pizza type of: {self.type} with total slices of: {self.slices}"
        return result

def PrintOurData(N, M, array):
    print(f"Number of total slices are: {N}")
    print(f"Number of pizza types are: {M}")
    print("Input data is:\n")
    for pizza in type_slice_array:
        print(pizza)

def SolveProblem(file_path):
    with open(file_path, 'r+', encoding='utf-8') as input_file:
        line = input_file.readline()
        total_slices, total_types = map(int, line.split())
        line = input_file.readline()
        type_slice_array = [PizzaType(index, slices) for index, slices in enumerate(list(map(int, line.split())))]

    """
        print(total_slices)
        for objectt in type_slice_array[::-1]:
            print(objectt.slices, end=" ")
        print()

    """

    # expectations: trebuie sa comandam pizza a.index. numarul de felii comandate sa fie <= total_slices
    # exact ca problema rucsacului
    # actual solution:

    slices_sum = 0
    solution = []
    # o luam de la capat sa nu mai sortam ca dureaza
    for index in range(len(type_slice_array) - 1, -1, -1):
        if type_slice_array[index].slices + slices_sum < total_slices:
            slices_sum += type_slice_array[index].slices
            solution.append(type_slice_array[index])
        elif type_slice_array[index].slices + slices_sum == total_slices:
            slices_sum += type_slice_array[index].slices
            solution.append(type_slice_array[index])
            break
        else:
            continue

    # numarul de felii
    print(f"Output slices: {len(solution)}")
    # feliile sortate dupa tip
    sorted_types = sorted([pizza.type for pizza in solution])
    print(f"ordering pizza: {sorted_types}")
    # scor total pe problema
    total_score = sum([pizza.slices for pizza in solution])
    print(f"Total score is: {total_score}")

if __name__ == '__main__':
    path = "D:\\__Alexzander_files__\\computer_science\\python_stuff\\andrew_packages\\programming_problems\\hashcode_event\\input_data\\"
    file_names = ['a.in', 'b.in', 'c.in', 'd.in', 'e.in']
    from time import sleep
    for name in file_names:
        absolute_path = path + name
        SolveProblem(absolute_path)
        sleep(1)
        print('------------------------')






