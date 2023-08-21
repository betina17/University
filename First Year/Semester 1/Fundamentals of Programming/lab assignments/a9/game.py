from board import Board
import random
class Game:
    def __init__(self, board: Board):
        self.board = board
        self.num_rows = 6
        self.num_cols = 7
        self.column_where_computer_moves = 0

    def place_symbol_on_table(self, row:int, column:int, symbol: chr): #for human
        self.board.board_getter[row][column] = symbol

    def get_line_to_place_move(self, column, symbol): #for human
        for row in range(5, -1, -1):
            if self.board.board_getter[row][column] == 0:
                return self.place_symbol_on_table(row, column, symbol)

    def check_if_column_chosen_by_human_is_full(self,column: int):
        if self.board.board_getter[0][column] != 0:
           return True

    def check_if_board_is_full(self):
        for row in range(6):
            for column in range(7):
                if self.board.board_getter[row][column] == 0:
                    return False
        return True

    def check_lines_for_winner(self, symbol):
        for row in range(self.num_rows):
            for col in range(self.num_cols - 3):
                if self.board.board_getter[row][col] == self.board.board_getter[row][col + 1] == \
                        self.board.board_getter[row][col + 2] == self.board.board_getter[row][col + 3] == symbol:
                    return -symbol

    def check_columns_for_winner(self, symbol):
        for col in range(self.num_cols):
            for row in range(self.num_rows - 3):
                if self.board.board_getter[row][col] == self.board.board_getter[row + 1][col] == \
                        self.board.board_getter[row + 2][col] == self.board.board_getter[row + 3][col] == symbol:
                    return -symbol

    def check_diagonals_from_left_to_right_for_winner(self, symbol):
        for row in range(self.num_rows - 3):
            for col in range(self.num_cols - 3):
                if self.board.board_getter[row][col] == self.board.board_getter[row + 1][col + 1] == \
                        self.board.board_getter[row + 2][col + 2] == self.board.board_getter[row + 3][col + 3] == symbol:
                    return -symbol

    def check_diagonals_from_right_to_left_for_winner(self, symbol):
        for row in range(self.num_rows - 3):
            for col in range(3, self.num_cols):
                if self.board.board_getter[row][col] == self.board.board_getter[row + 1][col - 1] == \
                        self.board.board_getter[row + 2][col - 2] == self.board.board_getter[row + 3][col - 3] == symbol:
                    return -symbol

    def check_if_symbol_won(self, symbol):
        if self.check_lines_for_winner(symbol) == -symbol or self.check_columns_for_winner(symbol) == -symbol or \
                self.check_diagonals_from_left_to_right_for_winner(symbol) == -symbol or \
                self.check_diagonals_from_right_to_left_for_winner(symbol) == -symbol:
            return -symbol

    def compute_random_move_for_computer(self):
        computer_chose = 0
        while computer_chose == 0:
            column = random.randint(0, 6)
            for row in range(5, -1, -1):
                if self.board.board_getter[row][column] == 0:
                    self.board.board_getter[row][column] = 2
                    self.set_column_where_computer_moves(column)
                    computer_chose = 1
                    break

    def is_valid_and_empty(self, r, c):  # Helper function to check if a position is valid and has a value of 0, si respects the gravity law
        if 0 <= r < self.num_rows and 0 <= c < self.num_cols:
            if r == 5 and self.board.board_getter[r][c] == 0:
                return True
            elif r <= 4 and self.board.board_getter[r][c] == 0 and self.board.board_getter[r + 1][c] != 0:
                return True
        return False

    def set_column_where_computer_moves(self, column):
        self.column_where_computer_moves = column

    def search_on_lines_sequence_of_three_consecutive_same_symbols(self, symbol):
        for row in range(self.num_rows):
            for col in range(self.num_cols - 2):
                if self.board.board_getter[row][col] == self.board.board_getter[row][col + 1] == self.board.board_getter[row][col + 2] == symbol:
                    # Verifica daca poate completa la stanga sau la dreapta
                    if self.is_valid_and_empty(row, col - 1):
                        self.board.board_getter[row][col - 1] = 2
                        self.set_column_where_computer_moves(col-1)
                        return True
                    elif self.is_valid_and_empty(row, col + 3):
                        self.board.board_getter[row][col + 3] = 2
                        self.set_column_where_computer_moves(col+3)
                        return True


    def search_on_columns_sequence_of_three_consecutive_same_symbols(self, symbol):
        for col in range(self.num_cols):
            for row in range(self.num_rows - 2):
                if self.board.board_getter[row][col] == self.board.board_getter[row + 1][col] == self.board.board_getter[row + 2][col] == symbol:
                    # Verifica daca poate completa deasupra
                    if self.is_valid_and_empty(row - 1, col):
                        self.board.board_getter[row - 1][col] = 2
                        self.set_column_where_computer_moves(col)
                        return True


    def search_on_diagonals_from_left_to_right_sequence_of_three_consecutive_same_symbols(self, symbol):
        for row in range(self.num_rows - 2):
            for col in range(self.num_cols - 2):
                if self.board.board_getter[row][col] == self.board.board_getter[row + 1][col + 1] == self.board.board_getter[row + 2][col + 2] == symbol:
                    # Verifica daca poate completa in sus-stanga sau jos-dreapta
                    if self.is_valid_and_empty(row - 1, col - 1):
                        self.board.board_getter[row - 1][col - 1] = 2
                        self.set_column_where_computer_moves(col-1)
                        return True
                    elif self.is_valid_and_empty(row + 3, col + 3):
                        self.board.board_getter[row + 3][col + 3] = 2
                        self.set_column_where_computer_moves(col+3)
                        return True

    def search_on_diagonals_from_right_to_left_sequence_of_three_consecutive_same_symbols(self, symbol):
        for row in range(self.num_rows - 2):
            for col in range(2, self.num_cols):
                if self.board.board_getter[row][col] == self.board.board_getter[row + 1][col - 1] == \
                        self.board.board_getter[row + 2][col - 2] == symbol:
                    # Verifica daca poate completa in sus-dreapta sau jos-stanga
                    if self.is_valid_and_empty(row - 1, col + 1):
                        self.board.board_getter[row - 1][col + 1] = 2
                        self.set_column_where_computer_moves(col+1)
                        return True
                    elif self.is_valid_and_empty(row + 3, col - 3):
                        self.board.board_getter[row + 3][col - 3] = 2
                        self.set_column_where_computer_moves(col-3)
                        return True

    def check_if_player_won(self):
        return self.check_if_symbol_won(1)

    def check_if_computer_won(self):
        return self.check_if_symbol_won(2)

    def check_if_computer_wins_by_completing_sequence_of_three_consecutive_symbols_of_2(self):
        if self.search_on_lines_sequence_of_three_consecutive_same_symbols(2) == True or \
        self.search_on_columns_sequence_of_three_consecutive_same_symbols(2) == True or \
        self.search_on_diagonals_from_left_to_right_sequence_of_three_consecutive_same_symbols(2) == True or \
        self.search_on_diagonals_from_right_to_left_sequence_of_three_consecutive_same_symbols(2) == True:
            return True
        return False

    def check_if_computer_blocks_player_win(self):
        if self.search_on_lines_sequence_of_three_consecutive_same_symbols(1) == True or \
        self.search_on_columns_sequence_of_three_consecutive_same_symbols(1) == True or \
        self.search_on_diagonals_from_left_to_right_sequence_of_three_consecutive_same_symbols(1) == True or \
        self.search_on_diagonals_from_right_to_left_sequence_of_three_consecutive_same_symbols(1) == True:
            return True
        return False



    def play_computer(self):
        #######################################verificam daca a castigat playerul
        if self.check_if_player_won() == -1:
            return -1

        ############daca playerul nu a castigat, verificam daca ar putea sa castige computerul acum(adica daca exista 3 elemente consecutive de 2, pe linii, coloane sau diagonale,
        #si spatiu liber in stanga sau dreapta, sau deasupra, in functie de caz, ca sa poata completa secventa sa fie 4 elemente consecutive de 2 si sa castige jocul
        # -daca poate, casuta respectiva primeste valoarea 2, si returneaza -2, ca sa stiu ca a castigat computerul si sa opresc jocul
        elif self.check_if_computer_wins_by_completing_sequence_of_three_consecutive_symbols_of_2() == True:
            return -2

        ##############################daca nu a putut castiga computerul, veirficam daca poate macar bloca posibila victoria viitoare a playerului, adica exista o
        ###############################secventa de 3 elem consecutive de 1, care poate fi completata cu un 2, ca sa nu poata sa o completeze playerul cu un 1 si sa castige
        #-daca poate bloca, casuta respectiva primeste valoarea 2

        if self.check_if_computer_blocks_player_win() == True:
            return 0

        ##############################daca nu a putut castiga si nici nu a avut ce sa castige, computerul pune random
        self.compute_random_move_for_computer()

        #chiar si daca computerul nu a castigat gasind 3 elemente de 2 consecutive, asta nu inseamna ca nu poate castiga dupa ce pune o mutare random
        #ar fi putut avea 1 0 1 1, si nu vedea asta ca pe o combinatie posibila de castig, dar daca pune random acolo, va castiga.
        #de asta trebuie sa verificam toata tabla si dupa ce pune computerul random.
        ##################verificam daca a castigat computerul dupa ce a pus random

        if self.check_if_computer_won() == -2:
            return -2

        return 0


