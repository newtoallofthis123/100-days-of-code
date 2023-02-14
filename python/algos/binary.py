# Binary Search in python
# Path: python\algos\binary.py
# Basic Version
# This is basic version of binary search
# Author: NoobScience

# <START>

# Recursive Version
def basic_binary(vars, first, second, target):
    if second >= first:
        # Define Middle Value and Index
        mid = (first + second) // 2
        # Check if middle value is target
        if vars[mid] == target:
            return mid
        # Check if middle value is greater than target
        elif vars[mid] > target:
            return basic_binary(vars, first, mid - 1, target)
        # Check if middle value is less than target
        else:
            return basic_binary(vars, mid + 1, second, target)
    else:
        return -1
    
# Non Recursive Version
def binary_non_recursive(arr, target):
    low = 0
    high = len(arr) - 1
    mid = 0
    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < target:
            low = mid + 1
        elif arr[mid] > target:
            high = mid - 1
        else:
            return mid
    return -1

def binary_search(arr, target):
    return basic_binary(sorted(arr), 0, len(arr), target)

# Examples

# Do you know you can also use binary search to search for a string in a list?

print(binary_search([1, 2, 3, 4, 5, 6, 7, 8, 9], 5))
print(binary_search([12, 14, 1, 15, 2, 45, 12], 15))
print(binary_search(["Hello", "World", "This", "Is", "A", "Test"], "Test"))

# <END>