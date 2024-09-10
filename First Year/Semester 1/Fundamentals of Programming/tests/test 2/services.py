class Services:
    def __init__(self, repository):
        self.__repository = repository

    def add_assignment(self, new_assignemnt):
        self.__repository.add(new_assignemnt)

    @property
    def repository(self):
        return self.__repository


