from src.repository.Repos import *
from src.services.Functionalities import *
from src.ui.Ui import *
from src.domain.Domain import Expense

if __name__ == "__main__":
    typeRepository = input("Input the type of repository: memory/text/binary>")
    if typeRepository not in ["text", "Text", "memory", "Memory", "binary", "Binary"]:
        raise ValueError("invalid reposition type")
    elif typeRepository == "text" or typeRepository == "Text":
        repository = ExpenseTextRepository("ExpenseTextRepository.txt")

    elif typeRepository == "binary" or typeRepository == "Binary":
        repository = ExpenseBinaryRepository("ExpenseBinaryRepository.bin")

    else:
        repository = ExpenseRepository()
    services = Functionalities(repository)
    UI = UserInterface(services)
    firstExpense = Expense(1, 100, "food")
    secondExpense = Expense(2, 200, "clothes")
    thirdExpense = Expense(3, 300, "movies")
    fourthExpense = Expense(4, 400, "hygiene")
    fifthExpense = Expense(5, 500, "restaurant")
    sixthExpense = Expense(6, 600, "gas")
    seventhExpense = Expense(7, 700, "furniture")
    eighthExpense = Expense(8, 800, "games")
    ninthExpense = Expense(9, 900, "books")
    tenthExpense = Expense(10, 1000, "electronics")
    services.Add(firstExpense)
    services.Add(secondExpense)
    services.Add(thirdExpense)
    services.Add(fourthExpense)
    services.Add(fifthExpense)
    services.Add(sixthExpense)
    services.Add(seventhExpense)
    services.Add(eighthExpense)
    services.Add(ninthExpense)
    services.Add(tenthExpense)



    UI.ReadCommand()