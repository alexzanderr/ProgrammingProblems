



class HumanObject:

    def __init__(self, weight, cost):
        self.weight = weight
        self.cost = cost

    def __str__(self):
        result = f"HumanObject for backpack with weight of: {self.weight} and cost of: {self.cost}"
        return result

if __name__ == '__main__':

    size = 20
    # generating random objects
    from random import randint
    backpack_objects = [HumanObject(randint(2, 15), randint(5, 20)) for _ in range(size)]
    for backobj in backpack_objects:
        print(backobj)

    cost_weight_raport = [(obj.cost / obj.weight) for obj in backpack_objects]
    print("Cost over weight raport:")
    print(cost_weight_raport)

    # sorting reverse
    cost_weight_raport = sorted(cost_weight_raport, reverse=True)
    print("Sorted reverse")
    print(cost_weight_raport)

    remaining_weight = 50
    solution = [0 for _ in range(len(backpack_objects))]
    for index, backpack_object in enumerate(backpack_objects):
        if backpack_object.weight <= remaining_weight:
            solution[index] = 1
            remaining_weight -= backpack_object.weight
        else:
            solution[index] = remaining_weight // backpack_object.weight
            for jndex in range(index + 1, len(backpack_objects)):
                solution[jndex] = 0

    print("Final solution:")
    print(tuple(solution))