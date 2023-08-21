#
# The program's functions are implemented here. There is no user interaction in this file, therefore no input/print statements. Functions here
# communicate via function parameters, the return statement and raising of exceptions.
#
import random
def create_list_scores_for_contestant(score_for_problem1:int, score_for_problem2:int, score_for_problem3:int):
    return [score_for_problem1, score_for_problem2, score_for_problem3]
def generate_list_random_contestants_scores():
    list_random_contestant_scores = []
    for i in range(0, 10):
        contestant_scores = create_list_scores_for_contestant(random.randint(0,10), random.randint(0,10), random.randint(0,10))
        list_random_contestant_scores.append(contestant_scores)
    return list_random_contestant_scores

def add_new_contestant_scores(list_contestants_scores:list, new_score_problem_1:int, new_score_problem_2:int, new_score_problem_3:int):

    contestant_scores = create_list_scores_for_contestant(new_score_problem_1, new_score_problem_2, new_score_problem_3)
    list_contestants_scores.append(contestant_scores)
    return list_contestants_scores

def insert_new_contestant_scores_on_specific_position(list_of_operations_to_undo:list, we_are_in_undo:bool, list_contestants_scores:list, new_score_problem_1:int,
                                                      new_score_problem_2:int, new_score_problem_3:int, position_of_insertion):
    if we_are_in_undo == False: #puteam sa fac fct separata pt ce se intampla in acest if si in toate if-urile de la undo==false, dar mi se pare ca m-as complica. parere?
        current_score_problem_1 = int(list_contestants_scores [position_of_insertion][0]) #puteam sa nu pun int aici ca oricum imi ia int in ui in undo insert
        current_score_problem_2 = int(list_contestants_scores[position_of_insertion][1])
        current_score_problem_3 = int(list_contestants_scores[position_of_insertion][2])
        insert_operation = ["insert", current_score_problem_1, current_score_problem_2, current_score_problem_3, position_of_insertion]
        list_of_operations_to_undo.append(insert_operation)
    contestant_scores = create_list_scores_for_contestant(new_score_problem_1, new_score_problem_2, new_score_problem_3)
    list_contestants_scores[position_of_insertion] = contestant_scores
    return list_contestants_scores


def put_removed_contestant_in_undo_list(list_of_operations_to_undo:list, list_contestants_scores:list, removed_contestant:int):
    current_scores_and_position = []
    current_scores = list_contestants_scores[removed_contestant] #[x,y,z]
    current_scores_and_position.append(current_scores) #[[x,y,z]]
    current_scores_and_position.append(removed_contestant) #[[x,y,z], w]
    list_of_operations_to_undo[-1].append(current_scores_and_position) #["remove", [[x,y,z],w]]
    return list_of_operations_to_undo

def set_scores_to_zero_at_given_position(list_of_operations_to_undo:list, list_contestants_scores:list, position_for_score_removal:int):
    put_removed_contestant_in_undo_list(list_of_operations_to_undo, list_contestants_scores, position_for_score_removal)
    list_contestants_scores[position_for_score_removal] = [0,0,0]
    return list_contestants_scores

def set_scores_to_zero_from_start_to_end_given_positions(list_of_operations_to_undo:list,list_contestants_scores:list, start_position_to_set_score_zero:int,
                                                         end_position_to_set_score_zero:int):
    for i in range(start_position_to_set_score_zero, end_position_to_set_score_zero+1):
        put_removed_contestant_in_undo_list(list_of_operations_to_undo, list_contestants_scores, i)
        list_contestants_scores[i] = [0,0,0]
    return list_contestants_scores

def set_scores_less_than_given_value_to_zero(list_of_operations_to_undo:list,list_contestants_scores:list, compare_score_with:int):

    for i in range(0, len(list_contestants_scores)):
        if((sum(list_contestants_scores[i])/len(list_contestants_scores[i]))<compare_score_with):
            put_removed_contestant_in_undo_list(list_of_operations_to_undo, list_contestants_scores, i)
            list_contestants_scores[i] = [0,0,0]
    return list_contestants_scores

