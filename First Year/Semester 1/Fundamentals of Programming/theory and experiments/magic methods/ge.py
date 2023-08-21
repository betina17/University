class distance:
    def __init__(self,km1:int):
        self.km = km1
    def __ge__(self, km2):
        val1 = self.km*12
        val2 = km2.km*12
        if val1>=val2:
            return True
        else:
            return False

if __name__ == "__main__":
    d1 = distance(2)
    d2 = distance(4)
    print(d1>=d2)

    #interesant
