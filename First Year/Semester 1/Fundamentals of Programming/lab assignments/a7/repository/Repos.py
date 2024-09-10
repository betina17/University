from src.domain.Domain import Expense
import copy
import pickle
import unittest

class RepoException(Exception):
    def __init__(self, message):
        self.__message = message

    @property
    def message(self):
        return self.__message

import random
class ExpenseRepository:
    def __init__(self):
        self._data = []

    def add(self, new_expense: Expense):
        if new_expense in self._data:
            raise RepoException("Expense Already Added")
        self._data.append(new_expense)

    def remove(self, expense: Expense):
        if expense not in self._data:
            raise RepoException("Expense does not exist")
        self._data.remove(expense)

    def getAll(self):
        return self._data

    def getExpense(self, index):
        return self._data[index]

    def changeData(self, new_list):
        self._data = copy.deepcopy(new_list)

class ExpenseTextRepository(ExpenseRepository):
    def __init__(self, file_name):
        super().__init__()
        self._file_name = file_name
        self.loadFile()
    def loadFile(self):
        inputFile = open(self._file_name, "rt")
        text = inputFile.readlines()
        inputFile.close()
        for line in text:
            currentLine = line.split(" ")
            argumentDay = 0
            argumentSum = 1
            argumentCategory = 2
            expense = Expense(int(currentLine[argumentDay].strip()), int(currentLine[argumentSum].strip()), currentLine[argumentCategory].strip())
            super().add(expense)

    def add(self, expense: Expense):
        super().add(expense)
        self.saveToFile()

    def remove(self, expense: Expense):
        super().remove(expense)
        self.saveToFile()

    def changeData(self, new_list):
        super().changeData(new_list)
        self.saveToFile()


    def saveToFile(self):
        with open(self._file_name, "wt") as outputFile:
           for expense in self._data:
               outputFile.write(str(expense.day) + " " + str(expense.amount) + " " + expense.type_of + "\n")



class ExpenseBinaryRepository(ExpenseRepository):
    def __init__(self, file_name):
        super().__init__()
        self._file_name = file_name


    def loadFile(self):
        inputFile = open(self._file_name, "rb")
        decodedInputFile = pickle.load(inputFile)
        for expenses in decodedInputFile:
            super().add(expenses)
        inputFile.close()

    def add(self, expense: Expense):
        super().add(expense)
        self.saveFile()

    def remove(self, expense: Expense):
        super().remove(expense)
        self.saveFile()

    def changeData(self, new_list):
        super().changeData(new_list)
        self.saveToFile()

    def saveFile(self):
        outputFile = open(self._file_name, "wb")
        pickle.dump(self._data, outputFile)
        outputFile.close()



def testAddNewExpense():
    repo = ExpenseRepository()
    expense = Expense(1, 100, "food")
    repo.add(expense)
    assert(expense in repo.getAll())

if __name__ == '__main__':
    testAddNewExpense()