def set_scores_equal_to_given_value_to_zero(list_of_operations_to_undo:list, list_contestants_scores:list, compare_score_with:int):
    for i in range(0, len(list_contestants_scores)):
        if((sum(list_contestants_scores[i])/len(list_contestants_scores[i])) == compare_score_with):
            put_removed_contestant_in_undo_list(list_of_operations_to_undo, list_contestants_scores, i)
            list_contestants_scores[i] = [0,0,0]
    return list_contestants_scores

def set_scores_higher_than_given_value_to_zero(list_of_operations_to_undo:list, list_contestants_scores:list, compare_score_with:int):
    for i in range(0, len(list_contestants_scores)):
        if((sum(list_contestants_scores[i])/len(list_contestants_scores[i])) > compare_score_with):
            put_removed_contestant_in_undo_list(list_of_operations_to_undo, list_contestants_scores, i)
            list_contestants_scores[i] = [0,0,0]
    return list_contestants_scores

def replace_score_of_problem_for_contestant(list_of_operations_to_undo:list, we_are_in_undo:bool, list_contestants_scores:list, position_for_score_replacement:int,
                                            problem_to_replace_score:int, new_score_for_problem:int):
    if we_are_in_undo == False:
        current_score_to_be_replaced = int(list_contestants_scores[position_for_score_replacement][problem_to_replace_score])
        replace_operation = ["replace", position_for_score_replacement, problem_to_replace_score, current_score_to_be_replaced]
        list_of_operations_to_undo.append(replace_operation)
    list_contestants_scores[position_for_score_replacement][problem_to_replace_score] = new_score_for_problem
    return list_contestants_scores

def display_participants_and_their_scores_string_representation(list_contestants_scores:list, participant_to_display_scores) -> str:
    return ("p" + str(participant_to_display_scores+1) + "=" + str(list_contestants_scores[participant_to_display_scores]))

def sort_list_decreasing_order_average_score(list_contestants_scores:list):
    for i in range(0, len(list_contestants_scores) - 1):
        for j in range(i+1, len(list_contestants_scores)):
            if (sum(list_contestants_scores[i]) / len(list_contestants_scores[i]) < sum(list_contestants_scores[j]) / len(list_contestants_scores[j])):  # avg score, puteam sa fac fct separata
                list_contestants_scores[i], list_contestants_scores[j] = list_contestants_scores[j], list_contestants_scores[i]
    return list_contestants_scores

def return_contestant_with_score_less_than_certain_value(list_contestants_scores:list, position_of_participant:int, contestant:list, compare_score_with:int):
        if ((sum(contestant) / len(contestant)) < compare_score_with):
            return display_participants_and_their_scores_string_representation(list_contestants_scores, position_of_participant)


def return_contestant_with_score_equal_to_certain_value(list_contestants_scores: list, position_of_participant: int,contestant: list, compare_score_with: int):
    if ((sum(contestant) / len(contestant)) == compare_score_with):
        return display_participants_and_their_scores_string_representation(list_contestants_scores,position_of_participant)

def return_contestant_with_score_above_certain_value(list_contestants_scores: list, position_of_participant: int,contestant: list, compare_score_with: int):
    if ((sum(contestant) / len(contestant)) > compare_score_with):
        return display_participants_and_their_scores_string_representation(list_contestants_scores,position_of_participant)

def sort_list_decreasing_order_of_score_of_certain_problem(list_contestants_scores:list, problem_to_show_score_for:int):
    for i in range(0, len(list_contestants_scores) - 1):
        for j in range(i+1, len(list_contestants_scores)):
            if (list_contestants_scores[i][problem_to_show_score_for-1] <list_contestants_scores[j][problem_to_show_score_for-1] ):
                list_contestants_scores[i], list_contestants_scores[j] = list_contestants_scores[j], list_contestants_scores[i]
    return list_contestants_scores


def undo_for_remove(list_contestants_scores:list, removed_positions:list):
    for i in range (1, len(removed_positions)):
        position_removed = int(removed_positions[i][1])
        list_contestants_scores[position_removed] = removed_positions[i][0]
    return list_contestants_scores
        #["add", ["remove", [[x,y,z],w], [[a,b,c],d]]]=undo_list
        #x,y,z si a,b,c sunt scorurile vechi care u fost setate la 0
        #w si d sunt concurentii (pozitiile din lista de concurenti) ale caror scoruri au fost setate la 0 (removed)