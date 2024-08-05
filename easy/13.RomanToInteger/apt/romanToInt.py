

class Solution(object):
    def romanToInt(self, s):
        check = {
            "I": 1,
            "V": 5,
            "X": 10,
            "L": 50,
            "C": 100,
            "D": 500,
            "M": 1000
        }
        number = 0
        for i in range (0, len(s)):
            current = check.get(s[i])

            next_value = check.get(s[i+1]) if i < len(s) - 1 else 0

            if current < next_value:
                number -= current
            else:
                number += current

        return number
        