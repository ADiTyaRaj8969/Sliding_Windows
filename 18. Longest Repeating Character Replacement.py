# Topic: Longest Repeating Character Replacement

from collections import defaultdict

def character_replacement(s, k):
    count = [0]*26
    left = 0
    maxf = 0
    res = 0
    for right, ch in enumerate(s):
        idx = ord(ch) - ord('A')
        count[idx] += 1
        maxf = max(maxf, count[idx])
        while (right - left + 1 - maxf) > k:
            count[ord(s[left]) - ord('A')] -= 1
            left += 1
        res = max(res, right-left+1)
    return res

if __name__ == '__main__':
    s = "AABABBA"
    k = 1
    print('Longest after replacement:', character_replacement(s,k))

# Time Complexity: O(n)
# Space Complexity: O(1)
