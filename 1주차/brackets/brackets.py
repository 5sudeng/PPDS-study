def solution(S):
    # bracket 페어 맞춰서 딕셔너리에 저장
    matching_brackets = {')': '(', ']': '[', '}': '{'}
    # 현재 열려있는 bracket이 뭔지 저장하고 트래킹하기 위한 스택
    stack = []
    
    for char in S:
        if char in "([{":  # opening bracket 이면
            stack.append(char) # 스택에 저장 (= 얘랑 매칭될 bracket 찾겠다)
        elif char in ")]}":  # closing bracket 이면
            # 스택 속에 있는 bracket 과의 매칭 여부 확인
            if not stack or stack[-1] != matching_brackets[char]: # 스택에 없거나, (bracket 여럿 열린 상태라면) 가장 마지막에 열린 bracket 아니라면
                return 0 # 매칭 X -> 0 반환
            stack.pop() # 매칭 O(= 짝 찾음) -> 더이상 스택에 저장돼있을 필요 없으니 pop
    # 스택이 비었으면 다 잘 매칭되었다는 뜻이므로 1, 아니면 0 반환
    return 1 if not stack else 0
