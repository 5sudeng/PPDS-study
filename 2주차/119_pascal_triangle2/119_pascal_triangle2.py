from typing import List

class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ## basecase
        if rowIndex == 0: 
            return [1]
        elif rowIndex == 1:
            return [1, 1]

        else :
            beforeRow = self.getRow(rowIndex-1) # 재귀적으로 이전 row 결과값 불러오기
            answer = [1 for j in range(rowIndex+1)] # list를 모두 1로 채워둠. 맨 앞, 맨 뒤가 1이 되도록 하기 위함
            for i in range(1, rowIndex):
                answer[i] = beforeRow[i-1] + beforeRow[i] #이전 row의 i-1번째와 i번째를 더해서 현재 row의 i번째 값을 생성

        return answer

if __name__ == "__main__":
    rowIndex = int(input("Enter the row index: "))
    solution = Solution()
    result = solution.getRow(rowIndex)
    print(f"The {rowIndex}-th row of Pascal's triangle is: {result}")
