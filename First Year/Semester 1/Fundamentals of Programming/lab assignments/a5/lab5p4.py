from copy import deepcopy
#
#Length and elements of a longest subarray(consecutive order) of numbers that contain at most 3 distinct values.
#The length and elements of a maximum subarray sum, when considering each number's real part
# Write the implementation for A5 in this file

#

#
# Write below this comment
# Functions to deal with complex numbers -- list representation
# -> There should be no print or input statements in this section
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#
def create_complex_number_list_representation(real_part_complex_number, imaginary_part_complex_number):
    return [real_part_complex_number, imaginary_part_complex_number]

def generate_list_10_random_complex_numbers_list_representation():
    list_real_part_complex_number=[-5,-5,-5,4,3,3,5,6,6,-6,-2,2,-2]
    list_imaginary_part_complex_number=[7,7,7,8,9,9,7,3,3,3,1,1,1]
    list_complex_numbers=[]
    for i in range(0,13):
        complex_number=create_complex_number_list_representation(list_real_part_complex_number[i], list_imaginary_part_complex_number[i])
        list_complex_numbers.append(complex_number)
    return list_complex_numbers

def add_elements_to_list_complex_numbers(list_complex_numbers:list, complex_number_from_user):
    list_complex_numbers.append(complex_number_from_user)

def get_real_part_of_complex_number_list_representation(complex_number:list):
    real_part = 0
    return complex_number[0]

def get_imaginary_part_of_complex_number_list_representation(complex_number:list):
    real_part = 1
    return complex_number[1]

def set_real_part_of_complex_number_list_representation(complex_number:list, new_real_part:int):
    real_part = 0
    complex_number[0] = new_real_part

def set_imaginary_part_of_complex_number_list_representation(complex_number: list, new_imaginary_part: int):
    imaginary_part = 1
    complex_number[1] = new_imaginary_part


# Write below this comment
# Functions to deal with complex numbers -- dict representation
# -> There should be no print or input statements in this section
# -> Each function should do one thing only
# -> Functions communicate using input parameters and their return values
#
def create_complex_number_dictionary_representation(real, imaginary):
    return {"real": real, "imaginary": imaginary}

def generate_list_random_complex_numbers_dictionary_representation():
    list_complex_numbers = []
    real_parts = [-5, -5, -5, 4, 3, 3, 5, 6, 6, -6, -2, 2, -2]
    imaginary_parts = [7, 7, 7, 8, 9, 9, 7, 3, 3, 3, 1, 1, 1]
    for i in range(len(real_parts)):
        complex_number = create_complex_number_dictionary_representation(real_parts[i], imaginary_parts[i])
        list_complex_numbers.append(complex_number)
    return list_complex_numbers


def get_real_part_dictionary_representation(complex_number):
    return complex_number["real"]

def get_imaginary_part_dictionary_representation(complex_number):
    return complex_number["imaginary"]

def set_real_part_dictionary_representation(complex_number, new_real):
    complex_number["real"] = new_real

def set_imaginary_part_dictionary_representation(complex_number, new_imaginary):
    complex_number["imaginary"] = new_imaginary


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
            list_frequencies_of_elements_in_subarray[0]+=1  #we put the first elem of subarray automatically in the frequencies list
        else:
            if list_complex_numbers[i] == list_complex_numbers[i-1]:  #if the elem is the same as the one before it, we just incerase its frequency
                list_frequencies_of_elements_in_subarray[position_in_list_frequencies]+=1
            else:
                position_in_list_frequencies+=1 #if we are at a different element than the previous one, we go to the next elem in subarray, so in the list of frequencies too
                if second_distinct_element_of_subarray == True:
                    position_of_second_distinct_element_of_subarray = i #we keep the position of where the second elem of subarray starts, because that becomes the pos of the
                                                                    #first element in the next subarray
                    second_distinct_element_of_subarray = False
                if position_in_list_frequencies<=2: #pos are from 0-2
                    list_frequencies_of_elements_in_subarray[position_in_list_frequencies] += 1 #if we have max 3 distinct values, we just increase their frequency when we get to one
                else:  #we got to the fourth distinct value
                    length_of_current_subarray = 0 #reset length of subarray
                    for j in range(3):
                        length_of_current_subarray+= list_frequencies_of_elements_in_subarray[j] #compute length of current subarray
                    if length_of_current_subarray >= maximum_length_longest_subarray_until_now:
                        maximum_length_longest_subarray_until_now = length_of_current_subarray
                        start_point_of_longest_subarray = position_first_element_in_subarray
                        end_point_longest_subarray = i-1 #i-1 because we already are at the fourth distinct elem, so outside of the subarray
                    position_first_element_in_subarray = position_of_second_distinct_element_of_subarray #as we reset the subarray, we alos reset the position of first elem
                                                                                                         # in subarray to the pos of second elem in last subarray
                    i = position_of_second_distinct_element_of_subarray #we start again from the start of the new subarray
                    we_go_to_another_subarray = True
                    list_frequencies_of_elements_in_subarray = [0,0,0]
                    position_in_list_frequencies = 0
                    second_distinct_element_of_subarray = True

        if we_go_to_another_subarray == False :
            i+=1


    #in case the longest subarray is the last one, we won't get to the fourth distinct element, so we have to check if this subarray is the longest outside the body function

    length_of_current_subarray = 0  # reset length of subarray
    for j in range(3):
        length_of_current_subarray += list_frequencies_of_elements_in_subarray[
            j]  # compute length of current subarray
    if length_of_current_subarray >= maximum_length_longest_subarray_until_now:
        maximum_length_longest_subarray_until_now = length_of_current_subarray
        start_point_of_longest_subarray = position_first_element_in_subarray
        end_point_longest_subarray = i - 1  # i-1 because we already are at the fourth distinct elem, so outside of the subarray
    position_first_element_in_subarray = position_of_second_distinct_element_of_subarray  # as we reset the subarray, we alos reset the position of first elem
    # in subarray to the pos of second elem in last subarray
    i = position_of_second_distinct_element_of_subarray  # we start again from the start of the new subarray
    we_go_to_another_subarray = True
    list_frequencies_of_elements_in_subarray = [0, 0, 0]
    position_in_list_frequencies = 0
    second_distinct_element_of_subarray = True

    return  [start_point_of_longest_subarray, end_point_longest_subarray]

