from src.domain.Domain import Expense
from src.repository.Repos import ExpenseRepository
import copy
import unittest


class FunctionalitiesException(Exception):
    def __init__(self, message):
        self.__message = message

    @property
    def message(self):
        return self.__message


class Functionalities:
    def __init__(self, repository):
        self._repository = repository
        self.operations = 0
        self._archive = []
        self._archive.append(copy.deepcopy(self._repository.getAll()))

    @property
    def repository(self):
        return self._repository

    @repository.setter
    def repository(self, new_repository):
        self._repository = new_repository

    @property
    def archive(self):
        return self._archive

    @archive.setter
    def archive(self, new_archive):
        self._archive = new_archive

    def Add(self, expense: Expense):
        self._repository.add(expense)
        self._archive.append(copy.deepcopy(self._repository.getAll()))
        self.operations += 1

    def Display(self):
        return self._repository.getAll()

    def Filter(self, value_below_which_we_delete):
        for expense in self._repository.getAll()[:]: #iterate over a copy of the list, because we might modify the actual list in the loop
            if expense.amount < value_below_which_we_delete:
                self._repository.remove(expense)
        self._archive.append(copy.deepcopy(self._repository.getAll()))
        self.operations += 1


    def Undo(self):
        if self.operations == 0:
            raise FunctionalitiesException("There is nothing to UNDO")
        self.operations -= 1
        self._archive.pop()
        newList = self._archive[len(self._archive) -1]  # lista de pe penultima pozitie
        self._repository.changeData(newList)


def test_add_expense():
    repository = ExpenseRepository()
    services = Functionalities(repository)
    expense = Expense(1, 100, "food")
    services.Add(expense)
    assert (expense in services.repository.getAll())


if __name__ == "__main__":
    test_add_expense()
