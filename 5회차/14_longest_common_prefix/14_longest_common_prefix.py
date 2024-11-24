def longest_common_prefix(strs): # input: list of words
    if not strs: # 아무것도 없을 때
        return "" # 빈 string return
    
    # 일단 첫번째 단어를 (통으로) prefix 로 지정
    prefix = strs[0]
    
    # prefix와, 나머지 단어들 순서대로 하나씩 비교
    for string in strs[1:]:
        # prefix 와 같지 않으면
        while not string.startswith(prefix):
            prefix = prefix[:-1] # prefix를 끝 알파벳에서부터 줄여나감
            if not prefix: # prefix 가 empty 되면
                return ""  # return 빈 string
    
    return prefix