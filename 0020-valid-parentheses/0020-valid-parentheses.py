class Solution:
    def isValid(self, s: str) -> bool:
        n=len(s)
        if n%2 !=0:
            return False
        stack = []
        hmap = { ")" : "(" , "}" : "{" , "]" : "[" }
        for p in s:
            if p in hmap:
                if stack and stack[-1]==hmap[p]:
                    stack.pop()
                else:
                    return False    
            else:
                stack.append(p)

        return True if not stack else False                  