
from andrew_packages.util.algorithms import RandomSet
first_positives = RandomSet(5, positives=True)
first_negatives = RandomSet(5, positives=False)
first_both = RandomSet(5, both=True)

second = RandomSet(7, positives=True)

# given this

# find the maximum value of this:
# E = a0 * x0 + a1 * x1 + ... + a(len(A) - 1) * x(len(A) - 1)