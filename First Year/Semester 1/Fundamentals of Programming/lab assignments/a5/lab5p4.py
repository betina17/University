#
#Length and elements of a longest subarray of numbers that contain at most 3 distinct values.
# Write the implementation for A5 in this file

#

#
# Write below this comment
# Functions to deal with complex numbers -- list representation
# -> There should be no print or input statements in this section
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#
def create_complex_number(real_part_complex_number, imaginary_part_complex_number):
    return [real_part_complex_number, imaginary_part_complex_number]

def generate_list_12_random_complex_numbers():
    list_real_part_complex_number=[5,5,5,4,3,3,5,6,6,6,2,2,2]
    list_imaginary_part_complex_number=[7,7,7,8,9,9,7,3,3,3,1,1,1]

    list_complex_numbers=[]
    for i in range(0,13):
        complex_number=create_complex_number(list_real_part_complex_number[i], list_imaginary_part_complex_number[i])
        list_complex_numbers.append(complex_number)
    return list_complex_numbers

def add_elements_to_list_complex_numbers(list_complex_numbers:list, complex_number_from_user):
    list_complex_numbers.append(complex_number_from_user)

#
# Write below this comment
# Functions that deal with subarray/subsequence properties
# -> There should be no print or input statements in this section
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#

def find_longest_subarray_with_maximum_3_distinct_values(list_complex_numbers:list):
    list_frequencies_of_elements_in_subarray = [0,0,0]
    position_first_element_in_subarray = 0
    maximum_length_longest_subarray_until_now = 0
    position_in_list_frequencies = 0
    second_distinct_element_of_subarray=True
    i=0

    while i < len(list_complex_numbers):
        we_go_to_another_subarray = False
        if i == position_first_element_in_subarray:
            list_frequencies_of_elements_in_subarray[0]+=1
        else:
            if list_complex_numbers[i] == list_complex_numbers[i-1]:
                list_frequencies_of_elements_in_subarray[position_in_list_frequencies]+=1
            else:
                position_in_list_frequencies+=1
                if second_distinct_element_of_subarray == True:
                    position_of_second_distinct_element_of_subarray = i
                    second_distinct_element_of_subarray = False
                if position_in_list_frequencies<=2:
                    list_frequencies_of_elements_in_subarray[position_in_list_frequencies] += 1
                else:
                    length_of_current_subarray = 0
                    for j in range(3):
                        length_of_current_subarray+= list_frequencies_of_elements_in_subarray[j]
                    if length_of_current_subarray >= maximum_length_longest_subarray_until_now:
                        maximum_length_longest_subarray_until_now = length_of_current_subarray
                        start_point_of_longest_subarray = position_first_element_in_subarray
                        end_point_longest_subarray = i-1
                    position_first_element_in_subarray = position_of_second_distinct_element_of_subarray
                    i = position_of_second_distinct_element_of_subarray
                    we_go_to_another_subarray = True
                    list_frequencies_of_elements_in_subarray = [0,0,0]
                    position_in_list_frequencies = 0
                    second_distinct_element_of_subarray = True

        if we_go_to_another_subarray == False :
            i+=1

    return  (start_point_of_longest_subarray, end_point_longest_subarray)



# Write below this comment
# UI section
# Write all functions that have input or print statements here
# Ideally, this section should not contain any calculations relevant to program functionalities
#
def display_each_complex_number_from_list(complex_number_from_list, position_of_complex_number_in_the_list):
    return "Z" + str(position_of_complex_number_in_the_list) + "=" + str(complex_number_from_list[0]) + "+" + str(complex_number_from_list[1]) + "i"

def display_list_complex_numbers(list_complex_numbers:list):
    for i in range(0, len(list_complex_numbers)):
        print(display_each_complex_number_from_list(list_complex_numbers[i], i))

def display_each_element_from_logest_subarray(element_of_subarray):
    print(str(element_of_subarray[0]) + "+" + str(element_of_subarray[1]) + "i" + "    ")

#if i put print here it displays me the elements, with return it doesn t
def display_length_longest_subarray_with_maximum_3_distinct_values( start_point_of_longest_subarray, end_point_longest_subarray):
    return end_point_longest_subarray-start_point_of_longest_subarray+1

def display_longest_subarray_with_maximum_3_distinct_values(list_complex_numbers:list, start_point_of_longest_subarray, end_point_longest_subarray):
    for i in range(start_point_of_longest_subarray, end_point_longest_subarray+1):
        display_each_element_from_logest_subarray(list_complex_numbers[i])
def main():
    list_complex_numbers = generate_list_12_random_complex_numbers()
    add_number = 1
    display_numbers = 2
    display_length_and_elements_longest_subarray = 3
    exit_program = 4
    print(f"Press {add_number} to add a complex number to the list of complex numbers")
    print(f"Press {display_numbers} to display all the elements of the list")
    print(f"Press {display_length_and_elements_longest_subarray} to display the length and elements of a longest subarray of numbers that contain at most 3 distinct values.")
    print(f"Press {display_length_and_elements_longest_subarray} to exit the program")

    while True:
        key = input(">")
        if key == add_number:
            real_part_complex_number=input("Introduce the real part of the complex number: ")
            imaginary_part_complex_number=input("Introduce the imaginary part of the complex number: ")
            complex_number_from_user=create_complex_number(real_part_complex_number, imaginary_part_complex_number)
            add_elements_to_list_complex_numbers(list_complex_numbers, complex_number_from_user)
        elif key == display_numbers:
            print(display_list_complex_numbers(list_complex_numbers))
        elif key == display_length_and_elements_longest_subarray:
            subsequence_interval=find_longest_subarray_with_maximum_3_distinct_values(list_complex_numbers)
            print("The length of a longest subarray of numbers that contain at most 3 distinct values: ")
            print(display_length_longest_subarray_with_maximum_3_distinct_values(subsequence_interval[0], subsequence_interval[1]))
            print("And its elements are: ")
            print(display_longest_subarray_with_maximum_3_distinct_values(list_complex_numbers, subsequence_interval[0], subsequence_interval[1]))
        elif key == exit_program:
            break
        else:
            print("You didn't press a valid key. Try again.")


if __name__ == "__main__":
    main()