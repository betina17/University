from src.domain.client import Client
from src.domain.client import ClientValidator
from src.repository.client_repo import ClientRepository

class ClientServices:
    def __init__(self, client_repository: ClientRepository, client_validator: ClientValidator):
        self.__client_repository = client_repository
        self.__client_validator = client_validator

    def add_client(self, client_id, name):
        """
            1.Builds the client instance
            2.Validates it
            3.Adds the new client to the list
        """
        new_client = Client(client_id, name)
        self.__client_validator.validate(new_client)
        self.__client_repository.add_client(new_client)

    def remove_client(self, client_id):
        self.__client_repository.remove_client(client_id)

    def get_all_clients_from_list(self):
        return self.__client_repository.get_all_clients_from_list()

    def update_client(self, client_id, name):
        """
            1.Builds the client replacer instance
            2.Validates it
            3.Updates the info of the client with the same id
        """
        client_replacer = Client(client_id, name)
        self.__client_validator.validate(client_replacer)
        self.__client_repository.update_client(client_replacer)

    def search_clients_matching_id(self, client_id: str):
        return self.__client_repository.search_clients_matching_id(client_id)

    def search_clients_matching_name(self, name: str):
        return self.__client_repository.search_clients_matching_name(name)