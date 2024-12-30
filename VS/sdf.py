import random

def generate_test_case():
    p = random.randint(1, 20)  # 炸药堆数量
    x = random.randint(1, 100)  # 体力
    n = random.randint(10, 20)  # 学校矩阵的行数
    m = random.randint(10, 20)  # 学校矩阵的列数
    
    a = [random.randint(1, 100) for _ in range(p)]  # 炸药的药量
    b = [random.randint(1, 100) for _ in range(p)]  # 炸药的重量
    
    school_map = []
    for _ in range(n):
        row = ''.join(str(random.randint(0, 10)) if random.random() > 0.1 else '*' for _ in range(m))
        school_map.append(row)
    
    return p, x, n, m, a, b, school_map

def write_test_cases(filename, num_cases):
    with open(filename, 'w') as f:
        for _ in range(num_cases):
            p, x, n, m, a, b, school_map = generate_test_case()
            f.write(f"{p} {x} {n} {m}")
            f.write(' '.join(map(str, a)) + "")
            f.write(' '.join(map(str, b)) + "")
            f.write(''.join(school_map) + "")
            f.write("\n" * 2 + "")  # 分隔不同的测试用例

# 生成200组测试数据并写入文件
write_test_cases('test_cases__poiu.txt', 20)