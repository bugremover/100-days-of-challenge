class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) == 0:
            return ""
        
        # Function to expand around the center and find the longest palindrome
        def expandAroundCenter(left: int, right: int) -> str:
            while left >= 0 and right < len(s) and s[left] == s[right]:
                left -= 1
                right += 1
            # Return the palindrome substring, not including left and right since the loop expands one step too far
            return s[left+1:right]
        
        longest = ""
        for i in range(len(s)):
            # Odd length palindrome
            tmp = expandAroundCenter(i, i)
            if len(tmp) > len(longest):
                longest = tmp
            
            # Even length palindrome
            tmp = expandAroundCenter(i, i+1)
            if len(tmp) > len(longest):
                longest = tmp
        
        return longest