class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.min_stack = [] 
        
    def push(self, x: int):
        if self.min_stack == []:
            self.min_stack.append(x)
        else:
            if x < self.min_stack[len(self.min_stack) - 1]:
                self.min_stack.append(x)
            else:
                self.min_stack.append(self.min_stack[len(self.min_stack) - 1])
        self.stack.append(x)

    def pop(self):
        if self.stack != []:
            self.stack.pop()
            self.min_stack.pop()

    def top(self):
        if self.stack != []:
            return self.stack[len(self.stack) - 1]

    def getMin(self):
        return self.min_stack[len(self.min_stack) - 1]





# minimum = stack[0]
# for elem in stack[1:]:
#     minimum = elem if elem < minimum else minimum
# return minimum

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()


"""
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]
"""
# line1 = ["MinStack","push","push","push","getMin","pop","top","getMin"]
# line2 = [[],[-2],[0],[-3],[],[],[],[]]


# stack = None
# actions = []
# for l1, l2 in zip(line1, line2):
#     if l1 == "MinStack":
#         stack = MinStack()
#     elif l1 == "push":
#         stack.push(l2[0])
#     elif l1 == "pop":
#         stack.pop()
#     elif l1 == "top":
#         stack.top()
#     elif l1 == "getMin":
#         stack.getMin()
