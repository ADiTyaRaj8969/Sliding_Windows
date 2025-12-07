# Topic: Minimum Window Substring (find smallest window containing all chars of pattern)

from collections import Counter

def min_window(s, t):
    if not t: return ""
    need = Counter(t)
    required = len(t)
    left = 0
    min_len = float('inf')
    start = 0
    for right, ch in enumerate(s):
        if need[ch] > 0:
            required -= 1
        need[ch] -= 1
        while required == 0:
            if right-left+1 < min_len:
                min_len = right-left+1
                start = left
            need[s[left]] += 1
            if need[s[left]] > 0:
                required += 1
            left += 1
    return "" if min_len == float('inf') else s[start:start+min_len]

if __name__ == '__main__':
    s = "ADOBECODEBANC"
    t = "ABC"
    print('MinWindow:', min_window(s,t))

# Time Complexity: O(n)
# Space Complexity: O(1) (alphabet-limited counter)
