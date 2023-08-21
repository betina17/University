
class Board:
    def __init__(self):
        self.board = [[0 for j in range(7)] for i in range(6)]

        # self._board = [[0] * self._cols for i in range(self._rows)]
    @property
    def board_getter(self):
        return self.board

    def visualize_board(self, board):
        for row in board:
            colored_row = []
            for cell in row:
                if cell == 1:
                    colored_row.append('\033[91m' + str(cell) + '\033[0m')  # 91m is the code for red
                elif cell == 2:
                    colored_row.append('\033[93m' + str(cell) + '\033[0m')  # 93m is the code for yellow
                else:
                    colored_row.append(str(cell))
            print(' '.join(colored_row))


