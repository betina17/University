#Determine the longest common subsequence of two given sequences. Subsequence elements are not required to occupy consecutive positions.
# For example, if X = MNPNQMN and Y = NQPMNM, the longest common subsequence has length 4, and can be one of "NQMN", "NPMN" or "NPNM".
# Determine and display both the length of the longest common subsequence as well as at least one such subsequence.
#dynamic programming
def create_sequence_as_list(sequence_as_list:list, sequence:str):
    for i in range (0, len(sequence)):
        sequence_as_list.append(sequence[i])
    return sequence_as_list

def longest_common_subsequence_naive_implementation(first_sequence:list, second_sequence:list):
    maximum_subsequence = []
    maximum_subsequence_length = 0
    current_subsequence_length = 0
    current_subsequence = []
    for i in range(0, len(first_sequence)):
        for j in range(0, len(second_sequence)):
            if first_sequence[i] == second_sequence[j]:
                current_subsequence_length+=1
                current_subsequence.append(first_sequence[i])
                i+=1
                if i>len(first_sequence)-1:
                    break
            else:
                if current_subsequence_length > maximum_subsequence_length:
                    maximum_subsequence_length = current_subsequence_length
                    maximum_subsequence = current_subsequence
                    current_subsequence = []
                    current_subsequence_length = 0
    if current_subsequence_length > maximum_subsequence_length:
        maximum_subsequence_length = current_subsequence_length
        maximum_subsequence = current_subsequence
    return maximum_subsequence_length, maximum_subsequence

def create_data_structure_for_dynamic_programming_approach(first_sequence:list, second_sequence:list, matrix_to_find_result:list):
    for i in range(0, len(second_sequence)+1):
        for j in range(0, len(first_sequence)+1):
            if i == 0 or j == 0:
                matrix_to_find_result[i][j] = 0
            elif first_sequence[j-1] == second_sequence[i - 1]:  #if the current elem from the first sequence is equal to the current elem from the second sequence
                matrix_to_find_result[i][j] = matrix_to_find_result[i - 1][j - 1] + 1 #our current elem takes the value of the elem from the top left corner + 1
            else:
                matrix_to_find_result[i][j] = max(matrix_to_find_result[i][j - 1], matrix_to_find_result[i - 1][j])
                #else, our current element takes the value of the max between the elem from the left and the elem from the top


def display_data_structure_of_dynamic_programming_approach(first_sequence:list, second_sequence:list, matrix_to_find_result:list):
    for i in range(0, len(second_sequence) + 1):
        for j in range(0, len(first_sequence) + 1):
            print(matrix_to_find_result[i][j], end=" ")
        print()

def get_longest_common_subsequence_of_two_sentences(first_sequence:list, second_sequence:list, matrix_to_find_result:list):
    i = len(second_sequence)
    j = len(first_sequence)
    #we start from the bottom right corner of the matrix
    #if the current elem is not equal to the max from the left or from the top, then it is a part of the longest subsequence
    #so we pick the element and move diagonally up
    longest_subsequence = []

    while i > 0 and j > 0:
        if matrix_to_find_result[i][j] != max(matrix_to_find_result[i][j - 1], matrix_to_find_result[i - 1][j]):
            longest_subsequence.append(first_sequence[j - 1]) #j-1 because the matrix has one more column and row than the length of the sequences
            i -= 1
            j -= 1   #we move diagonally up
        else:
            if matrix_to_find_result[i][j] == matrix_to_find_result[i - 1][j]: #if the current elem is equal to the max from the top, we move up
                i -= 1
            else:
                j -= 1 #if the current elem is equal to the max from the left, we move left

    return ''.join(reversed(longest_subsequence))


def main():
    first_sequence_as_list=[]
    second_sequence_as_list=[]
    print("Introduce the elements of sequence 1: ")
    first_sequence = input()
    first_sequence_as_list= create_sequence_as_list(first_sequence_as_list, first_sequence)
    print("Introduce the elements of sequence 2: ")
    second_sequence = input()
    second_sequence_as_list= create_sequence_as_list(second_sequence_as_list, second_sequence)
    rows_in_matrix, columns_in_matrix=(len(first_sequence_as_list)+1, len(second_sequence_as_list)+1)
    matrix_to_find_result=[[0 for i in range(rows_in_matrix)] for j in range(columns_in_matrix)]
    print(matrix_to_find_result)
    create_data_structure_for_dynamic_programming_approach(first_sequence_as_list, second_sequence_as_list, matrix_to_find_result)
    display_data_structure_of_dynamic_programming_approach(first_sequence_as_list, second_sequence_as_list, matrix_to_find_result)
    length_longest_common_subsequence=matrix_to_find_result[len(second_sequence_as_list)][len(first_sequence_as_list)] #elem din colt jos dreapta
    print(f"The length of the longest common subsequence of sequence 1 and sequence 2 is: {length_longest_common_subsequence}")
    print(f"the longest common subsequence of sequence 1 and sequence 2 is: {get_longest_common_subsequence_of_two_sentences(first_sequence_as_list, second_sequence_as_list, matrix_to_find_result)}")
    print(f"naive implementation:")
    (length_subsequence, subsequence) = longest_common_subsequence_naive_implementation(first_sequence_as_list, second_sequence_as_list)
    print(f"length={length_subsequence}")
    print(f"subsequence is: {subsequence}")




main()