# From leetCode:
# Given two strings return true if first string can be constructed by using the letters from the other.
class Solution:
    def canConstruct(ransomNote, magazine) -> bool:
        length = len(ransomNote)

        if len(ransomNote) < 1 or len(magazine) >= 10**5:
            raise Exception("bad lengths")

        for i in magazine:
            j = 0
            while(j < length):
                if i == ransomNote[j]:
                    if length == 1:
                        return True
                    else:
                        print(ransomNote[j])
                        ransomNote = ransomNote[:j] + ransomNote[j + 1:]
                        length -= 1
                        break
                j += 1
        return False

def main():
    sol = Solution
    ransomNote = "alabama"
    magazine = "amabala"

    print(sol.canConstruct(ransomNote, magazine))

if __name__ == "__main__":
    main()