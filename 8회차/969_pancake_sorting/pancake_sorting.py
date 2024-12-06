class Solution:
    def pancakeSort(self, arr: List[int]) -> List[int]:
        result = []
        n = len(arr)

        # 현재 범위를 줄여가며 반복
        for currentSize in range(n, 1, -1):
            # 1. 현재 범위에서 가장 큰 값의 인덱스 찾기
            maxIndex = arr.index(max(arr[:currentSize]))

            # 2. 가장 큰 값이 이미 제자리에 있으면 건너뜀
            if maxIndex == currentSize - 1:
                continue

            # 3. 가장 큰 값을 맨 앞으로 뒤집음
            if maxIndex != 0:
                result.append(maxIndex + 1)
                arr[:maxIndex + 1] = reversed(arr[:maxIndex + 1])

            # 4. 가장 큰 값을 현재 범위의 끝으로 이동
            result.append(currentSize)
            arr[:currentSize] = reversed(arr[:currentSize])

        return result