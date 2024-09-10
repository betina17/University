import unittest

from src.domain.movie import Movie

class MovieTests(unittest.TestCase):
    def setUp(self) -> None:
        print("Set up")

    def tearDown(self) -> None:
        print("Tear down")

    def test_movie_class_1(self):
        print("test")
        first_movie = Movie(1212, "Annabella", "gone crazy over this one", "horror")
        self.assertEqual(first_movie.movie_id, 1212)
        self.assertEqual(first_movie.title, "Annabella")
        self.assertEqual(first_movie.description, "gone crazy over this one")
        self.assertEqual(first_movie.genre, "horror")

        first_movie.movie_id = 1213
        self.assertEqual(first_movie.movie_id, 1213)
        first_movie.title = "Frozen"
        self.assertEqual(first_movie.title, "Frozen")
        first_movie.description = "a really strong relationship between sisters is portraied"
        self.assertEqual(first_movie.description, "a really strong relationship between sisters is portraied")
        first_movie.genre = "animation"
        self.assertEqual(first_movie.genre, "animation")

    def test_movie_class_2(self):
        print("test")
        second_movie = Movie(1200, "Hangover", "impossible to forget", "comedy")
        self.assertEqual(second_movie.movie_id, 1212)
        self.assertEqual(second_movie.title, "Annabella")
        self.assertEqual(second_movie.description, "gone crazy over this one")
        self.assertEqual(second_movie.genre, "horror")


