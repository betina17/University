#The sequence a1, ..., an of distinct integer numbers is given. Display all subsets with a mountain aspect. A set has a mountain aspect if the
# elements increase up to a point and then they decrease. E.g. 10, 16, 27, 18, 14, 7.
import random
def generate_list_distinct_integers():
    sequence_distinct_integers=[]
    for i in range(0, 10):
        random_number=random.randint(1, 100)
        ok=1
        for j in range(i, len(sequence_distinct_integers)):
            if sequence_distinct_integers[j] == random_number:
                ok=0
        if ok == 1:
                sequence_distinct_integers.append(random_number)
        else:
                i-=1
    return sequence_distinct_integers


def display_subsets_with_mountain_aspect_recursive_backtracking(sequence_distinct_integers,subsequence:list):
    for i in range(0, len(sequence_distinct_integers)):
        subsequence[0]=sequence_distinct_integers[i]
        position_from_sequence=i
        generate_subsequence(sequence_distinct_integers,subsequence, position_from_sequence+1)


def generate_subsequence(sequence_distinct_integers,subsequence, position_from_sequence):
    for i in range(position_from_sequence, len(sequence_distinct_integers)):
        subsequence[i]=sequence_distinct_integers[i]
        length_subsequence=i
        if i>=2:
            if verify_subsequence_is_mountain(subsequence):
                for i in range(0, length_subsequence):
                    print (subsequence[i])

def verify_subsequence_is_mountain(subsequence):
    max_subsequence = max(subsequence)
    if subsequence[0] == max_subsequence or subsequence[-1] == max_subsequence:
        return False
    else:
        for i in range(1, len(subsequence)-1):
            if subsequence[i] == max:
                position_max=i

        for i in range(0, position_max):
            if subsequence[i]>subsequence[i+1]:
                return False

        for i in range(position_max+1, len(subsequence)):
            if subsequence[i]<subsequence[i+1]:
                return False

    return True

def main():
    sequence_distinct_integers=[]
    sequence_distinct_integers=generate_list_distinct_integers()
    print(sequence_distinct_integers)
    subsequence=[]
    display_subsets_with_mountain_aspect_recursive_backtracking(sequence_distinct_integers, subsequence)

main()
