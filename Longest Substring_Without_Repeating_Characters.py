 #-*- coding:utf-8 -*-
# 3. Longest Substring Without Repeating Characters
# Given a string, find the length of the longest substring without repeating characters.

# Examples:

# Given "abcabcbb", the answer is "abc", which the length is 3.

# Given "bbbbb", the answer is "b", with the length of 1.

# Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        hmap = {}
        n = len(s) - 1 
        max_len = 1
        l = {}
        #hmap[n] = {s[n]:n}
        hmap[s[n]] = n
        l[n] = 1
        #l[x] max len start with pos x.
        for i in xrange(n-1,-1,-1):
            a = s[i]
            if a not in hmap or hmap[a]>=i+1+l[i+1]: #s[i+1:i+1+l[i+1]]
                l[i] = l[i+1] + 1
                hmap[a] = i
            else:
                pos = hmap[a]
                l[i] = pos - i
                hmap[a] = i

            if max_len < l[i]:
                max_len = l[i]
        return max_len


if __name__ == '__main__':
    sol = Solution()
    print sol.lengthOfLongestSubstring('abcabcbb')
    print sol.lengthOfLongestSubstring('aaaaa')
    print sol.lengthOfLongestSubstring('')
    print sol.lengthOfLongestSubstring('a')

