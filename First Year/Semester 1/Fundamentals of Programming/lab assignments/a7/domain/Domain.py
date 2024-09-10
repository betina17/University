class Expense:

    def __init__(self, day: int, amount: int, type_of: str):
        self.__day = day
        self.__amount = amount
        self.__type_of = type_of

    @property
    def type_of(self):
        return self.__type_of

    @type_of.setter
    def type_of(self, new_type):
        self.type_of = new_type

    @property
    def amount(self):
        return self.__amount

    @amount.setter
    def amount(self, new_amount):
        self.__amount = new_amount

    @property
    def day(self):
        return self.__day
    @day.setter
    def day(self, new_day):
        self.__day = new_day

    def __repr__(self):
        return str(self)

    def __str__(self):
        return (str(self.__day) + " " + str(self.__amount) + " " + self.__type_of)


def test_Expense():
    new_expense = Expense(25, 2000, "Christmas")
    assert new_expense.day == 25
    assert new_expense.amount == 2000
    assert new_expense.type_of == "Christmas"
    assert str(new_expense) == "25 2000 Christmas"

    new_expense.amount = 50
    assert str(new_expense) == "25 50 Christmas"
    print(new_expense.__dict__)

if __name__ == "__main__":
    test_Expense()
