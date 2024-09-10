from src.domain.rental import Rental
from src.domain.rental import RentalValidator
from src.repository.rental_repo import RentalRepository

class RentalServices:
    def __init__(self, rental_repository: RentalRepository, rental_validator: RentalValidator):
        self.__rental_repository = rental_repository
        self.__rental_validator = rental_validator

    def add_rental(self, new_rental: Rental):
        self.__rental_repository.add_rental(new_rental)

    def rent_a_movie(self, rental_id, movie_id, client_id, rented_date, due_date, returned_date):
        """
            1.We build the rental instance
            2.Validate it
            3.Adds the rental to the list of rentals
        """
        new_rental = Rental(rental_id, movie_id, client_id, rented_date, due_date, returned_date)
        self.__rental_validator.validate(new_rental)
        self.__rental_repository.rent_a_movie(new_rental)

    def return_a_movie(self, movie_id, client_id):
        self.__rental_repository.return_a_movie(movie_id, client_id)

    def get_all_rentals_from_list(self):
        return self.__rental_repository.get_all_rentals_from_list()

    def most_rented_movies(self):
        return self.__rental_repository.most_rented_movies()

    def most_active_clients(self):
        return self.__rental_repository.most_active_clients()

    def late_rentals(self):
        return self.__rental_repository.late_rentals()