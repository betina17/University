#include <stdio.h>

int verify_if_prime_number(int number)///write a single prime verification function that can be used on each number
{
    int is_prime = 1;
    int is_prime2 = 1;
    for (int i = 3; i*i <= number; i += 2)   ///algoritm nou folosit
        if (number% i == 0)
        {is_prime = 0;
            i = number;
        }
    if (is_prime == 1)
    {

        number += 2;
        for (int i = 2; i <= number / 2; i++)  //viata unei variabile din antetul functiei se termina cand iesi din functie, de asta trb sa pun int si in acest for, chiar daca am pus deja in ala de mai sus
            if (number% i == 0)
            {is_prime2 = 0;
                i = number;
            }
    }

    if (is_prime && is_prime2)
        return 1;

    return 0;

}

void display_vector_of_pairs_of_twin_numbers(int vector[], int n)
{
    for (int i=0; i<2*n;i+=2)
    {
        int first_elem_of_pair = vector[i];
        int second_elem_of_pair = vector[i + 1];
        printf("(%u, %u)", first_elem_of_pair, second_elem_of_pair);
    }

}

void find_first_n_pairs_of_twin_numbers(int n)
{
    int vector_of_pairs_of_twin_numbers[1000];
    int position_in_vector = 0;
    int current_number = 3; // 2 cannot be in a pair of prime twin numbers
    int current_number_of_pairs = 0;
    while (current_number_of_pairs < n)
    {
        if (verify_if_prime_number(current_number) == 1)
        {
            current_number_of_pairs += 1;
            vector_of_pairs_of_twin_numbers[position_in_vector] = current_number;
            position_in_vector += 1;
            vector_of_pairs_of_twin_numbers[position_in_vector] = current_number + 2;
            position_in_vector += 1;
        }

        current_number += 2;

    }

    display_vector_of_pairs_of_twin_numbers(vector_of_pairs_of_twin_numbers, n); ///better call this function in the show_option function, not here
}
void display_longest_decreasing_contiguous_subsequence(int given_vector[], int position_of_first_elem_of_subsequence, int position_of_last_elem_of_subsequence)
{
    for (int i = position_of_first_elem_of_subsequence; i <= position_of_last_elem_of_subsequence; i++)
    printf("%d ", given_vector[i]);


}
void find_longest_decreasing_contiguous_subsequence(int given_vector[], int length_of_vector)
{
    int maximum_length_of_solution_subsequence = 0;
    int position_of_first_elem_of_subsequence = 0;
    int position_of_last_elem_of_valid_subsequence;
    int position_of_first_elem_of_valid_subsequence;
    int nr_of_elem_in_subsequence=1;
    int i;
    for (i = 0; i<length_of_vector - 1; i++)
    {

        if (given_vector[i] > given_vector[i + 1])
            nr_of_elem_in_subsequence += 1;
        else
        {
            if (nr_of_elem_in_subsequence > maximum_length_of_solution_subsequence)
            {
                maximum_length_of_solution_subsequence = nr_of_elem_in_subsequence;
                position_of_last_elem_of_valid_subsequence = i;
                position_of_first_elem_of_valid_subsequence = position_of_first_elem_of_subsequence;
            }
            position_of_first_elem_of_subsequence = i + 1; //incepe o noua secventa, de la elem i+1
            nr_of_elem_in_subsequence = 1;
        }
    }
    if (nr_of_elem_in_subsequence > maximum_length_of_solution_subsequence)
    {
        maximum_length_of_solution_subsequence = nr_of_elem_in_subsequence;
        position_of_last_elem_of_valid_subsequence = i;
        position_of_first_elem_of_valid_subsequence = position_of_first_elem_of_subsequence;
    }
    display_longest_decreasing_contiguous_subsequence(given_vector, position_of_first_elem_of_valid_subsequence, position_of_last_elem_of_valid_subsequence);

}
void read_vector(int given_vector[], int length_of_vector)
{
    for (int i = 0; i < length_of_vector; i++) {
        printf("%u", i);
        printf(">");
        scanf("%d", &given_vector[i]);
    }

}
void show_option()
{
    while(1 ==1) {
        printf("\nIntroduce the option that you want>\n");
        int option;
        scanf_s("%u", &option);
        if (option == 1) {
            int n;
            printf("Introduce number n>");
            scanf_s("%u", &n);
            find_first_n_pairs_of_twin_numbers(n);

        } else if (option == 2) {
            printf("Introduce the length of the vector>");
            int length_of_vector;
            scanf_s("%d", &length_of_vector);
            printf("\nIntroduce the elements of the vector>\n");
            int given_vector[1000] = {0};
            read_vector(given_vector, length_of_vector);

            find_longest_decreasing_contiguous_subsequence(given_vector, length_of_vector);
        } else if (option == 3)
            break;

    }

}

void user_interface()
{
    printf("Press 1 to determine the first n pairs of twin numbers>\n");
    printf("Press 2 to introduce a vector of numbers and find the longest contiguous subsequence such that any consecutive elements have at least 2 distinct digits in common>\n");
    printf("Press 3 to exit the program>\n");
    show_option();
}
int main()
{

    user_interface();
    return 0;
}
