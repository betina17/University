from src.services.client_services import ClientServices
from src.services.movie_services import MovieServices
from src.services.rental_services import RentalServices
from datetime import date
from src.domain.rental import Rental
class UI:
    def __init__(self, movie_services: MovieServices, client_services: ClientServices, rental_services: RentalServices):
        self.__client_services = client_services
        self.__movie_services = movie_services
        self.__rental_services = rental_services

    def menu(self):
        print("Choose an option from below:")
        print("1.Manage clients and movies.")
        print("2.Rent or return a movie.")
        print("3.Search for clients or movies using any one of their fields (e.g. movies can be searched for using id, "
              "title, description or genre).")
        print("4.Create statistics")
        print("0.Exit the program")
        print()

    def menu_for_managing_clients_and_movies(self):
        while True:
            try:
                print()
                print("Choose to work with:")
                print("1.Movies")
                print("2.Clients")
                print("0.GO BACK")
                category = input("Write your option here:")
                MOVIES = "1"
                CLIENTS = "2"
                _GO_BACK = "0"
                print()
                if category == MOVIES:
                    try:
                        print("Choose an option from below:")
                        print("1.Add a new movie to list")
                        print("2.Remove movie from list")
                        print("3.List all movies")
                        print("4.Update a movie")
                        print("0.GO BACK")
                        print()
                        option_chosen = input("Write down your option:")
                        print()

                        _ADD_NEW_MOVIE = "1"
                        _REMOVE_MOVIE = "2"
                        _LIST_ALL_MOVIES = "3"
                        _UPDATE_MOVIE = "4"
                        _GO_BACK = "0"

                        if option_chosen == _ADD_NEW_MOVIE:
                            print("Give movie's:")
                            id = int(input("ID:"))
                            title = input("Title:")
                            description = input("Description:")
                            genre = input("Genre:")
                            self.__movie_services.add_movie(id, title, description, genre)

                        elif option_chosen == _REMOVE_MOVIE:
                            print("Give movie's:")
                            id = int(input("ID:"))
                            self.__movie_services.remove_movie(id)

                        elif option_chosen == _LIST_ALL_MOVIES:
                            list_of_movies = self.__movie_services.get_all_movies_from_list()
                            for movie in list_of_movies:
                                print(repr(movie))
                            print()

                        elif option_chosen == _UPDATE_MOVIE:
                            print("Give movie's:")
                            id = int(input("ID:"))
                            title = input("Title:")
                            description = input("Description:")
                            genre = input("Genre:")
                            self.__movie_services.update_movie(id, title, description, genre)

                        elif option_chosen == _GO_BACK:
                            print()
                            break

                        else:
                            print("Invalid option introduced!")
                    except ValueError:
                        print("Invalid option introduced!")

                elif category == CLIENTS:
                    try:
                        print("Choose an option from below:")
                        print("1.Add a new client to list")
                        print("2.Remove client from list")
                        print("3.List all clients")
                        print("4.Update a client")
                        print("0.GO BACK")
                        print()
                        option_chosen = input("Write down your option:")
                        print()

                        _ADD_NEW_CLIENT = "1"
                        _REMOVE_CLIENT = "2"
                        _LIST_ALL_CLIENTS = "3"
                        _UPDATE_CLIENT = "4"
                        _GO_BACK = "0"

                        if option_chosen == _ADD_NEW_CLIENT:
                            print("Give client's:")
                            id = int(input("ID:"))
                            name = input("Name:")
                            self.__client_services.add_client(id, name)

                        elif option_chosen == _REMOVE_CLIENT:
                            print("Give client's:")
                            id = int(input("ID:"))
                            self.__client_services.remove_client(id)

                        elif option_chosen == _LIST_ALL_CLIENTS:
                            list_of_clients = self.__client_services.get_all_clients_from_list()
                            for client in list_of_clients:
                                print(repr(client))
                            print()

                        elif option_chosen == _UPDATE_CLIENT:
                            print("Give client's:")
                            id = int(input("ID:"))
                            name = input("Name:")
                            self.__client_services.update_client(id, name)

                        elif option_chosen == _GO_BACK:
                            print()
                            break

                        else:
                            print("Invalid option introduced!")
                    except ValueError:
                        print("Invalid option introduced!")
                elif category == _GO_BACK:
                    break
                else:
                    print("Invalid option introduced!")
            except ValueError:
                print("Invalid option introduced!")

    def menu_for_renting_or_returning_movies(self):
        while True:
            try:
                print()
                print("Choose to:")
                print("1.Rent a movie")
                print("2.Return a movie")
                print("3.List all rentals")
                print("0.GO BACK")
                print()
                option_chosen = input("Write down your option:")
                print()

                _RENT_A_MOVIE = "1"
                _RETURN_A_MOVIE = "2"
                _LIST_ALL_RENTALS = "3"
                _GO_BACK = "0"

                if option_chosen == _RENT_A_MOVIE:
                    print("Introduce:")
                    rental_id = int(input("Rental ID:"))
                    movie_id = int(input("Movie ID:"))
                    client_id = int(input("Client ID:"))

                    year_rented_date = int(input("Year for rented date:"))
                    month_rented_date = int(input("Month for rented date:"))
                    day_rented_date = int(input("Day for rented date:"))
                    rented_date = date(year_rented_date, month_rented_date, day_rented_date)

                    """
                    rented_date = date.today()
                    """

                    year_due_date = int(input("Year for due date:"))
                    month_due_date = int(input("Month for due date:"))
                    day_due_date = int(input("Day for due date:"))
                    due_date = date(year_due_date, month_due_date, day_due_date)

                    returned_date = date(9999, 12, 31)
                    self.__rental_services.rent_a_movie(rental_id, movie_id, client_id, rented_date, due_date,
                                                        returned_date)


                elif option_chosen == _RETURN_A_MOVIE:
                    print("Introduce:")
                    movie_id = int(input("Movie ID:"))
                    client_id = int(input("Client ID:"))
                    self.__rental_services.return_a_movie(movie_id, client_id)

                elif option_chosen == _LIST_ALL_RENTALS:
                    list_of_rentals = self.__rental_services.get_all_rentals_from_list()
                    for rental in list_of_rentals:
                        print(str(rental))
                    print("\n")

                elif option_chosen == _GO_BACK:
                    print()
                    break
                else:
                    print("Invalid option introduced!")
            except ValueError:
                print("Invalid option introduced!") #aicea sare

    def menu_for_searching_movies_or_clients(self):
        while True:
            try:
                print()
                print("Choose to search:")
                print("1.Movies")
                print("2.Clients")
                print("0.GO BACK")
                print()
                search_option = input("Introduce your option here:")

                _SEARCH_MOVIES = "1"
                _SEARCH_CLIENTS = "2"
                _GO_BACK = "0"

                if search_option == _SEARCH_MOVIES:
                    self.search_movies_menu()
                elif search_option == _SEARCH_CLIENTS:
                    self.search_clients_menu()
                elif search_option == _GO_BACK:
                    print()
                    break
                else:
                    print("Invalid option introduced!")
            except TypeError:
                print("Invalid option introduced!")


    def search_movies_menu(self):
        while True:
            try:
                print("\nAvailable keys for movies are:\n 1.movie_id\n 2.title\n "
                      "3.description\n 4.genre\n 0.GO BACK")
                key_for_searching = input("Introduce the key after which the search will be done:")
                _movie_id = "1"
                _title = "2"
                _description = "3"
                _genre = "4"
                _GO_BACK = "0"

                if key_for_searching == _movie_id:
                    id = input("ID:")
                    list_of_movies_matching_id = self.__movie_services.find_movies_matching_id(id)
                    print("\nAll matching results are:")
                    for movie in list_of_movies_matching_id:
                        print(repr(movie))

                elif key_for_searching == _title:
                    title = input("Title:")
                    list_of_movies_matching_title = self.__movie_services.find_movies_matching_title(title)
                    print("\nAll matching results are:")
                    for movie in list_of_movies_matching_title:
                        print(repr(movie))

                elif key_for_searching == _description:
                    description = input("Description:")
                    list_of_movies_matching_description = \
                        self.__movie_services.find_movies_matching_description(description)
                    print("\nAll matching results are:")
                    for movie in list_of_movies_matching_description:
                        print(repr(movie))

                elif key_for_searching == _genre:
                    genre = input("Genre:")
                    list_of_movies_matching_genre = \
                        self.__movie_services.find_movies_matching_genre(genre)
                    print("\nAll matching results are:")
                    for movie in list_of_movies_matching_genre:
                        print(repr(movie))
                    pass
                elif key_for_searching == _GO_BACK:
                    break
                else:
                    print("Invalid option introduced!")
            except TypeError:
                print("Invalid option introduced!")

    def search_clients_menu(self):
        while True:
            try:
                print("\nAvailable keys for clients are:\n 1.client_id \n 2.Name \n 0.GO BACK")
                key_for_searching = input("Introduce the key after which the search will be done:")
                _client_id = "1"
                _name = "2"
                _GO_BACK = "0"
                if key_for_searching == _client_id:
                    id = input("ID:")
                    list_of_clients_matching_name = self.__client_services.search_clients_matching_id(id)
                    print("\nAll matching results are:")
                    for client in list_of_clients_matching_name:
                        print(repr(client))

                elif key_for_searching == _name:
                    name = input("Name:")
                    list_of_clients_matching_name = self.__client_services.search_clients_matching_name(name)
                    print("\nAll matching results are:")
                    for client in list_of_clients_matching_name:
                        print(repr(client))

                elif key_for_searching == _GO_BACK:
                    break
                else:
                    print("Invalid option introduced!")
            except TypeError:
                print("Invalid option introduced!")

    def menu_for_creating_statistics(self):
        while True:
            try:
                print()
                print("Choose to create statistics for:")
                print("1. Most rented movies")
                print("2. Most active clients")
                print("3. Late rentals")
                print("0. GO BACK")
                print()

                create_statistics_option = input("Introduce your option for statistics here:")
                print()

                _MOST_RENTED_MOVIES = "1"
                _MOST_ACTIVE_CLIENTS = "2"
                _LATE_RENTALS = "3"
                _GO_BACK = "0"

                if create_statistics_option == _MOST_RENTED_MOVIES:
                    list_of_movies = self.__rental_services.most_rented_movies()
                    index = 1
                    print("Most rented movies are:")
                    for movie in list_of_movies:
                        print(str(index) + ". " + movie)
                        index = index + 1
                    print()

                elif create_statistics_option == _MOST_ACTIVE_CLIENTS:
                    list_of_clients = self.__rental_services.most_active_clients()
                    index = 1
                    print("Most active clients are:")
                    for client in list_of_clients:
                        print(str(index) + ". " + client)
                        index = index + 1
                    print()

                elif create_statistics_option == _LATE_RENTALS:
                    list_of_late_rentals = self.__rental_services.late_rentals()
                    if len(list_of_late_rentals) != 0:
                        index = 1
                        print("Late rentals:")
                        for rental in list_of_late_rentals:
                            print(str(index) + ". " + str(rental))
                            index = index + 1
                        print()
                    else:
                        print("There are no late rentals!")

                elif create_statistics_option == _GO_BACK:
                    print()
                    break

                else:
                    print("Invalid option introduced!")
            except TypeError:
                print("Invalid option introduced!")

    def start_ui(self):
        while True:
            try:
                self.menu()
                option_for_execution = input("Introduce the number of the option to be implemented:")
                _MANAGE_MOVIES_AND_CLIENTS = "1"
                _RENT_OR_RETURN_MOVIE = "2"
                _SEARCH_FOR_CLIENTS_OR_MOVIES = "3"
                _CREATE_STATISTICS = "4"
                _EXIT = "0"

                if option_for_execution == _MANAGE_MOVIES_AND_CLIENTS:
                    self.menu_for_managing_clients_and_movies()

                elif option_for_execution == _RENT_OR_RETURN_MOVIE:
                    self.menu_for_renting_or_returning_movies()

                elif option_for_execution == _SEARCH_FOR_CLIENTS_OR_MOVIES:
                    self.menu_for_searching_movies_or_clients()

                elif option_for_execution == _CREATE_STATISTICS:
                    self.menu_for_creating_statistics()

                elif option_for_execution == _EXIT:
                    print("BYE BYE!")
                    break
                else:
                    print("Invalid option introduced!")
            except ValueError:
                print("Invalid option introduced!")
