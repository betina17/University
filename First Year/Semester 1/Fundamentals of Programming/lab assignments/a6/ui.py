import functions
import copy
#command driven
#POSITION = CONTESTANT
#position refers to the position of contestant in the list-la asta se refera in assingment, nu mai spune contestant, spune direct position = position of contestant in the
#list of contestants
#problem is the position 1, 2 or 3  in a list in the main list
#score is the value of the problem, the value on position 1, 2 or 3  in a list in the main list
#daca nu suntem in undo inseamna ca vreau sa imi alipeasca la lista de undo ultima operatie. daca suntem in undo nu vreau
def main():
    list_of_operations_to_undo = []
    list_contestants_scores = functions.generate_list_random_contestants_scores()
    print("This is the list of 10 contestants scores randomly generated")
    print(list_contestants_scores)
    print("\nA-Add the result of a new participant.You can: ")
    print("a)add <P1 score> <P2 score> <P3 score> -e.g.- add 3 8 10 – add a new participant with scores 3,8 and 10 (scores for P1, P2, P3 respectively)")
    print("b)insert <P1 score> <P2 score> <P3 score> at <position> -e.g.- insert 10 10 9 at 5 – insert scores 10, 10 and 9 at position 5 in the list (positions numbered from 0)")
    print("\nB-Modify scores. You can:")
    print("a)remove <position> -e.g.- remove 1 – set the scores of the participant at position 1 to 0")
    print("b)remove <start position> to <end position> -e.g.- remove 1 to 3 – set the scores of participants at positions 1, 2 and 3 to 0")
    print("c)replace <old score> <P1 | P2 | P3> with <new score> -e.g.- replace 4 P2 with 5 – replace the score obtained by participant 4 at P2 with 5")
    print("\nC-Display participants whose score has different properties. You can display:")
    print("a)list - display participants and all their scores")
    print("b)list sorted – display participants sorted in decreasing order of average score")
    print("c)list [ < | = | > ] <score> -e.g.- list < 4 – display participants with an average score <4. list = 6 – display participants with an average score =6")
    print("\nD-Establish the podium. You can display: ")
    print("a)top <number> -e.g.- top 3 – display the 3 participants having the highest average score, in descending order of average score")
    print("b)top <number> <P1 | P2 | P3> -e.g.- top 4 P3 – display the 4 participants who obtained the highest score for P3, sorted descending by that score")
    print("Or you can: ")
    print("remove [ < | = | > ] <score> -e.g- remove < 70 – set the scores of participants having an average score <70 to 0")
    print("\nE-Undo - the last operation that modified program data is reversed. You can we_are_in_undo all operations performed since program start by repeatedly calling this function.")

    while True:
        print("Introduce the option that you want")
        print(">")
        user_input = input()
        option = user_input.split()
        command = 0
        try:
###################ADD############################ADD###########################ADD############################################################################################
            if option[command] == "add":
                try:
                    operation = ["add"]
                    list_of_operations_to_undo.append(operation)
                    new_score_problem_1 = int(option[1])
                    new_score_problem_2 = int(option[2])
                    new_score_problem_3 = int(option[3])
                    print("This is the list with the new added contestant")
                    print(functions.add_new_contestant_scores(list_contestants_scores, new_score_problem_1, new_score_problem_2, new_score_problem_3))
                except (IndexError, ValueError):
                    print("You introduced too many or not enough arguments for the selected option. Try again!")
######################INSERT####################INSERT###################INSERT#################################################################################################
            elif option[command] == "insert":
                try:
                    we_are_in_undo = False
                    new_score_problem_1 = int(option[1])
                    new_score_problem_2 = int(option[2])
                    new_score_problem_3 = int(option[3])
                    position_of_insertion = int(option[5])
                    print("This is the modified list")
                    print(functions.insert_new_contestant_scores_on_specific_position(list_of_operations_to_undo, we_are_in_undo, list_contestants_scores, new_score_problem_1, new_score_problem_2, new_score_problem_3, position_of_insertion))
                except (IndexError, ValueError):
                    print("You introduced too many or not enough arguments for the selected option. Try again!")
