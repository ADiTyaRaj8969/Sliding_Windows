# Topic: Permutation in String (check if s2 contains permutation of s1)

from collections import Counter

def check_inclusion(s1, s2):
    if len(s1) > len(s2): return False
    cnt1 = [0]*26
    cnt2 = [0]*26
    for i in range(len(s1)):
        cnt1[ord(s1[i]) - ord('a')] += 1
        cnt2[ord(s2[i]) - ord('a')] += 1
    if cnt1 == cnt2: return True
    for i in range(len(s1), len(s2)):
        cnt2[ord(s2[i]) - ord('a')] += 1
        cnt2[ord(s2[i-len(s1)]) - ord('a')] -= 1
        if cnt1 == cnt2: return True
    return False

if __name__ == '__main__':
    s1 = 'ab'
    s2 = 'eidbaooo'
    print('Yes' if check_inclusion(s1,s2) else 'No')

# Time Complexity: O(n)
# Space Complexity: O(1)
