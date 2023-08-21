from main import Board
from ui import UI
if __name__ == "__main__":
    domain = Board(4,6)
    ui = UI(domain)
    ui.start()