######################REMOVE###########################REMOVE#####################REMOVE#######################################################################################
            elif option[command] == "remove":
                remove_operation = ["remove"]
                list_of_operations_to_undo.append(remove_operation)
                if len(option) == 2:
                    position_for_removal = int(option[1])
                    print("This is the modified list")
                    print(functions.set_scores_to_zero_at_given_position(list_of_operations_to_undo, list_contestants_scores, position_for_removal))

                elif len(option) == 4:
                    start_position_for_removal = int(option[1])
                    end_position_for_removal = int(option[3])
                    print("This is the modified list")
                    print(functions.set_scores_to_zero_from_start_to_end_given_positions(list_of_operations_to_undo,
                                                                                         list_contestants_scores, start_position_for_removal,
                                                                                        end_position_for_removal))

                elif len(option) == 3:
                    comparison_sign = option[1]
                    compare_score_with = int(option[2])
                    if comparison_sign == "<":
                        functions.set_scores_less_than_given_value_to_zero(list_of_operations_to_undo,list_contestants_scores, compare_score_with)
                        print("This is the modified list")
                        print(list_contestants_scores)

                    elif comparison_sign == "=":
                        functions.set_scores_equal_to_given_value_to_zero(list_of_operations_to_undo,list_contestants_scores, compare_score_with)
                        print("This is the modified list")
                        print(list_contestants_scores)

                    elif comparison_sign == ">":
                        functions.set_scores_higher_than_given_value_to_zero(list_of_operations_to_undo,list_contestants_scores, compare_score_with)
                        print("This is the modified list")
                        print(list_contestants_scores)

                else:
                    print("You introduced too many or not enough arguments for the selected option. Try again!")
##############################REPLACE#########################REPLACE#####################REPLACE#############################################################################
            elif option[command] == "replace":
                try:
                    we_are_in_undo = False
                    position_for_score_replacement = int(option[1])
                    problem_to_replace_score =  int(option[2][1])
                    new_score_for_problem =  int(option[4])
                    print("This is the modified list")
                    print(functions.replace_score_of_problem_for_contestant(list_of_operations_to_undo, we_are_in_undo, list_contestants_scores,position_for_score_replacement,problem_to_replace_score,new_score_for_problem))
                except (IndexError, ValueError):
                    print("You introduced too many or not enough arguments for the selected option. Try again!")
#######################LIST##########################LIST#################################LIST#################################################################################
            elif option[command] == "list":
                if len(option) == 1:
                    print("This is the list of all participants and their scores")
                    for i in range (0, len(list_contestants_scores)):
                        print(functions.display_participants_and_their_scores_string_representation(list_contestants_scores, i))


                elif len(option) == 2:
                    print("This is the sorted list")
                    list_contestants_scores_to_sort = list_contestants_scores
                    functions.sort_list_decreasing_order_average_score(list_contestants_scores_to_sort)
                    for i in range(0, len(list_contestants_scores_to_sort)):
                        print(functions.display_participants_and_their_scores_string_representation(
                            list_contestants_scores_to_sort, i))


                elif len(option) == 3:
                    comparison_sign =  int(option[1])
                    compare_score_with =  int(option[2])
                    if comparison_sign == "<":
                        score_has_this_property =False
                        for i in range(0, len(list_contestants_scores)):
                            display_result = functions.return_contestant_with_score_less_than_certain_value(list_contestants_scores, i, list_contestants_scores[i], compare_score_with)
                            if display_result != None:
                                print(display_result)
                                score_has_this_property = True
                        if score_has_this_property == False:
                                print("No participant has a score with this property")

                    elif comparison_sign == "=":
                        score_has_this_property =False
                        for i in range(0, len(list_contestants_scores)):
                            display_result = functions.return_contestant_with_score_equal_to_certain_value(list_contestants_scores, i, list_contestants_scores[i], compare_score_with)
                            if display_result != None:
                                print(display_result)
                                score_has_this_property = True
                        if score_has_this_property == False:
                                print("No participant has a score with this property")

                    elif comparison_sign == ">":
                        score_has_this_property =False
                        for i in range(0, len(list_contestants_scores)):
                            display_result = functions.return_contestant_with_score_above_certain_value(list_contestants_scores, i, list_contestants_scores[i], compare_score_with)
                            if display_result != None:
                                print(display_result)
                                score_has_this_property = True
                        if score_has_this_property == False:
                                print("No participant has a score with this property")

                else:
                        print("You introduced too many or not enough arguments for the selected option. Try again!")
