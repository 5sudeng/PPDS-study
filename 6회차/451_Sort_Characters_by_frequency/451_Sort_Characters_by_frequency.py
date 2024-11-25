'''
Hash, string, sorting, heap(priority queue), bucket sort, counting


Given a string s, sort it in decreasing order based on the frequency of the characters.
If there are multiple answers, return any of them.

접근 방식
- frequency hash map 만들어서 sorting
- C++ 일 경우, priority queue(max heap으로 만들어서 사용)
- 대소문자 구별

'''



class Solution:
    def frequencySort(self, s: str) -> str:
        
        hash = {}
        for i in range(len(s)):
            
            if s[i] not in hash:
                hash[s[i]] = s.count(s[i])
        
        #sorting hash decreasing order
        temp = sorted([(character, count) for character, count in hash.items()],key = lambda x:x[1], reverse = True)

        #get answer string
        ans =""
        for a, b in temp:
            ans+= a*b

        return ans

def main():
    s = 'Aabb'
    sol = Solution()
    print(sol.frequencySort(s))

    

if __name__ == "__main__":
    main()

