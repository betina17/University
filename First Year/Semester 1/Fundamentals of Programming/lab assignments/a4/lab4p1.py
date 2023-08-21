#Determine the longest common subsequence of two given sequences. Subsequence elements are not required to occupy consecutive positions.
# For example, if X = "MNPNQMN" and Y = "NQPMNM", the longest common subsequence has length 4, and can be one of "NQMN", "NPMN" or "NPNM".
# Determine and display both the length of the longest common subsequence as well as at least one such subsequence.
def create_sequence(sequence:list, length_sequence:int):
    for i in range (0, length_sequence):
        sequence.append(input())

def create_data_structure(sequence1:list, sequence2:list, length_sequence1:int, length_sequence2:int, matrix_to_find_result:list):
    for i in range(0, length_sequence2+ 1):
        for j in range(0, length_sequence1 + 1):
            if i == 0 or j == 0:
                matrix_to_find_result[i][j] = 0
            elif sequence1[j-1] == sequence2[i-1]:
                matrix_to_find_result[i][j] = matrix_to_find_result[i - 1][j - 1] + 1
            else:
                matrix_to_find_result[i][j] = max(matrix_to_find_result[i][j - 1], matrix_to_find_result[i - 1][j])


def display_data_structure(length_sequence1:int, length_sequence2:int, matrix_to_find_result:list):
    for i in range (length_sequence2+1):
        for j in range(length_sequence1+1):
            print(matrix_to_find_result[i][j], end=" ")
        print()

def display_longest_common_subsequence(sequence1:list, length_sequence1:int, length_sequence2:int, matrix_to_find_result:list):
   i=length_sequence2+1
   j=length_sequence1+1
   while i!= 0 and i!= 1 and j!=0 and j!=1:
       if matrix_to_find_result[i][j] != max(matrix_to_find_result[i][j - 1], matrix_to_find_result[i - 1][j]):
           print(sequence1[j-1])
           i-=1
           j-=1
       else:
           if matrix_to_find_result[i][j] == matrix_to_find_result[i - 1][j] == matrix_to_find_result[i][j - 1] or matrix_to_find_result[i][j] == matrix_to_find_result[i - 1][j]:
               i-=1
           else:
               j-=1 #matrix_to_find_result[i][j]==matrix_to_find_result[j-1][i]


def main():
    sequence1=[]
    sequence2=[]
    print("Introduce the length of sequence 1: ")
    length_sequence1 = int(input())
    print("Introduce the elements of sequence 1: ")
    create_sequence(sequence1, length_sequence1)
    print("Introduce the length of sequence 2: ")
    length_sequence2 = int(input())
    print("Introduce the elements of sequence 2: ")
    create_sequence(sequence2, length_sequence2)
    rows_in_matrix, columns_in_matrix=(length_sequence2+1, length_sequence1+1)
    matrix_to_find_result=[[0]*columns_in_matrix]*rows_in_matrix
    print(matrix_to_find_result)
    create_data_structure(sequence1, sequence2, length_sequence1, length_sequence2, matrix_to_find_result)
    display_data_structure(length_sequence1, length_sequence2, matrix_to_find_result)
    print(f"The length of the longest common subsequence of sequence 1 and sequence 2 is: {matrix_to_find_result[length_sequence2][length_sequence1]}")
    print("the longest common subsequence of sequence 1 and sequence 2 is:")
    display_longest_common_subsequence(sequence1, length_sequence1, length_sequence2, matrix_to_find_result)



main()