from src.services.Functionalities import *
class UIException(Exception):
    def __init__(self, message):
        self.__message = message

    @property
    def message(self):
        return self.__message

class UserInterface:
    def __init__(self, services):
        self._functionalities = services
    def Add(self, expense: Expense):
        self._functionalities.Add(expense)
    def Display(self):
        for expense in self._functionalities.Display():
            print(str(expense))
    def Filter(self, lowerBound):
        self._functionalities.Filter(lowerBound)

    def Undo(self):
        self._functionalities.Undo()
    def ReadCommand(self):
        while True:
            try:
                print("Press 1 in order to add an expense")
                print("Press 2 in order to display the list of Expenses")
                print("Press 3 in order to filter the list values above a given value")
                print("Press 4 to Undo")
                print("Press 5 to exit")
                add_expense = 1
                display_expenses = 2
                filter_expenses = 3
                undo = 4
                exit = 5
                userInput = input(">")
                if userInput.isnumeric() == False:
                    raise ValueError("Not A Valid Command")
                if int(userInput) == add_expense:
                    day = int(input("Please Input the Day of the expense:>"))
                    amount = int(input("Please the value of the expense:>"))
                    type_of = input("Please Input the expense category:>")
                    if day not in range(1, 32):
                        raise UIException("The Day is not Valid")
                    self.Add(Expense(day, amount, type_of))
                if int(userInput) == display_expenses:
                    self.Display()
                if int(userInput) == filter_expenses:
                    lowerBound = int(input("Please Input the amount below which we delete elements:>"))
                    self.Filter(lowerBound)
                if int(userInput) == undo:
                    self.Undo()
                if int(userInput) == exit:
                    return

            except Exception as ex:
                print(ex)
                print("Try again")
                continue