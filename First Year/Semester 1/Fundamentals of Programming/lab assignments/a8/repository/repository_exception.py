class RepositoryException(Exception):
    def __init__(self, messages):
        self.__messages = messages

    @property
    def message(self):
        return self.__messages

    def __str__(self):
        return self.__messages