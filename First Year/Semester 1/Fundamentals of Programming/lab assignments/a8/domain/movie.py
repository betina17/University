from src.domain.validator_exceptions import ValidatorException


class Movie:
    def __init__(self, movie_id: int, title: str, description: str, genre: str):
        self.__movie_id = movie_id
        self.__title = title
        self.__description = description
        self.__genre = genre

    @property
    def movie_id(self):
        return self.__movie_id

    @property
    def title(self):
        return self.__title

    @property
    def description(self):
        return self.__description

    @property
    def genre(self):
        return self.__genre

    @movie_id.setter
    def movie_id(self, new_id: int):
        self.__movie_id = new_id

    @title.setter
    def title(self, new_title):
        self.__title = new_title

    @description.setter
    def description(self, new_description):
        self.__description = new_description

    @genre.setter
    def genre(self, new_genre):
        self.__genre = new_genre

    def __str__(self):
        return "Movie->\n" + " ID: " + str(self.__movie_id) + "\n Title: " + self.__title + "\n Genre: " + self.__genre \
               + "\n Description: " + self.__description + "\n"

    def __repr__(self):
        return str(self)

    def __eq__(self, other_movie):
        if not isinstance(other_movie, Movie):
            return False
        return self.__movie_id == other_movie.__movie_id


class MovieValidator:
    def validate(self, movie):
        """
        Validate if the provided movie is considered to be valid
        movie - instance of Movie type
        :return: list of validation errors. If the movie is valid, it returns an empty list.
        """



        _list_of_errors = []
        _list_of_genres = ["action", "adventure", "comedy", "drama", "fantasy", "horror",
                           "musicals", "mystery", "romance", "science fiction", "sports", "thriller", "western", "historical",
                           "animation", "crime", "biopics", "war"]
        if len(movie.title) < 2:
            _list_of_errors.append("Movie title is incomplete!")
        if len(movie.description) < 3:
            _list_of_errors.append("Description too short according to rules!")
        if movie.genre not in _list_of_genres:
            _list_of_errors.append("Movie genre is nonexistent!")
        if len(_list_of_errors) > 0:
            raise ValidatorException(_list_of_errors)
        return True