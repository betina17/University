from src.domain.movie import Movie
from src.repository.repository_exception import RepositoryException
import re

class MovieRepository:
    def __init__(self):
        self.__movies = []
    def find(self, movie_id):
        for movie in self.__movies:
            if movie_id == movie.movie_id:
                return movie

        return None

    """    
    def get_movie(self, id: int):
        return self.__movies[id]
    """

    def add_movie(self, new_movie: Movie):
        """
        Adds a new movie to the list if the id of the new movie is not found within the others from the list
        Otherwise, it raises a RepositoryException
        """
        if self.find(new_movie.movie_id) is not None:
            raise RepositoryException("Movie having id: " + str(new_movie.movie_id) + " is already in list!")
        self.__movies.append(new_movie)

    def remove_movie(self, movie_id):
        """
        Removes a movie from the list if its id is found within the list
        Otherwise, it raises a RepositoryException
        """
        movie_to_be_removed = self.find(movie_id)
        if movie_to_be_removed is None:
            raise RepositoryException("Movie is not part of the list!")
        self.__movies.remove(movie_to_be_removed)

    def get_all_movies_from_list(self):
        return self.__movies

    def update_movie(self, other_movie: Movie):
        """
         Updates the list by replacing all characteristics of the movie with the same id
         Raises RepositoryException in case the given movie is not part of the initial list
        """

        movie_to_be_updated = self.find(other_movie.movie_id)
        if movie_to_be_updated is None:
            raise RepositoryException("Movie to be updated is not part of the list!")
        position_in_list = self.__movies.index(movie_to_be_updated)
        self.__movies.remove(movie_to_be_updated)
        self.__movies.insert(position_in_list, other_movie)

    def __len__(self):
        return len(self.__movies)

    def __str__(self):
        list_of_movies = ""
        for movie in self.__movies:
            list_of_movies += movie
            list_of_movies += "\n"

        return list_of_movies

    def find_movies_matching_id(self, movie_id: str):
        list_of_movies_matching_id = []
        for movie in self.__movies:
            if re.search(movie_id, str(movie.movie_id), re.IGNORECASE):
                list_of_movies_matching_id.append(movie)

        if len(list_of_movies_matching_id) == 0:
            raise RepositoryException("There is no movie with matching id!")

        return list_of_movies_matching_id

    def find_movies_matching_title(self, title: str):
        list_of_movies_matching_title = []
        for movie in self.__movies:
            if re.search(title, movie.title, re.IGNORECASE):
                list_of_movies_matching_title.append(movie)

        if len(list_of_movies_matching_title) == 0:
            raise RepositoryException("There is no movie with matching title!")

        return list_of_movies_matching_title

    def find_movies_matching_description(self, description: str):
        list_of_movies_matching_description = []
        for movie in self.__movies:
            if re.search(description, movie.description, re.IGNORECASE):
                list_of_movies_matching_description.append(movie)

        if len(list_of_movies_matching_description) == 0:
            raise RepositoryException("There is no movie with matching description!")

        return list_of_movies_matching_description

    def find_movies_matching_genre(self, genre: str):
        list_of_movies_matching_genre = []
        for movie in self.__movies:
            if re.search(genre, movie.genre, re.IGNORECASE):
                list_of_movies_matching_genre.append(movie)

        if len(list_of_movies_matching_genre) == 0:
            raise RepositoryException("There is no movie with matching genre!")

        return list_of_movies_matching_genre

def generate_movies():
    list_of_movies = []
    list_of_movies.append(Movie(1000, "Commando", "there would be nice to have a description, but I am a little bit lazy", "action"))
    list_of_movies.append(Movie(1001, "The day after tomorrow", "there would be nice to have a description, but I am a little bit lazy", "action"))
    list_of_movies.append(Movie(1002, "Shrek", "there would be nice to have a description, but I am a little bit lazy", "animation"))
    list_of_movies.append(Movie(1003, "Rango", "there would be nice to have a description, but I am a little bit lazy", "animation"))
    list_of_movies.append(Movie(1004, "The Notebook", "there would be nice to have a description, but I am a little bit lazy", "romance"))
    list_of_movies.append(Movie(1005, "IT", "there would be nice to have a description, but I am a little bit lazy", "horror"))
    list_of_movies.append(Movie(1006, "Zootopia", "there would be nice to have a description, but I am a little bit lazy", "animation"))
    list_of_movies.append(Movie(1007, "How to lose a guy in 10 days", "there would be nice to have a description, but I am a little bit lazy", "comedy"))
    list_of_movies.append(Movie(1008, "Sleepless in Seattle", "there would be nice to have a description, but I am a little bit lazy", "comedy"))
    list_of_movies.append(Movie(1009, "The terminator", "there would be nice to have a description, but I am a little bit lazy", "science fiction"))
    list_of_movies.append(Movie(1010, "Young Royals", "there would be nice to have a description, but I am a little bit lazy", "romance"))
    list_of_movies.append(Movie(1011, "Heartstopper", "there would be nice to have a description, but I am a little bit lazy", "romance"))
    list_of_movies.append(Movie(1012, "Trolii", "there would be nice to have a description, but I am a little bit lazy", "animation"))
    list_of_movies.append(Movie(1013, "Tarzan", "there would be nice to have a description, but I am a little bit lazy", "animation"))
    list_of_movies.append(Movie(1014, "Mogli", "there would be nice to have a description, but I am a little bit lazy", "animation"))
    list_of_movies.append(Movie(1015, "1917", "there would be nice to have a description, but I am a little bit lazy", "war"))
    list_of_movies.append(Movie(1016, "Good will hunting", "there would be nice to have a description, but I am a little bit lazy", "drama"))
    list_of_movies.append(Movie(1017, "Hachiko", "there would be nice to have a description, but I am a little bit lazy", "drama"))
    list_of_movies.append(Movie(1018, "Avatar: The way of water", "there would be nice to have a description, but I am a little bit lazy", "fantasy"))
    list_of_movies.append(Movie(1019, "Puss in boots", "there would be nice to have a description, but I am a little bit lazy", "fantasy"))

    return list_of_movies