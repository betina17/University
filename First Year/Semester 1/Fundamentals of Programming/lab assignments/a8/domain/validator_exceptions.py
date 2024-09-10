class ValidatorException(Exception):
    def __init__(self, list_of_messages):
        self._list_of_messages = list_of_messages

    def get_message(self):
        return self._list_of_messages

    def __str__(self):
        validation_errors = ""
        for message in self._list_of_messages:
            validation_errors += message
            validation_errors += "\n"
        return validation_errors
