from src.domain import *
from src.repository import *
from src.services import *
from src.ui import *


if __name__ == "__main__":
    repository = TextRepository("assigments.txt")
    services = Services(repository)
    UI = UI(services)
    UI.start()