def subarray_with_max_real_part_sum(list_of_complex_numbers, representation_type:str):
    """

    :param: list_of_complex_numbers: the list of all complex numbers
    :return: a list with all the elements of the subarray with the max sum
    """
    subarray_with_max_sum = []
    current_subarray = []
    max_subarray_sum = 0
    current_subarray_sum = 0

    for complex_number in list_of_complex_numbers:
        if representation_type == "list":
            real_part = complex_number[0]
        elif representation_type == "dictionary":
            real_part = complex_number["real"]
        if current_subarray_sum + real_part > 0:
            current_subarray.append(complex_number)
            current_subarray_sum += real_part
            if current_subarray_sum > max_subarray_sum:
                subarray_with_max_sum = deepcopy(current_subarray)
                max_subarray_sum = current_subarray_sum
        else:
            current_subarray = []
            current_subarray_sum = 0
    return subarray_with_max_sum




# Write below this comment
# UI section
# Write all functions that have input or print statements here
# Ideally, this section should not contain any calculations relevant to program functionalities

def display_complex_number_dictionary_representation(complex_number, position_of_complex_number_in_the_list):
    return "Z" + str(position_of_complex_number_in_the_list) + "=" + str(complex_number["real"]) + "+" + str(complex_number["imaginary"]) + "i"

def display_list_complex_numbers_dictionary_representation(list_complex_numbers):
    for i, complex_number in enumerate(list_complex_numbers):
        print(display_complex_number_dictionary_representation(list_complex_numbers[i], i))
#
def display_complex_number_list_representation(complex_number_from_list, position_of_complex_number_in_the_list):
    return "Z" + str(position_of_complex_number_in_the_list) + "=" + str(complex_number_from_list[0]) + "+" + str(complex_number_from_list[1]) + "i"

def display_list_complex_numbers_list_representation(list_complex_numbers:list):
    for i in range(0, len(list_complex_numbers)):
        print(display_complex_number_list_representation(list_complex_numbers[i], i))

def display_each_element_from_logest_subarray_list_representation(element_of_subarray):
    print(str(element_of_subarray[0]) + "+" + str(element_of_subarray[1]) + "i" + "    ")

def display_each_element_from_logest_subarray_dictionary_representation(element_of_subarray):
    print(str(element_of_subarray["real"]) + "+" + str(element_of_subarray["imaginary"]) + "i" + "    ")


def display_length_longest_subarray_with_maximum_3_distinct_values( start_point_of_longest_subarray, end_point_longest_subarray):
    return end_point_longest_subarray-start_point_of_longest_subarray+1

def display_longest_subarray_with_maximum_3_distinct_values_list_representation(list_complex_numbers:list, start_point_of_longest_subarray, end_point_longest_subarray):
    for i in range(start_point_of_longest_subarray, end_point_longest_subarray+1):
        display_each_element_from_logest_subarray_list_representation(list_complex_numbers[i])

