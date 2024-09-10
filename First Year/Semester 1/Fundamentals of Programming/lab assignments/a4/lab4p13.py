
#The sequence a1, ..., an of distinct integer numbers is given. Display all subsets with a mountain aspect. A set has a mountain aspect if the
# elements increase up to a point and then they decrease. E.g. 10, 16, 27, 18, 14, 7.
#backtracking
import random
from copy import deepcopy

def generate_distinct_integers_list():
    integers_list = []
    while len(integers_list) < 10:
        random_number = random.randint(1, 100)
        if random_number not in integers_list:
            integers_list.append(random_number)
    return integers_list


def has_mountain_aspect(subsequence):
    if len(subsequence) < 3:
        return False

    peak_index = subsequence.index(max(subsequence))
    # Check if peak is at either end of the subsequence
    if peak_index == 0 or peak_index == len(subsequence) - 1:
        return False

    # Check for strictly increasing then decreasing pattern
    for i in range(1, peak_index):
        if subsequence[i] <= subsequence[i - 1]:
            return False
    for i in range(peak_index + 1, len(subsequence)):
        if subsequence[i] >= subsequence[i - 1]:
            return False

    return True


def generate_consecutive_subsequences_recursive_backtracking(sequence, start=0, end=2, results=[]):
    if end > len(sequence):
        return

    subsequence = sequence[start:end]
    if has_mountain_aspect(subsequence):
        results.append(subsequence)


    generate_consecutive_subsequences_recursive_backtracking(sequence, start, end + 1, results)
    if end == len(sequence):
        generate_consecutive_subsequences_recursive_backtracking(sequence, start + 1, start+3, results)

    return results

def generate_consecutive_subsequences_iterative_backtracking(sequence):
    stack = []
    results=[]
    for i in range(len(sequence)):
        subsequence = []
        subsequence.append(sequence[i])
        for j in range(i+1, len(sequence)):
            subsequence.append(sequence[j])
            if(len(subsequence)>=3):
                stack.append(deepcopy(subsequence))

    for k in range(len(stack)):
        if has_mountain_aspect(stack[k]):
            results.append(stack[k])

    return results

def main():
    distinct_integers = generate_distinct_integers_list()
    print("Original Sequence:", distinct_integers)

    mountain_subsequences_recursive_backtracking = generate_consecutive_subsequences_recursive_backtracking(distinct_integers)
    mountain_subsequences_iterative_backtracking = generate_consecutive_subsequences_iterative_backtracking(distinct_integers)
    print("Mountain Subsequences recursive backtracking:")
    for subsequence in mountain_subsequences_recursive_backtracking:
        print(subsequence)

    print("\nMountain Subsequences iterative backtracking: ")
    for subsequence in mountain_subsequences_iterative_backtracking:
        print(subsequence)




if __name__ == "__main__":
    main()
