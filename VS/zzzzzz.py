import sys
from functools import cmp_to_key

def compare(x, y):
    return int(y + x) - int(x + y)

def largest_number(nums, k):
    nums = [str(x) for x in nums]
    nums.sort(key=cmp_to_key(compare))
    result = int(''.join(nums)) % k
    return result

def main():
    with open("test_data.txt", "r") as f:
        data = f.read().splitlines()
    
    index = 0
    results = []
    while index < len(data):
        a, k = map(int, data[index].split())
        index += 1
        result = 1
        for _ in range(a):
            n = int(data[index])
            nums = list(map(int, data[index + 1].split()))
            result = (result * largest_number(nums, k)) % k
            index += 2
        results.append(result)
    
    for res in results:
        print(res)

if __name__ == "__main__":
    main()