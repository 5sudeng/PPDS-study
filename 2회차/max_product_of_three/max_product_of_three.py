def solution(A):
    A.sort() # array A 안의 elements 줄 세우기
    
    # 세 숫자의 곱이 max 가 될 수 있는(될 가능성이 있는) 2가지 경우 (note. A 의 원소는 모두 정수)
    # 1. 양수 3개의 곱: 정렬된 array A 에서, 맨 뒤 세 숫자(= largest three)를 곱한다
    # 2. 음수 2개, 양수 1개의 곱: 정렬된 array A 에서, 맨 앞 2개, 맨 뒤 하나를 곱한다
    max_product_1 = A[-1] * A[-2] * A[-3]
    max_product_2 = A[0] * A[1] * A[-1]
    
    if A[0] >= 0: # array A 의 첫 번째 원소가 0이거나 0보다 클 경우, 맨 뒤 3개 숫자를 곱하는 것이 최댓값
        return max_product_1
    elif A[1] < 0: # array A 의 두 번째 원소가 음수인 경우(자연스레 첫 번째 원소도 음수라는 뜻)
        return max(max_product_1, max_product_2) 
    else: # array A 의 두 번째 원소가 양수인 경우(자연스레 array A 에서 음수인 원소는 첫 번째 원소 only)
        return max_product_1