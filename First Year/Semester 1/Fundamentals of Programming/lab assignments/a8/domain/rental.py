from src.domain.validator_exceptions import ValidatorException
from datetime import date

class Rental:
    def __init__(self, rental_id: int, movie_id: int, client_id: int, rented_date, due_date, returned_date):
        self.__rental_id = rental_id
        self.__movie_id = movie_id
        self.__client_id = client_id
        self.__rented_date = rented_date
        self.__due_date = due_date
        self.__returned_date = returned_date

    @property
    def rental_id(self):
        return self.__rental_id
    @property
    def movie_id(self):
        return self.__movie_id
    @property
    def client_id(self):
        return self.__client_id
    @property
    def rented_date(self):
        return self.__rented_date
    @property
    def due_date(self):
        return self.__due_date
    @property
    def returned_date(self):
        return self.__returned_date
    @returned_date.setter
    def returned_date(self, new_date):
        self.__returned_date = new_date

    @rented_date.setter
    def rented_date(self, new_date):
        self.__rented_date = new_date

    def __len__(self):
        if self.__returned_date is not None:
            return (self.__returned_date - self.__rented_date).days + 1
        else:
            today = date.today()
            return (today - self.__rented_date).days + 1

    def __eq__(self, other_rental):
        if not isinstance(other_rental, Rental):
            return False
        return self.__rental_id == other_rental.__rental_id

    def __str__(self):
        return "Rental-> " + str(self.__rental_id) + "\nClient ID:" + str(self.__client_id) + ", Movie ID:" \
               + str(self.__movie_id) + "\nPeriod of rental: " + self.__rented_date.strftime("%Y-%m-%d") \
               + " to " + self.__returned_date.strftime("%Y-%m-%d") + "\n"
    def __repr__(self):
        return str(self)

class RentalValidator:
    def validate(self, rental):

        _list_of_errors = []
        date_today = date.today()
        if rental.rented_date < date_today:
            _list_of_errors.append("Rent starts in the future!")
        if len(_list_of_errors) > 0:
            raise ValidatorException(_list_of_errors)