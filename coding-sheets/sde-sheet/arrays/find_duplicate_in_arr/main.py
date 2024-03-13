"""
    Link - https://leetcode.com/problems/find-the-duplicate-number/description/
    Problem - Find the duplicate number in the array
    Difficulty - Medium
    Status - Solved
    Date - 31/1/2024

    Approach 1 - Cyclic sort (NOT AN ACTUAL NAMED ALGORITHM)
        1) the array is of n size and only consists of numbers 1 to n
        2) so a sorted array would look like arr[0] = 1, arr[1] = 2, arr[2] = 3,
        3) therefore, each element has a "correct index" for arr[i],
           correct_index = arr[i] - 1
        4) To find the duplicate we swap arr[i] with arr[correct_index]
        3) so if at any index arr[i] != i + 1, i.e element not at its "correct"
           index we swap it with its correct index but if arr[correct] == arr[i], we
           have a duplicate.

    Notes -
       1) Edge case - i and correct_index can be the same, in which case we shouldn't do anything
       2) Time complexity - O(n), Space complexity - O(1), single pass solution
       3) Drawbacks - Modifys the original Error, Big companies will look for a solution with Floyd's Algorithm
"""


def find_duplicate(arr):
    for i in range(0, len(arr)):
        correct_index = arr[i] - 1
        print(f"i {i}")
        print(f"correct index {correct_index}")
        if i != correct_index:
            if arr[i] != arr[correct_index]:
                swap(arr[i], arr[correct_index])
                print(f"arr[i] {arr[i]}")
                print(f"arr[correct_index] {arr[i]}")
            else:
                return i


arr = [1, 2, 3, 3, 4, 5]
res = find_duplicate(arr)
print(arr)
print(res)