#####################TOP##############################TOP######################################TOP##############################################################################
            elif option[command] == "top":
                if len(option) == 2:
                    number_of_top_participants_to_display = int(option[1])
                    list_contestants_scores_to_sort = copy.deepcopy(list_contestants_scores)
                    functions.sort_list_decreasing_order_average_score(list_contestants_scores_to_sort)
                    for i in range(0, number_of_top_participants_to_display):
                        print(functions.display_participants_and_their_scores_string_representation(list_contestants_scores_to_sort, i))

                elif len(option) == 3:
                    number_of_top_participants_to_display = int(option[1])
                    list_contestants_scores_to_sort = copy.deepcopy(list_contestants_scores)
                    problem_to_show_top_score_for = int(option[2][1])
                    functions.sort_list_decreasing_order_of_score_of_certain_problem(list_contestants_scores_to_sort, problem_to_show_top_score_for)
                    for i in range(0, number_of_top_participants_to_display):
                        print(functions.display_participants_and_their_scores_string_representation(list_contestants_scores_to_sort, i))

                else:
                    print("You introduced too many or not enough arguments for the selected option. Try again!")
#####################UNDO###################################UNDO########################UNDO###################################################################################
            elif option[command] == "undo":
                if len(list_of_operations_to_undo) == 0:
                    print("There aren't any steps that you can undo anymore")
                else:
                    we_are_in_undo = True
                    if list_of_operations_to_undo[-1][0] == "add":
                        list_contestants_scores.pop()
                    elif list_of_operations_to_undo[-1][0] == "replace":
                        position_for_score_replacement = int(list_of_operations_to_undo[-1][1])
                        problem_to_replace_score = int(list_of_operations_to_undo[-1][2])
                        old_score_for_problem = int(list_of_operations_to_undo[-1][3])
                        functions.replace_score_of_problem_for_contestant(list_of_operations_to_undo, we_are_in_undo,
                                                                          list_contestants_scores,
                                                                          position_for_score_replacement,
                                                                          problem_to_replace_score, old_score_for_problem)
                    elif list_of_operations_to_undo[-1][0] == "insert":
                        old_score_problem_1 = int(list_of_operations_to_undo[-1][1])
                        old_score_problem_2 = int(list_of_operations_to_undo[-1][2])
                        old_score_problem_3 = int(list_of_operations_to_undo[-1][3])
                        position_of_insertion = int(list_of_operations_to_undo[-1][4])
                        functions.insert_new_contestant_scores_on_specific_position(list_of_operations_to_undo,
                                                                                    we_are_in_undo, list_contestants_scores,
                                                                                    old_score_problem_1, old_score_problem_2,
                                                                                    old_score_problem_3, position_of_insertion)

                    elif list_of_operations_to_undo[-1][0] == "remove":
                        removed_positions = list_of_operations_to_undo[-1]
                        functions.undo_for_remove(list_contestants_scores, removed_positions)

                    print("This was the list before: ")
                    print(list_contestants_scores)
                    list_of_operations_to_undo.pop()


        except (IndexError):
            print("You didn't introduce one of the given options properly. Try again!")
#in undo sunt OLD values, in UI si functions sunt NEW values, in functions in if undo==false sunt CURRENT values, pt ca pe ele le salvezi, ele vor fi inlocuite de NEW values
#din ui, care sunt si parametri in functiile din functions (ui si functions, de asta am zis), si care devin OLD values in undo (tot de asta am zis)
main()