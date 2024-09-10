import random
import re
import sys
sys.path.append("domain")
from src.repository.repository_exception import RepositoryException
from src.domain.client import Client
from random import choice

class ClientRepository:
    def __init__(self):
        self.__clients = []

    def add_client(self, new_client: Client):
        """
        Adds a new client to the list if his id is not found within the initial list
        Raises a RepositoryException otherwise
        """
        if self.find(new_client.client_id) is not None:
            raise RepositoryException("Client having id: " + str(new_client.client_id) + " is already in list!")
        self.__clients.append(new_client)

    def remove_client(self, client_id: int):
        """
        Removes a client from list if its id is found within the list
        Raises a RepositoryException otherwise
        Returns the removed client
        """

        client_to_be_removed = self.find(client_id)
        if client_to_be_removed is None:
            raise RepositoryException("Client is not part of the list!")
        self.__clients.remove(client_to_be_removed)
        return client_to_be_removed

    def find(self, client_id: int):
        for client in self.__clients:
            if client_id == client.client_id:
                return client
        return None

    def get_all_clients_from_list(self):
        return self.__clients

    def update_client(self, client: Client):
        """
        Updates the list by replacing all characteristics of the client with the same id
        Raises RepositoryException in case the given client is not part of the initial list
        """

        client_to_be_updated = self.find(client.client_id)
        if client_to_be_updated is None:
            raise RepositoryException("Client to be updated is not part of the list!")
        position_in_list = self.__clients.index(client_to_be_updated)
        self.__clients.remove(client_to_be_updated)
        self.__clients.insert(position_in_list, client)

    def __len__(self):
        return len(self.__clients)

    def __str__(self):
        list_of_clients = ""
        for person in self.__clients:
            list_of_clients += person
            list_of_clients += "\n"

        return list_of_clients

    def search_clients_matching_id(self, client_id: str):
        list_of_clients_matching_id = []
        for client in self.__clients:
            if re.search(client_id, str(client.client_id), re.IGNORECASE):
                list_of_clients_matching_id.append(client)

        if len(list_of_clients_matching_id) == 0:
            raise RepositoryException("There is no client with matching id!")

        return list_of_clients_matching_id

    def search_clients_matching_name(self, name: str):
        list_of_clients_matching_name = []
        for client in self.__clients:
            if re.search(name, client.name, re.IGNORECASE):
                list_of_clients_matching_name.append(client)

        if len(list_of_clients_matching_name) == 0:
            raise RepositoryException("There is no client with matching name!")

        return list_of_clients_matching_name

def generate_clients():
    list_of_clients = []
    first_names = ["Ana", "Denisa", "Alexia", "Maria", "Daria", "Teodora", "Alisia", "Arriana", "Iulia", "Oana",
                   "Diandra", "Alex", "Bobi", "Darius", "Tudor", "Andrei", "Iulian", "Florin", "Codrut", "George"]
    last_names = ["Pop", "Ionescu", "Bogdan", "Drugan", "Ciubotaru", "Onaci", "Iliescu", "Boariu", "Vivien", "Elvir",
                  "Toader", "Timisorean", "Cret", "Aries", "Simiocan", "Sas", "Suciu", "Siciu", "Tresca", "Bic"]
    ids = [1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009,
           1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019]
    number_of_clients_for_generation = 0
    while number_of_clients_for_generation != 20:
        name = random.choice(first_names) + " " + random.choice(last_names)
        client = Client(ids[number_of_clients_for_generation], name)
        list_of_clients.append(client)
        number_of_clients_for_generation = number_of_clients_for_generation + 1
    return list_of_clients