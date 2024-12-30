import random

def generate_test_data(num_tests):
    test_data = []
    
    for _ in range(num_tests):
        a = random.randint(2, 100)
        b = random.randint(2, 100)
        m = random.randint(10, 1000)
        
        matrix = [['0' for _ in range(b)] for _ in range(a)]
        start_x, start_y = random.randint(0, a-1), random.randint(0, b-1)
        matrix[start_x][start_y] = '@'
        
        apple_count = random.randint(1, a*b - 1)  # 至少有一个苹果
        
        for _ in range(apple_count):
            while True:
                x, y = random.randint(0, a-1), random.randint(0, b-1)
                if matrix[x][y] == '0':
                    matrix[x][y] = str(random.randint(1, 9))
                    break
        
        test_data.append({
            'a': a,
            'b': b,
            'm': m,
            'matrix': matrix
        })
    
    return test_data

# 生成100个测试数据
test_data = generate_test_data(100)

# 打印第一个测试数据作为示例
print(test_data[0])