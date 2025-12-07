# Topic: Fruit Into Baskets (longest subarray with at most two distinct types)

from collections import defaultdict

def total_fruit(fruits):
    cnt = defaultdict(int)
    left = 0
    res = 0
    for right, f in enumerate(fruits):
        cnt[f] += 1
        while len(cnt) > 2:
            cnt[fruits[left]] -= 1
            if cnt[fruits[left]] == 0:
                del cnt[fruits[left]]
            left += 1
        res = max(res, right-left+1)
    return res

if __name__ == '__main__':
    fruits = [1,2,1]
    print('Max fruits:', total_fruit(fruits))

# Time Complexity: O(n)
# Space Complexity: O(1) (bounded by 2 types)
