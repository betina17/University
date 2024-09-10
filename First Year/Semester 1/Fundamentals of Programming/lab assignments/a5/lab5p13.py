#
# Functions to deal with complex numbers -- list representation
#

def modulus_of_complex_number(complex_number):
    return (complex_number[0] ** 2 + complex_number[1] ** 2) ** 0.5

#
# Write below this comment
# Functions that deal with subarray/subsequence properties
#

def is_alternating_sequence(prev_modulus, current_modulus, is_increasing):
    return (is_increasing and current_modulus > prev_modulus) or (not is_increasing and current_modulus < prev_modulus)

def find_longest_alternating_subsequence_modulus(list_complex_numbers):
    if not list_complex_numbers:
        return 0, []

    max_length = 1
    max_subsequence = [list_complex_numbers[0]]

    current_length = 1
    current_subsequence = [list_complex_numbers[0]]
    prev_modulus = modulus_of_complex_number(list_complex_numbers[0])
    is_increasing = True

    for i in range(1, len(list_complex_numbers)):
        current_modulus = modulus_of_complex_number(list_complex_numbers[i])
        if is_alternating_sequence(prev_modulus, current_modulus, is_increasing):
            current_subsequence.append(list_complex_numbers[i])
            current_length += 1
            is_increasing = not is_increasing
            prev_modulus = current_modulus
        else:
            if current_length > max_length:
                max_length = current_length
                max_subsequence = current_subsequence.copy()

            current_length = 2
            current_subsequence = [list_complex_numbers[i - 1], list_complex_numbers[i]]
            prev_modulus = modulus_of_complex_number(list_complex_numbers[i - 1])
            is_increasing = current_modulus > prev_modulus

    if current_length > max_length:
        max_length = current_length
        max_subsequence = current_subsequence

    return max_length, max_subsequence

#
# UI section
#
def display_each_complex_number_from_list(complex_number_from_list, position_of_complex_number_in_the_list):
    return "Z" + str(position_of_complex_number_in_the_list) + "=" + str(complex_number_from_list[0]) + "+" + str(complex_number_from_list[1]) + "i"

def display_list_complex_numbers(list_complex_numbers:list):
    for i in range(0, len(list_complex_numbers)):
        print(display_each_complex_number_from_list(list_complex_numbers[i], i))
def display_alternating_subsequence(list_complex_numbers, subsequence):
    for complex_number in subsequence:
        print(display_each_complex_number_from_list(complex_number, list_complex_numbers.index(complex_number)))

def main():
    list_complex_numbers = [[3,4], [4,5], [3,4], [5,6], [7,8], [8,9], [2,3]]
    print("Press 2 to display all the elements of the list")
    print(
        "Press 3 to display the length and elements of a longest subarray of numbers that contain at most 3 distinct values.")
    print("Press 4 to exit the program")

    while True:
        key = input(">")
        if key == "2":
            print(display_list_complex_numbers(list_complex_numbers))
        elif key == "3":
            (length_subsequence, subsequence) = find_longest_alternating_subsequence_modulus(list_complex_numbers)
            print("The length of a longest subarray of numbers that contain at most 3 distinct values: ")
            print()
            print("And its elements are: ")
            print()
        elif key == "4":
            break
        else:
            print("You didn't press a valid key. Try again.")

    while True:

        if key == "5":
            length, subsequence = find_longest_alternating_subsequence_modulus(list_complex_numbers)
            print("Length of the longest alternating subsequence: ", length)
            print("Elements of the subsequence: ")
            display_alternating_subsequence(list_complex_numbers, subsequence)

# ... rest of your code ...
