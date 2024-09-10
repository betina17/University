import unittest

from src.domain.movie import Movie
from src.repository.movie_repo import MovieRepository

class Add_movie_tests(unittest.TestCase):
    def setUp(self) -> None:
        print("Set up")

    def tearDown(self) -> None:
        print("Tear down")

    def test_add_movie_1(self):
        print("test")
        """
            First, we verify if we can add a new movie to the list 
        """
        first_movie = Movie(1891, "Avatar", "indeed beautiful sights and impactful message", "action")
        movie_repo = MovieRepository()
        initial_length = len(movie_repo)
        movie_repo.add_movie(first_movie)
        self.assertEqual(len(movie_repo), initial_length + 1)

        """
            And here, we try to add the same movie for the second time, which should fail
        """
        length_after_first_addition = len(movie_repo)
        movie_repo.add_movie(first_movie)
        self.assertEqual(len(movie_repo), length_after_first_addition + 1)

    def test_add_movie_2(self):
        print("test")
        second_movie = Movie(1234, "Five feet apart", "an emotional, but tragic love story", "romance")
        movie_repo = MovieRepository()
        initial_length = len(movie_repo)
        movie_repo.add_movie(second_movie)
        self.assertEqual(len(movie_repo), initial_length + 1)

