class Solution:
    def intToRoman(self, num: int) -> str:
        '''
        hash function
        integer to string
        '''

        ans =""
        hash_table = {
            1: "I", 4 :"IV", 5:"V", 9:"IX", 10 : "X",
            40:"XL", 50 :"L", 90:"XC", 100: "C",
            400 :"CD", 500:"D", 900 : "CM", 1000 : "M"
        }
        for key in sorted(list(hash_table.keys()), reverse = True): # 내림차순.
            while(num>= key):
                ans += hash_table[key]
                num -= key

        return ans