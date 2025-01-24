import numpy as np

def read_matrix_from_file(filename):
    with open(filename, 'r') as file:
        n = int(file.readline().strip())
        matrix = []
        for _ in range(n):
            row = list(map(float, file.readline().strip().split()))
            matrix.append(row)
    return np.array(matrix)

if __name__ == '__main__':
    filename = 'test_files/file24.txt'
    matrix = read_matrix_from_file(filename)
    
    determinant = np.linalg.det(matrix)
    
    print(f'{determinant}')