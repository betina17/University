from src.domain import Assignment
from copy import deepcopy

class RepoException(Exception):

    def __init__(self, message):
        self.__message = message

    @property
    def message(self):
        return self.__message

import random
class Repository:
    def __init__(self):
        self._data = []

    def add(self, new_assingment: Assignment):
        if new_assingment in self._data:
            raise RepoException("Assignment Already Added")
        self._data.append(new_assingment)

    def getAll(self):
        return self._data

    def getAssigment(self, index):
        return self._data[index]


class TextRepository(Repository):
    def __init__(self, file_name):
        super().__init__()
        self._file_name = file_name
        self.loadFile()
    def loadFile(self):
        inputFile = open(self._file_name, "rt")
        text = inputFile.readlines()
        inputFile.close()
        for line in text:
            currentLine = line.split(",")
            id = 0
            name = 1
            solution = 2
            assignment = Assignment(int(currentLine[id].strip()), currentLine[name].strip(), currentLine[solution].strip())
            super().add(assignment)

    def add(self, assignment):
        super().add(assignment)
        self.saveToFile()

    def saveToFile(self):
        with open(self._file_name, "wt") as outputFile:
           for assignment in self._data:
               outputFile.write(str(assignment.id) + "," + str(assignment.student_name) + "," + assignment.solution + "\n")
