from src.domain.validator_exceptions import ValidatorException
class Client:
    def __init__(self, client_id: int, name: str):
        self.__client_id = client_id
        self.__name = name

    @property
    def client_id(self):
        return self.__client_id

    @property
    def name(self):
        return self.__name

    @client_id.setter
    def client_id(self, new_id):
        self.__client_id = new_id

    @name.setter
    def name(self, new_name):
        self.__name = new_name

    def __eq__(self, other_client):
        if isinstance(other_client, Client) is False:
            return False
        return self.client_id == other_client.client_id

    def __str__(self):
        return "Client-> ID:" + str(self.__client_id) + ", Name:" + self.__name

    def __repr__(self):
        return str(self)

class ClientValidator:
    def validate(self, client):
        """
        Validate if provided Client instance is valid
        :param client: is a Client type object
        :return: list of validation errors. If the client is valid, it returns an empty list.
        """


        _list_of_errors = []
        if len(client.name) == 0:
            _list_of_errors.append("Name not valid!")
        if len(_list_of_errors) > 0:
            raise ValidatorException(_list_of_errors)