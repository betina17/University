from board import Board
from game import Game
from ui import UserInterface

if __name__ == "__main__":

    domain = Board()
    services = Game(domain)
    user_interface = UserInterface(services)
    user_interface.start_game()