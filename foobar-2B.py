def msb(b):
    i = b.find('1')
    b = b[:i] + '0' + b[i+1:]
    return bin(int(b,2)+1)

def is_power(x):
    return (x and (not(x & (x - 1))))

def simple_case(num):
    if(is_power(num+2) or is_power(num+1)):
        return True
    else:
        return False

def return_simple_case(num):
    if(is_power(num+2)):
        return num+1
    else:
        return (2*num + 1)

def main(h,num):
    if(pow(2,h)-1 == num):
        return (-1)
    ans = 0
    while(not simple_case(num)):
        binary_num = bin(num)
        binary_num = msb(binary_num)
        int_num_new = int(binary_num,2)
        ans = ans + (num - int_num_new)
        num = int_num_new

    ans = ans + return_simple_case(num)
    print(ans)
    
def solution(h, q):
    # Your code here
    final = []
    for e in q:
        final.append(main(h,e))
    print(final)

solution(3,[7,3,5,1])
    