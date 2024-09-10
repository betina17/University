import unittest

from src.domain.movie import Movie
from src.repository.movie_repo import MovieRepository

class Update_movie_tests(unittest.TestCase):
    def setUp(self) -> None:
        print("Set up")

    def tearDown(self) -> None:
        print("Tear down")

    def test_update_movie_1(self):
        print("test")
        """
            First, we update the movie with the id = 1891
        """
        first_movie = Movie(1891, "Avatar", "indeed beautiful sights and impactful message", "action")
        second_movie = Movie(1891, "Annabella", "horrific and terrifying", "horror")
        movie_repo = MovieRepository()
        movie_repo.add_movie(first_movie)

        movie_repo_for_test = MovieRepository()
        movie_repo_for_test.add_movie(second_movie)

        movie_repo.update_movie(second_movie)

        self.assertEqual(movie_repo.get_all_movies_from_list(), movie_repo_for_test.get_all_movies_from_list())

    def test_update_movie_2(self):
        print("test")
        """
            And now, we try to update the movie with the id = 2334, which is not part of our list
        """
        first_movie = Movie(1891, "Avatar", "indeed beautiful sights and impactful message", "action")
        second_movie = Movie(2334, "Annabella", "horrific and terrifying", "horror")
        movie_repo = MovieRepository()
        movie_repo.add_movie(first_movie)

        movie_repo_for_test = MovieRepository()
        movie_repo_for_test.add_movie(second_movie)

        movie_repo.update_movie(second_movie)
        self.assertEqual(movie_repo.get_all_movies_from_list(), movie_repo_for_test.get_all_movies_from_list())