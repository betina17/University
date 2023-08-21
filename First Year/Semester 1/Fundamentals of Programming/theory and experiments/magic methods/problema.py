"""
Create a Python class called Rectangle that represents a rectangle with a length and width. Implement the following methods using magic methods:

__init__: Initialize the length and width of the rectangle.
__str__: Return a string representation of the rectangle in the format "Rectangle(length, width)".
__eq__: Return True if two rectangles have the same length and width.
__lt__: Return True if the area of the rectangle is less than the area of another rectangle.
__add__: Return a new rectangle with a length and width equal to the sum of the lengths and widths of two rectangles.
"""
class Rectangle:
    def __init__(self, length:int, width:int):
        self.length = length
        self.width = width

    def __str__(self):
        return "Rectangle(" + str(self.length) + ", " + str(self.width) + ")"
        #return f"Rectangle({self.length}, {self.width})" asa mai puteam sa scriu

    def __eq__(self, other):
        if isinstance(other, Rectangle):
            return other.length == self.length and other.width == self.width #puteam sa scriu doar asta
        return False

    def __lt__(self, other):

        area1= self.length*self.width
        area2 = other.length*other.width
        return area1<area2

    def __add__(self, r2):
        new_rectangle = Rectangle(self.length, self.width) #construiesc obiectul asta, adica obiectul meu initial,
        #self-ul, la care o sa adaug un nou obiect, adica r2
        new_rectangle.length = self.length + r2.length
        new_rectangle.width = self.width + r2.width
        return new_rectangle

if __name__ == "__main__":
    r1 = Rectangle(2,3)
    r2 = Rectangle(3,3)
    r3 = Rectangle(2,3)
    print(r1==r2)
    print(r1==r3)
    print(r2 < r3)
    print(r1+r2)
#pt r1==r2-deci prin conditia isinstance verifica daca obiectul r2 este o instanta a clasei Rectangle-trb sa verifice asta
#pt ca puteam sa am r2=AltaClasa(2,3) care nu avea doua atribute de tip int pe care sa poata sa le compare cu cele doua atribute
#de tip int le clasei Rectangle, pe care le are obiectul r1 care e instantiat cu clasa Rectangle (primul obiect din comparatie
#se considera self-ul, adica r1, iar al doilea, adica r2, se considera other-ul). Deci cele doua obiecte pe care le comparam
#trb sa fie instantiate cu acceasi clasa, asta verifica isinstance, ca sa poata apoi eq sa compare atributele intre ele
#dupa verificare, daca ea e falsa, se returneaza automat False, daca e adev, se intra si se compara atributele pe care vrem
#sa le comparam, intre ele, si se returneaza True daca sunt egale si False daca nu

"""
The __eq__ method checks if the other object is an instance of the Rectangle class. If it is, the method compares the length
 and width attributes of the current instance (self) and the other instance to determine if they are equal. If both length
  and width attributes are equal, then the two Rectangle objects are considered equal and the method returns True. Otherwise, 
  the method returns False.
NU E NECESAR SA FOLOSESTI ISINSTANCE, dar da, e mai corect
"""

