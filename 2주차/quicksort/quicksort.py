#User function Template for python3

class Solution:
    #Function to sort a list using quick sort algorithm.
    def quickSort(self,arr,low,high):
        # code here
        if low < high:
            # partition 메서드를 호출하여 피벗의 위치를 얻음
            pivot_index = self.partition(arr, low, high)
            
            # 피벗을 기준으로 좌우 부분을 재귀적으로 정렬
            self.quickSort(arr, low, pivot_index - 1)
            self.quickSort(arr, pivot_index + 1, high)
            
    
    def partition(self,arr,low,high):
        # code here
        pivot = arr[low]  # 부분 리스트의 왼쪽 요소를 피벗으로 설정
        left = low + 1
        right = high

        # left가 right보다 작을 때만 반복
        while True:
            # left가 right보다 작고, arr[left]가 pivot보다 작거나 같은 동안 left 증가
            while left <= right and arr[left] <= pivot:
                left += 1
            
            # right가 left보다 크고, arr[right]가 pivot보다 큰 동안 right 감소
            while left <= right and arr[right] > pivot:
                right -= 1
            
            # 교환될 요소를 찾았다면 두 요소를 교환
            if left <= right:
                arr[left], arr[right] = arr[right], arr[left]
            else:
                break
        
        # 마지막으로 피벗 요소와 right가 가리키는 요소를 교환하여 피벗을 제자리로 이동
        arr[low], arr[right] = arr[right], arr[low]
        
        # 피벗이 위치한 인덱스를 반환
        return right
            
    


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for i in range(t):

        arr = list(map(int, input().split()))
        n = len(arr)
        Solution().quickSort(arr, 0, n - 1)
        for i in range(n):
            print(arr[i], end=" ")
        print()

# } Driver Code Ends