def display_longest_subarray_with_maximum_3_distinct_values_dictionary_representation(list_complex_numbers:list, start_point_of_longest_subarray, end_point_longest_subarray):
    for i in range(start_point_of_longest_subarray, end_point_longest_subarray+1):
        display_each_element_from_logest_subarray_dictionary_representation(list_complex_numbers[i])
def main():
    list_complex_numbers_list_representation = generate_list_10_random_complex_numbers_list_representation()
    list_complex_numbers_dictionary_representation= generate_list_random_complex_numbers_dictionary_representation()
    while True:
        print("Enter 'dict' for dictionary representation or 'list' for list representation")
        print("Enter 'exit' to exit the program")
        representation = input(">")
        if representation == "list":
            while True:
                print("Press 1 to add a complex number to the list of complex numbers")
                print("Press 2 to display all the elements of the list in list representation")
                print("Press 3 to display the length and elements of a longest subarray of numbers that contain at most 3 distinct values.")
                print("Press 4 to display the elements of a maximum subarray sum, when considering each number's real part")
                print("Press 5 to exit the menu")
                key = input(">")
                if key == "1":
                    real_part_complex_number=input("Introduce the real part of the complex number: ")
                    imaginary_part_complex_number=input("Introduce the imaginary part of the complex number: ")
                    complex_number_from_user=create_complex_number_list_representation(real_part_complex_number, imaginary_part_complex_number)
                    add_elements_to_list_complex_numbers(list_complex_numbers_list_representation, complex_number_from_user)
                    continue
                elif key == "2":
                    print(display_list_complex_numbers_list_representation(list_complex_numbers_list_representation))
                    continue
                elif key == "3":
                    subsequence_interval=find_longest_subarray_with_maximum_3_distinct_values(list_complex_numbers_list_representation)
                    print("The length of a longest subarray of numbers that contain at most 3 distinct: ")
                    start_position = 0
                    end_position = 1
                    print(display_length_longest_subarray_with_maximum_3_distinct_values(subsequence_interval[start_position], subsequence_interval[end_position]))
                    print("And its elements are: ")
                    print(display_longest_subarray_with_maximum_3_distinct_values_list_representation(list_complex_numbers_list_representation, subsequence_interval[start_position], subsequence_interval[end_position]))
                    continue
                elif key == "4":
                    print("The subarray with the maximum sum of the real part of its elements is: ")
                    print(display_list_complex_numbers_list_representation(subarray_with_max_real_part_sum(list_complex_numbers_list_representation, "list")))
                    continue
                elif key == "5":
                    break
                else:
                    print("You didn't press a valid key. Try again.")
                    continue
        elif representation == "dict":
            while True:
                print("Press 1 to add a complex number to the list of complex numbers ")
                print("Press 2 to display all the elements of the list in dictionary representation")
                print("Press 3 to display the length and elements of a longest subarray of numbers that contain at most 3 distinct values.")
                print("Press 4 to display the elements of a maximum subarray sum, when considering each number's real part")
                print("Press 5 to exit the menu")
                key = input(">")
                if key == "1":
                    real_part_complex_number = input("Introduce the real part of the complex number: ")
                    imaginary_part_complex_number = input("Introduce the imaginary part of the complex number: ")
                    complex_number_from_user = create_complex_number_dictionary_representation(real_part_complex_number,
                                                                                         imaginary_part_complex_number)
                    add_elements_to_list_complex_numbers(list_complex_numbers_dictionary_representation, complex_number_from_user)
                    continue
                elif key == "2":
                    print(display_list_complex_numbers_dictionary_representation(list_complex_numbers_dictionary_representation))
                    continue
                elif key == "3":
                    subsequence_interval = find_longest_subarray_with_maximum_3_distinct_values(list_complex_numbers_dictionary_representation)
                    print("The length of a longest subarray of numbers that contain at most 3 distinct: ")
                    start_position = 0
                    end_position = 1
                    print(display_length_longest_subarray_with_maximum_3_distinct_values(
                        subsequence_interval[start_position], subsequence_interval[end_position]))
                    print("And its elements are: ")
                    print(display_longest_subarray_with_maximum_3_distinct_values_dictionary_representation(
                        list_complex_numbers_dictionary_representation, subsequence_interval[start_position], subsequence_interval[end_position]))
                    continue
                elif key == "4":
                    print("The subarray with the maximum sum of the real part of its elements is: ")
                    print(display_list_complex_numbers_dictionary_representation(
                        subarray_with_max_real_part_sum(list_complex_numbers_dictionary_representation, "dictionary")))
                    continue
                elif key == "5":
                    break
                else:
                    print("You didn't press a valid key. Try again.")
                    continue
        elif representation == "exit":
            break


if __name__ == "__main__":
    main()