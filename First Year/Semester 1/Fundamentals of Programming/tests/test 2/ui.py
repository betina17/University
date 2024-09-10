from src.domain import AssigmentException
from src.domain import Assignment
from src.domain import AssigmentValidator
class UI:
    def __init__(self, controller):
        self.controller = controller
    def start(self):
        print("Press 1 to add a new student")
        print("Press 2 to display all students")
        add_assignment = 1
        display_assignments = 2
        print("Introduce your option>")
        option = int(input())
        if option == add_assignment:
            print("id>")
            not_add = 0
            id = int(input())
            assigments_list = self.controller.repository.getAll()
            try:
                for assignment in assigments_list:
                    if assignment.id == id:
                       raise AssigmentException("The id is not unique!")




            except AssigmentException as e:
                print(e)
            print("student name>")
            student_name = input()
            print("solution>")
            solution = input()
            new_assignment = Assignment(id, student_name, solution)
            try:
                AssigmentValidator.validate_assigment(new_assignment)

            except AssigmentException as e:
                print(e)


            self.controller.add_assignment(new_assignment)

        elif option == 2:
            assigments_list = self.controller.repository.getAll()
            for assignment in assigments_list:
                print(assignment)



