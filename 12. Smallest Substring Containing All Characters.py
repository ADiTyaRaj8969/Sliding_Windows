"""
Smallest Substring Containing All Characters of Another String
"""
from collections import Counter

def min_window(s, t):
    need = Counter(t)
    missing = len(t)
    left = start = 0
    minlen = float('inf')
    for right, ch in enumerate(s):
        if need[ch] > 0: missing -= 1
        need[ch] -= 1
        while missing == 0:
            if right-left+1 < minlen:
                minlen = right-left+1; start = left
            need[s[left]] += 1
            if need[s[left]] > 0: missing += 1
            left += 1
    return '' if minlen==float('inf') else s[start:start+minlen]

def main():
    print(min_window('ADOBECODEBANC','ABC'))

if __name__ == '__main__':
    main()

# Time Complexity: O(n)
# Space Complexity: O(1)
