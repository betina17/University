import unittest

from src.domain.movie import Movie
from src.repository.movie_repo import MovieRepository

class Remove_movie_tests(unittest.TestCase):
    def setUp(self) -> None:
        print("Set up")

    def tearDown(self) -> None:
        print("Tear down")

    def test_remove_movie_1(self):
        print("test")
        """
            First, we remove the movie with the id = 1891
        """
        first_movie = Movie(1891, "Avatar", "indeed beautiful sights and impactful message", "action")
        movie_repo = MovieRepository()
        movie_repo.add_movie(first_movie)
        initial_length = len(movie_repo)
        movie_repo.remove_movie(first_movie.movie_id)
        self.assertEqual(len(movie_repo), initial_length - 1)

    def test_remove_movie_2(self):
        print("test")
        """
            And now, we try to remove the movie with the id = 2334, which is not part of our list
        """
        first_movie = Movie(1891, "Avatar", "indeed beautiful sights and impactful message", "action")
        movie_repo = MovieRepository()
        movie_repo.add_movie(first_movie)
        initial_length = len(movie_repo)
        second_movie = Movie(2334, "Annabella", "horrific and terrifying", "horror")
        movie_repo.remove_movie(second_movie.movie_id)
        self.assertEqual(len(movie_repo), initial_length - 1)