def solution(K, M, A):
    low = max(A)
    high = sum(A)

    while low != high:
        mid = (low+high)//2
        cnt = 1
        tmp = 0

        for x in A:
            if tmp+x > mid:
                cnt += 1
                tmp = x
            else:
                tmp += x
        
        if cnt > K:
            low = mid+1
        else:
            high = mid
            
    return low