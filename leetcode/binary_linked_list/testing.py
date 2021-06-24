
from leetcode.binary_linked_list.sol import Solution, ListNode

testcases = [
    {
        "input": [1,0,1],
        "output": 5
    },
    {
        "input": [0],
        "output": 0 
    },
    {
        "input": [1],
        "output": 1
    },
    {
        "input": [1,0,0,1,0,0,1,1,1,0,0,0,0,0,0],
        "output": 18880
    },
    {
        "input": [0,0],
        "output": 0
    }
]

def GenerateLinkedList(sequence: list):
    head = ListNode(sequence[0])
    temp_iter = head
    for item in sequence[1:]:
        temp_iter.next = ListNode(item)
        temp_iter = temp_iter.next
    return head

sol = Solution()
for index, testcase in enumerate(testcases, start=1):
    linked_list = GenerateLinkedList(testcase["input"])
    result = sol.getDecimalValue(linked_list)
    
    if result == testcase["output"]:
        message = "passed"
    else:
        message = "failed"
    print("[ {} ]. {} -- {} -> {}".format(index, message, testcase['input'], result))