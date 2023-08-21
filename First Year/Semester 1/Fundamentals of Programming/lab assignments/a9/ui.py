from board import Board
from game import Game
class UserInterface:
    def __init__(self, game:Game):
        self.game = game
    def start_game(self):
        board = Board()
        self.game = Game(board)
        in_game = True
        board.visualize_board(self.game.board.board_getter) #afisare la start
        human_won = False
        while in_game:
            valid_human_move = True
            while valid_human_move:
                try:
                    print("Place your move on column> ")
                    column = int(input())
                    if self.game.check_if_column_chosen_by_human_is_full(column) == True:
                        print("This column is already full. Try again!")
                    elif column not in [0, 1, 2, 3, 4, 5, 6]:
                        print("Invalid move. Please enter a number between 0 and 6.")
                    else:
                        self.game.get_line_to_place_move(column, 1)
                        valid_human_move = False
                except ValueError:
                    print("Invalid input. Please enter an integer between 0 and 6.")

            board.visualize_board(self.game.board.board_getter) #afisare dupa mutarea playerului
            print("\n")
            play = self.game.play_computer()
            computer_move = self.game.column_where_computer_moves
            print("The computer moved on column" + " " + str(computer_move))
            if play == -2:
                print("Sorry, the computer won the game!")
                in_game = False
            elif play == -1:
                print("Congrats, you won the game!")
                in_game = False
                human_won = True
            print("\n")
            if human_won == False:
                board.visualize_board(self.game.board.board_getter)
                if self.game.check_if_board_is_full() == True:
                    print("The board is full. It's a tie!")
                    in_game = False








