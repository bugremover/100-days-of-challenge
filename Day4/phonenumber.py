class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        
        # Create a dictionary mapping digits to letters
        phone_mapping = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        
        # Function to recursively generate combinations
        def backtrack(combination, next_digits):
            # If there are no more digits to check, append the combination
            if len(next_digits) == 0:
                output.append(combination)
            # Otherwise, iterate over all letters for the next digit and recurse
            else:
                for letter in phone_mapping[next_digits[0]]:
                    backtrack(combination + letter, next_digits[1:])
        
        output = []
        backtrack("", digits)
        return output
