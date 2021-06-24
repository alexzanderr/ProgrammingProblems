
if __name__ == '__main__':

    print("Banknotes problem:\n")

    banknotes_romania = [1, 5, 10, 50, 100, 200, 500]
    print(banknotes_romania, '\n')

    from random import randint
    price = randint(5, 1000)

    print(f"The price is: {price}\n")

    from collections import OrderedDict
    solution = OrderedDict()
    total_sum = 0
    done = False
    for banknote in banknotes_romania[::-1]:
        if total_sum + banknote == price:
            solution[banknote] = solution.get(banknote, 0) + 1
            break
        while total_sum + banknote < price:
            total_sum += banknote
            solution[banknote] = solution.get(banknote, 0) + 1
            if total_sum + banknote == price:
                solution[banknote] = solution.get(banknote, 0) + 1
                done = True
        if done:
            break

    print(f"For completing the sum of {price} lei we needed:")
    for banknote in solution:
        print(f"- {solution[banknote]} banknote of {banknote} lei.")

