# 쉬운 방식
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 입력 문자열에서 알파벳과 숫자만 추출하고 소문자로 변환
        filtered = ''.join(char.lower() for char in s if char.isalnum())
        # 회문 여부 확인
        return filtered == filtered[::-1]

# 포인터
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 투 포인터 초기화
        left = 0
        right = len(s) - 1

        while left < right:
            # 왼쪽 포인터가 알파벳이나 숫자가 아닐 때 이동
            while left < right and not self.isAlphaNumeric(s[left]):
                left += 1
            # 오른쪽 포인터가 알파벳이나 숫자가 아닐 때 이동
            while left < right and not self.isAlphaNumeric(s[right]):
                right -= 1

            # 소문자로 변환 후 비교
            if self.toLower(s[left]) != self.toLower(s[right]):
                return False

            left += 1
            right -= 1

        return True

    # 알파벳이나 숫자인지 확인하는 함수
    def isAlphaNumeric(self, c: str) -> bool:
        return ('a' <= c <= 'z') or ('A' <= c <= 'Z') or ('0' <= c <= '9')

    # 대문자를 소문자로 변환하는 함수
    def toLower(self, c: str) -> str:
        if 'A' <= c <= 'Z':
            return chr(ord(c) + (ord('a') - ord('A')))  # 대문자를 소문자로 변환
        return c


# 테스트
solution = Solution()

# 테스트 케이스
print(solution.isPalindrome("A man, a plan, a canal: Panama"))  # True
print(solution.isPalindrome("racecar"))                        # True
print(solution.isPalindrome("hello"))
