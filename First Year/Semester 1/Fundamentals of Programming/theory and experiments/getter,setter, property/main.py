class expenses:
    def __init__(self, day: int):
        self.__day = day


    def day_getter(self):
        return self.__day


    def day_setter(self, new_day):
        self.__day = new_day
        return
 #NU FAC ASA
    a = expenses.day()
    expenses.day_setter() = a
     #aici functiile astea se numesc metode acum. daca scriu asa, cu getter si setter, fara proprietate, observi ca trb sa precizez la fiecare operatie ce fel de metoda
    #folosesc, daca getter sau setter. daac folosesc functie si setter, atunci nu mai trb precizat cu _setter sau _getter(expenses.day_getter), ci se intelege de la
    #sine, adica programul intelege, ce proprietate a variabilei day o sa folosesti, adica proprietatea de getter sau de setter

class Expenses:
    def __init__(self, day: int):
        self.__day = day
#FAC ASA
    @property  #ASTA E GETTERU
    def day(self):
        return self.__day

    @day.setter  #ASTA E SETTERU
    def day(self, new_day):
        self.__day = new_day


a = Expenses.day
