class distance:
    def __init__(self,km1:int):
        self.km = km1
    def __add__(self, km2):
        total = distance(self.km)
        total.km = self.km + km2.km #km2.km e ca si self.km = km2, si o sa ai total =km1(care e self.km)+km2(care e km2.km)
        #km2.km ia valoarea parametrului functiei add, aadica a lui km2, cum self.km ia val param init, adica km1
        return total
    def __str__(self):
        return 'total=' + str(self.km)


if __name__ == "__main__":
    d1 = distance(2)
    d2 = distance(3)
    total = d1+d2
    print(total)
    #interesting