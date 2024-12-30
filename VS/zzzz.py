def is_prime(n):
    """检查一个数是否是质数"""
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# 生成小于10000的所有质数的列表
primes = [i for i in range(2, 10000) if is_prime(i)]

def count_semi_primes(a, b):
    """计算在a和b之间的半质数的数量"""
    count = 0
    for num in range(a, b + 1):
        for prime in primes:
            if prime > num:
                break
            if num % prime == 0 and is_prime(num // prime):
                count += 1
                break
    return count

# 读取输入
a, b = map(int, input().split())

# 计算并输出结果
print(count_semi_primes(a, b))