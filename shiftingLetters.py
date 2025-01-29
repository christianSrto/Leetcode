#You are given a string s of lowercase English letters and a 2D integer array shifts where shifts[i] = [starti, endi, directioni]. For every i, shift the characters in s from the index starti to the index endi (inclusive) forward if directioni = 1, or shift the characters backward if directioni = 0.
#Shifting a character forward means replacing it with the next letter in the alphabet (wrapping around so that 'z' becomes 'a'). Similarly, shifting a character backward means replacing it with the previous letter in the alphabet (wrapping around so that 'a' becomes 'z').
#Return the final string after all such shifts to s are applied.

class Solution:
    def shiftingLetters(self, s: str, shifts: list[list[int]]) -> str:
        n = len(s)
        diff_array = [
            0
        ] * n 

        for shift in shifts:
            if shift[2] == 1:  
                diff_array[shift[0]] += 1  
                if shift[1] + 1 < n:
                    diff_array[
                        shift[1] + 1
                    ] -= 1  
            else:  
                diff_array[shift[0]] -= 1  
                if shift[1] + 1 < n:
                    diff_array[
                        shift[1] + 1
                    ] += 1  
        result = list(s)
        number_of_shifts = 0

        for i in range(n):
            number_of_shifts = (
                number_of_shifts + diff_array[i]
            ) % 26  
            if number_of_shifts < 0:
                number_of_shifts += 26 

           
            shifted_char = chr(
                (ord(s[i]) - ord("a") + number_of_shifts) % 26 + ord("a")
            )
            result[i] = shifted_char

        return "".join(result)