from src.domain.rental import Rental
from src.repository.repository_exception import RepositoryException
from src.repository.movie_repo import MovieRepository
from src.repository.client_repo import ClientRepository

from datetime import date
from datetime import timedelta
import random

class RentalRepository:
    def __init__(self, movie_repository: MovieRepository, client_repository: ClientRepository):
        self.__rentals = []
        self.__history = []
        self.__movie_repository = movie_repository
        self.__client_repository = client_repository

    def add_rental(self, new_rental: Rental):
        """
            Adds rental to the rental repository
            Used for storing the randomly generated rentals
        """
        self.__rentals.append(new_rental)
        self.__history.append(new_rental)

    def rent_a_movie(self, new_rental: Rental):
        """
        A client can rent a movie if he does not have any passed due date rentals
        Otherwise, it is raised a RepositoryException
        """
        if self.find_rental_id(new_rental.rental_id) is None:
            if (self.find_movie_to_be_rented(new_rental.movie_id) is True and
                self.find_client_that_rents(new_rental.client_id) is True):
                if self.find_rentals_of_client(new_rental.client_id) is not None:
                    raise RepositoryException("Client with id: " + str(new_rental.client_id) + "has at least one passed due "
                                                                                               "date rental!")
                self.__rentals.append(new_rental)
                self.__history.append(new_rental)
            else:
                raise RepositoryException("Client or movie not part of the lists!")
        else:
            raise RepositoryException("There exists a rental with the same ID!")

    def find_rental_id(self, rental_id):
        for rental in self.__history:
            if rental.rental_id == rental_id:
                return rental
        return None

    def find_rentals_of_client(self, client_id):
        """
        :param client_id: Gets as parameter the id of the client
        :return: one rental of the client if he had rented a movie, haven't returned it yet and it is passed due date
        Otherwise, returns None
        """
        today = date.today()
        maximum_date = date(9999, 12, 31)
        for rental in self.__rentals:
            if rental.client_id == client_id:
                #if we find other rentals of the same client, we verify if they passed their due date
                if rental.due_date < today and rental.renturned_date == maximum_date:
                    return rental
        return None

    def find_movie_to_be_rented(self, movie_id):
        for movie in self.__movie_repository.get_all_movies_from_list():
            if movie.movie_id == movie_id:
                return True
        return False

    def find_client_that_rents(self, client_id):
        for client in self.__client_repository.get_all_clients_from_list():
            if client.client_id == client_id:
                return True
        return False

    def return_a_movie(self, movie_id, client_id):
        if len(self.__rentals) != 0:
            maximum_date = date(9999, 12, 31)
            for rental in self.__rentals:
                if rental.movie_id == movie_id and rental.client_id == client_id and \
                        rental.returned_date == maximum_date:
                    rental.returned_date = date.today()
                    self.__rentals.remove(rental)
                    break
        else:
            raise RepositoryException("Can not return this movie! Invalid data!")

    def get_all_rentals_from_list(self):
        """
            Adds to the list of all_rentals_done the rentals of which movies and clients haven't been removed from lists
        """
        all_rentals_done = []
        for rental in self.__history:
            if rental.movie_id in self.__movie_repository.get_all_movies_from_list() and rental.client_id in self.__client_repository.get_all_clients_from_list():
                all_rentals_done.append(rental)
        return all_rentals_done

    def __len__(self):
        return len(self.__rentals)

    def __str__(self):
        list_of_rentals = ""
        for rental in self.__rentals:
            list_of_rentals += rental
            list_of_rentals += "\n"

        return list_of_rentals

    """
        Functions for CREATING STATISTICS
    """

    """
        1. FUNCTIONS FOR GETTING THE MOST RENTED MOVIES
    """
    def find_ids_of_rented_movies(self):
        """
        :return: A list of the ids of the rented movies, arranged in descending order with regard to the number of days
        they have been rented
        """
        verified_movies = []
        days_for_movies = []
        maximum_date = date(9999, 12, 31)

        for rental in self.__history:
            if rental.movie_id not in verified_movies:
                verified_movies.append(rental.movie_id)
                if rental.returned_date != maximum_date:
                    days_for_movies.append((rental.returned_date - rental.rented_date).days + 1)
                else:
                    today = date.today()
                    days_for_movies.append((today - rental.rented_date).days + 1)

            else:
                if rental.returned_date != maximum_date:
                    days_for_movies[verified_movies.index(rental.movie_id)] = \
                        days_for_movies[verified_movies.index(rental.movie_id)] + \
                        (rental.returned_date - rental.rented_date).days + 1
                else:
                    today = date.today()
                    days_for_movies[verified_movies.index(rental.movie_id)] = \
                        days_for_movies[verified_movies.index(rental.movie_id)] + \
                        (today - rental.rented_date).days + 1

        for i in range(0, len(days_for_movies)):
            for j in range(i+1, len(days_for_movies)):
                if days_for_movies[i] < days_for_movies[j]:
                    auxiliary = days_for_movies[i]
                    days_for_movies[i] = days_for_movies[j]
                    days_for_movies[j] = days_for_movies[i]

                    auxiliary = verified_movies[i]
                    verified_movies[i] = verified_movies[j]
                    verified_movies[j] = auxiliary

        return verified_movies

    def find_titles_of_rented_movies(self, movie_ids_list: list):
        list_of_names_of_most_rented_movies = []

        for movie in self.__movie_repository.get_all_movies_from_list():
            if movie.movie_id in movie_ids_list and movie.title not in list_of_names_of_most_rented_movies:
                list_of_names_of_most_rented_movies.append(movie.title)

        return list_of_names_of_most_rented_movies

    def most_rented_movies(self):
        return self.find_titles_of_rented_movies(self.find_ids_of_rented_movies())

    """
        2.FUNCTIONS FOR GETTING THE MOST ACTIVE CLIENTS
    """
    def get_ids_of_clients(self):
        """
        :return: A list of ids of the clients, sorted in descending order with regard to the number of movies' rented
        days
        """
        verified_clients = []
        days_for_movies = []
        maximum_date = date(9999, 12, 31)

        for rental in self.__history:
            if rental.client_id not in verified_clients:
                verified_clients.append(rental.client_id)
                if rental.returned_date != maximum_date:
                    days_for_movies.append((rental.returned_date - rental.rented_date).days + 1)
                else:
                    today = date.today()
                    days_for_movies.append((today - rental.rented_date).days + 1)

            else:
                if rental.returned_date != maximum_date:
                    days_for_movies[verified_clients.index(rental.client_id)] = \
                        days_for_movies[verified_clients.index(rental.client_id)] + \
                        (rental.returned_date - rental.rented_date).days + 1
                else:
                    today = date.today()
                    days_for_movies[verified_clients.index(rental.client_id)] = \
                        days_for_movies[verified_clients.index(rental.client_id)] + \
                        (today - rental.rented_date).days + 1

        for i in range(0, len(days_for_movies)):
            for j in range(i + 1, len(days_for_movies)):
                if days_for_movies[i] < days_for_movies[j]:
                    auxiliary = days_for_movies[i]
                    days_for_movies[i] = days_for_movies[j]
                    days_for_movies[j] = days_for_movies[i]

                    auxiliary = verified_clients[i]
                    verified_clients[i] = verified_clients[j]
                    verified_clients[j] = auxiliary

        return verified_clients

    def get_names_of_most_active_clients(self, clients_names: list):
        list_of_names_of_most_active_clients = []

        for client in self.__client_repository.get_all_clients_from_list():
            if client.client_id in clients_names and client.name not in list_of_names_of_most_active_clients:
                list_of_names_of_most_active_clients.append(client.name)

        return list_of_names_of_most_active_clients

    def most_active_clients(self):
        return self.get_names_of_most_active_clients(self.get_ids_of_clients())

    """
        3.FUNCTIONS FOR GETTING LATE RENTALS
    """
    def late_rentals(self):
        list_of_late_rentals = []
        days_of_delay = []

        date_today = date.today()
        for rental in self.__rentals:
            if rental.due_date < date_today:
                list_of_late_rentals.append(rental)
                days_of_delay.append((date_today - rental.due_date).days + 1)

        for i in range(0, len(days_of_delay)):
            for j in range(i+1, len(days_of_delay)):
                if days_of_delay[i] < days_of_delay[j]:
                    auxiliary = days_of_delay[i]
                    days_of_delay[i] = days_of_delay[j]
                    days_of_delay[j] = auxiliary

                    auxiliary = list_of_late_rentals[i]
                    list_of_late_rentals[i] = list_of_late_rentals[j]
                    list_of_late_rentals[j] = auxiliary

        return list_of_late_rentals

def generate_rentals(movie_repository: MovieRepository, client_repository: ClientRepository):
    list_of_rentals = []

    ids = [1000, 1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009,
           1010, 1011, 1012, 1013, 1014, 1015, 1016, 1017, 1018, 1019]
    movies = movie_repository.get_all_movies_from_list()
    clients = client_repository.get_all_clients_from_list()

    number_of_rentals = 0

    while number_of_rentals != 20:
        rental_id = ids[number_of_rentals]

        movie = movies[number_of_rentals]
        client = clients[number_of_rentals]
        movie_id = movie.movie_id
        client_id = client.client_id

        """rented_date creation"""
        end_date = date.today()
        start_date = end_date - timedelta(days=22)
        rented_date = end_date - (end_date - start_date) * random.random()

        """due_date creation"""
        start_date = date.today()
        end_date = start_date + timedelta(days=20)
        due_date = start_date + (end_date - start_date) * random.random()

        returned_date = date(9999, 12, 31)

        rental = Rental(rental_id, movie_id, client_id, rented_date, due_date, returned_date)
        list_of_rentals.append(rental)
        number_of_rentals = number_of_rentals + 1

    return list_of_rentals
