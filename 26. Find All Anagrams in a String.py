# Topic: Find All Anagrams in a String

def find_anagrams(s, p):
    res = []
    if len(p) > len(s): return res
    cnt1 = [0]*26
    cnt2 = [0]*26
    for i in range(len(p)):
        cnt1[ord(s[i]) - ord('a')] += 1
        cnt2[ord(p[i]) - ord('a')] += 1
    if cnt1 == cnt2:
        res.append(0)
    for i in range(len(p), len(s)):
        cnt1[ord(s[i]) - ord('a')] += 1
        cnt1[ord(s[i-len(p)]) - ord('a')] -= 1
        if cnt1 == cnt2:
            res.append(i-len(p)+1)
    return res

if __name__ == '__main__':
    s = 'cbaebabacd'
    p = 'abc'
    print('Indices:', find_anagrams(s,p))

# Time Complexity: O(n)
# Space Complexity: O(1)
