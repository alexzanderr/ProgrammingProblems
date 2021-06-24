class Solution:
    def reverseWords(self, s: str):
        words = s.strip().split()
        if words == []:
            return ""
        return " ".join(reversed(words))
        
if __name__ == '__main__':
    testcases = [
        "  hello world!  ",
        "a good   example",
        "",
        "                    ",
        "the sky is blue"
    ]
    
    s = Solution()
    for t in testcases:
        print(s.reverseWords(t))