# Задание 1. Вариант 9

import numpy as np

def create_matrix():
  
#     A = np.array([[1,2,0,0,0,0,0],
#                  [0,3,2,0,0,0,0],
#                  [0,0,5,2,0,0,0],
#                  [0,0,0,7,2,0,0],
#                  [0,0,0,0,9,2,0],
#                  [0,0,0,0,0,11,2],
#                  [-8,-8,-8,-8,-8,-8,-8]])

    A = np.diag([1, 3, 5, 7, 9, 11, 0]) + np.diag([2, 2, 2, 2, 2, 2], k=1)
    A[-1, :] = -8
    
    E = np.eye(7)
    B = np.exp(A)
    result = np.block([[A, E], [np.zeros((7, 7)), B]])
    
    np.savetxt('matrix.txt', result, fmt='%.0f')
