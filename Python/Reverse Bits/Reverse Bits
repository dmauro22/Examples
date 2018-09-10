
def func(num):
    x = num
    answer = 0
    for i in range (0,32):
        answer <<= 1
        answer += x & 1
        x >>= 1
    return answer

def main():
    test = 255
    print("Your original number is: ", test)
    result = func(test)
    print("Your upgraded number is: ", result)
    
main()
