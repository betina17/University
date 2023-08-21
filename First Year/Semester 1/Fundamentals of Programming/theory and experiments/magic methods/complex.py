class Complex:
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    def __complex__(self):
        return complex(self.real, self.imag)
if __name__ == "__main__":
    nr = Complex(3,4)
    print(complex(nr))

    #foarte interesant