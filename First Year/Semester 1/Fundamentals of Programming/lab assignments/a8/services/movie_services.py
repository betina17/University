from src.domain.movie import Movie
from src.domain.movie import MovieValidator
from src.repository.movie_repo import MovieRepository

class MovieServices:
    def __init__(self, movie_repository: MovieRepository, movie_validator: MovieValidator):
        self.__movie_repository = movie_repository
        self.__movie_validator = movie_validator

    def add_movie(self, movie_id, title, description, genre):
        """
            1. We build the movie instance
            2. Validate it
            3. Add the movie instance to the list
        """
        new_movie = Movie(movie_id, title, description, genre)
        self.__movie_validator.validate(new_movie)
        self.__movie_repository.add_movie(new_movie)

    def remove_movie(self, movie_id):
        self.__movie_repository.remove_movie(movie_id)

    def get_all_movies_from_list(self):
        return self.__movie_repository.get_all_movies_from_list()

    def update_movie(self, movie_id, title, description, genre):
        """
            As parameters, we get the id of the movie to be updated and new characteristics of the film
            1.We build the movie replacer instance
            2.Validate it
            3.Update the movie with the same id if found
        """
        movie_replacer = Movie(movie_id, title, description, genre)
        self.__movie_validator.validate(movie_replacer)
        self.__movie_repository.update_movie(movie_replacer)

    def find_movies_matching_id(self, movie_id: str):
        return self.__movie_repository.find_movies_matching_id(movie_id)

    def find_movies_matching_title(self, title: str):
        return self.__movie_repository.find_movies_matching_title(title)

    def find_movies_matching_description(self, description: str):
        return self.__movie_repository.find_movies_matching_description(description)

    def find_movies_matching_genre(self, genre: str):
        return self.__movie_repository.find_movies_matching_genre(genre)