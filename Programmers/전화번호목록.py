def solution(phone_book):
    phone_book.sort()
    answer = True
    
    # i+1의 prefix는 아닌데 i+2의 prefix 일 수는 없음!
    for i in range(len(phone_book)-1):
        if phone_book[i+1].startswith(phone_book[i]):
            answer = False
            break

    return answer
