


if __name__ == '__main__':
    hours_intervals = [[8,11], [9,12], [10, 12], [12, 14], [13, 15], [16, 18], [18,20]]
    hours_intervals = list(map(tuple, hours_intervals))
    print("Initial hours intervals:")
    print(hours_intervals)

    # sorting accordingly
    hours_intervals = sorted(hours_intervals, key=lambda interval: interval[1])
    print("Sorted after the finish hour:")
    print(hours_intervals)


    end = hours_intervals[0][1]
    solution = [(hours_intervals[0][0], end)]
    for iterval in hours_intervals[1:]:
        if iterval[0] >= end:
            solution.append((iterval[0], iterval[1]))
            end = iterval[1]

    print(f"\nOptimal spectacles to participate are: \n{solution}")




