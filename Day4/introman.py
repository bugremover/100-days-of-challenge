class Solution:
    def intToRoman(self, num: int) -> str:
        # Create mappings for integer values to Roman numeral symbols
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        symbols = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

        result = ""
        # Iterate through the mappings
        for i in range(len(values)):
            # Repeat the symbol as many times as possible
            while num >= values[i]:
                result += symbols[i]
                num -= values[i]
        return result
