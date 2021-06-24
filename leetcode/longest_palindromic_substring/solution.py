
class Solution:
    def longestPalindrome(self, s: str):
        if len(s) == 1 or s == "" or self.isPalindrome(s) or s == None:
            return s
            
        solutions = []
        for start in range(len(s)):
            for stop in range(start + 1, len(s) + 1):
                s_cut = s[start : stop]
                if self.isPalindrome(s_cut):
                    solutions.append(s_cut)
                    
        max_length = max(map(len, solutions))
        for sol in solutions:
            if len(sol) == max_length:
                return sol
                
    def isPalindrome(self, string):
        return string == string[::-1]