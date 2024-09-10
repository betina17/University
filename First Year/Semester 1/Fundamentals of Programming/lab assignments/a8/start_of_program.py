from services.rental_services import RentalServices
from services.client_services import ClientServices
from services.movie_services import MovieServices

from repository.rental_repo import RentalRepository
from repository.client_repo import ClientRepository
from repository.movie_repo import MovieRepository

from ui.console import UI

from repository.client_repo import generate_clients
from repository.movie_repo import generate_movies
from repository.rental_repo import generate_rentals

from domain.movie import MovieValidator
from domain.client import ClientValidator
from domain.rental import RentalValidator

movie_repository = MovieRepository()
movie_validator = MovieValidator()

list_of_movies = []
list_of_movies = generate_movies()
for movie in list_of_movies:
    movie_repository.add_movie(movie)

movie_services = MovieServices(movie_repository, movie_validator)

client_repository = ClientRepository()
client_validator = ClientValidator()

list_of_clients = []
list_of_clients = generate_clients()
for client in list_of_clients:
    client_repository.add_client(client)

client_services = ClientServices(client_repository, client_validator)

rental_repository = RentalRepository(movie_repository, client_repository)
rental_validator = RentalValidator()

list_of_rentals = []
list_of_rentals = generate_rentals(movie_repository, client_repository)
for rental in list_of_rentals:
    rental_repository.add_rental(rental)

rental_services = RentalServices(rental_repository, rental_validator)

console = UI(movie_services, client_services, rental_services)

console.start_ui()

