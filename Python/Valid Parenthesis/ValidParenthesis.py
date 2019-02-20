

class Solution:
    def isValid(self, s: 'str') -> 'bool':
        
        validity = True
        
        storage = []
        
        for i in s:
            if i == ')':
                if not storage:
                    return False
                else:
                    if storage[-1] == '(':
                        del storage[-1]
                    else:
                        return False
            elif i == '}':
                if not storage:
                    return False
                else:
                    if storage[-1] == '{':
                        del storage[-1]
                    else:
                        return False
            elif i == ']':
                if not storage:
                    return False
                else:
                    if storage[-1] == '[':
                        del storage[-1]
                    else:
                        return False
            
            else:
                storage.append(i)
                
        if storage:
            return False
        
        return True
