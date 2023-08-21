from main import Board
class UI:
    def __init__(self, board:Board):
        self.board = board

    def start(self):
        print(self.board.board_get)
        print("\n")
        print(str(self.board))
        print("Introduce the row, the column on which you want to introduce the next element. e.g: 2, 3")
        print("\n")
        user_input = input()
        position = user_input.split(", ")
        row = int(position[0]) #deci tre sa dau int aici pt ca split face lista de stribguri si atunci si row si col
        #vor fi vazute ca string, dar eu am nevoie de int ca sunt indicii matricii
        col = int(position[1])
        print("Introduce the element: ")
        element = int(input())
        self.board.change_elem_in_board(row, col, element)
        print(str(self.board))

