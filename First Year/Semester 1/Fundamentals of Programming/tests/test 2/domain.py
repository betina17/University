from src.validator import AssigmentException
class Assignment:
    def __init__(self, id, student_name, solution):
        self.id = id
        self.student_name = student_name
        self.solution = solution


    def id(self):
        return self.id




    def student_name(self):
        return self.student_name




    def solution(self):
        return self.solution


    def __str__(self):
        return "id: " + str(self.id) + ", student name: " + self.student_name + ", assignment solution:" + self.solution

    def __repr__(self):
        return str(self)


class AssigmentValidator:
    def validate_assigment(assigment):
        if len(assigment.student_name) < 3:
            raise AssigmentException("The student name does not have at least 3 characters!")

        if assigment.solution == "":
            raise AssigmentException("The solution is an empty string!")

