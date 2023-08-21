import random
import timeit

def ProgramOptions():
    print('Press 1 for cocktail sort time complexity')
    print('Press 2 for comb sort time complexity')
    print('Press 3 to exit the program')
    while True:
        key = input()
        if key == "1":
            CaseOptionsCocktail()
        elif key == "2":
            CaseOptionsComb()
        elif key == "3":
            break
        else:
            print("Wrong option! Try again!")



def CreateListOfRandomIncreasingNumbers(LengthOfList, ListOfRandomIncreasingNumbers):
    FirstNrInList = random.randint(0, 100)
    ListOfRandomIncreasingNumbers.append(FirstNrInList)
    for i in range(1, LengthOfList):
        ListOfRandomIncreasingNumbers.append(ListOfRandomIncreasingNumbers[i - 1] + random.randint(1, 10))
    return ListOfRandomIncreasingNumbers


def CreateListOfRandomDecreasingNumbers(LengthOfList, ListOfRandomDecreasingNumbers):
    FirstNrInList = random.randint(90000, 100000)
    ListOfRandomDecreasingNumbers.append(FirstNrInList)
    for i in range(1, LengthOfList):
        ListOfRandomDecreasingNumbers.append(ListOfRandomDecreasingNumbers[i - 1] - random.randint(1, 10))
    return ListOfRandomDecreasingNumbers


def CaseOptionsCocktail():
    print('Press a to get the best case scenario for the sort')
    print('Press b to get the average case scenario for the sort')
    print('Press c to get the worst case scenario for the sort')
    print('Press d to get back to the menu')
    while True:
        key = input()
        LengthOfList = 300
        if key == "a":
            for i in range(0, 5):
                ListOfRandomIncreasingNumbers = []
                CreateListOfRandomIncreasingNumbers(LengthOfList, ListOfRandomIncreasingNumbers)
                t1 = timeit.default_timer()
                CocktailSortListOfRandomNaturalNumbers(ListOfRandomIncreasingNumbers)
                t2=timeit.default_timer()
                ExecutionTime=t2-t1
                print(
                    f'The time execution of the cocktail sort algorithm for the best case scenario, for a list of {LengthOfList} elements is: {ExecutionTime}')

                LengthOfList = LengthOfList * 2
        elif key == "b":
            for i in range(0, 5):
                ListOfRandomNumbers = []
                GenerateListOfRandomNumbers(LengthOfList, ListOfRandomNumbers)
                t1 = timeit.default_timer()
                CocktailSortListOfRandomNaturalNumbers(ListOfRandomNumbers)
                t2 = timeit.default_timer()
                ExecutionTime = t2 - t1
                print(
                    f'The time execution of the cocktail sort algorithm for the average case scenario, for a list of {LengthOfList} elements is: {ExecutionTime}')

                LengthOfList = LengthOfList * 2
        elif key == "c" :
            for i in range(0, 5):
                ListOfRandomDecreasingNumbers = []
                CreateListOfRandomDecreasingNumbers(LengthOfList, ListOfRandomDecreasingNumbers)
                t1 = timeit.default_timer()
                CocktailSortListOfRandomNaturalNumbers(ListOfRandomDecreasingNumbers)
                t2 = timeit.default_timer()
                ExecutionTime = t2 - t1
                print(
                        f'The time execution of the cocktail sort algorithm for the worst case scenario, for a list of {LengthOfList} elements is: {ExecutionTime}')

                LengthOfList = LengthOfList * 2
        else:
            ProgramOptions()



def CaseOptionsComb():
    print('Press a to get the best case scenario for the sort')
    print('Press b to get the average case scenario for the sort')
    print('Press c to get the worst case scenario for the sort')
    print('Press d to get back to the menu')
    while True:
        key = input()
        LengthOfList = 300
        if key == "a":
            for i in range(0, 5):
                ListOfRandomIncreasingNumbers = []
                CreateListOfRandomIncreasingNumbers(LengthOfList, ListOfRandomIncreasingNumbers)
                t1 = timeit.default_timer()
                CombSortListOfRandomNaturalNumbers(ListOfRandomIncreasingNumbers)
                t2 = timeit.default_timer()
                ExecutionTime = t2 - t1
                print(
                    f'The time execution of the comb sort algorithm for the best case scenario, for a list of {LengthOfList} elements is: {ExecutionTime}')

                LengthOfList = LengthOfList * 2
        elif key == "b":
            for i in range(0, 5):
                ListOfRandomNumbers = []
                GenerateListOfRandomNumbers(LengthOfList, ListOfRandomNumbers)
                t1 = timeit.default_timer()
                CombSortListOfRandomNaturalNumbers(ListOfRandomNumbers)
                t2 = timeit.default_timer()
                ExecutionTime = t2 - t1
                print(
                    f'The time execution of the comb sort algorithm for the average case scenario, for a list of {LengthOfList} elements is: {ExecutionTime}')

                LengthOfList = LengthOfList * 2
        elif key == "c":
            for i in range(0, 5):
                ListOfRandomDecreasingNumbers = []
                CreateListOfRandomDecreasingNumbers(LengthOfList, ListOfRandomDecreasingNumbers)
                t1 = timeit.default_timer()
                CombSortListOfRandomNaturalNumbers(ListOfRandomDecreasingNumbers)
                t2 = timeit.default_timer()
                ExecutionTime = t2 - t1
                print(
                    f'The time execution of the comb sort algorithm for the worst case scenario, for a list of {LengthOfList} elements is: {ExecutionTime}')

                LengthOfList = LengthOfList * 2
        else:
            ProgramOptions()


def GenerateListOfRandomNumbers(LengthOfList, ListOfRandomNumbers):
    for i in range(0, LengthOfList):
        ListOfRandomNumbers.append(random.randint(0, 10000))
    return ListOfRandomNumbers


def CocktailSortListOfRandomNaturalNumbers(ListOfRandomNaturalNumbers):
    SwapOfTwoNumbersFromTheList = True
    LowerPartOfTheList = 0
    UpperPartOfTheList = len(ListOfRandomNaturalNumbers)
    while SwapOfTwoNumbersFromTheList is True:
        SwapOfTwoNumbersFromTheList = False
        for i in range(LowerPartOfTheList, UpperPartOfTheList - 1):
            if ListOfRandomNaturalNumbers[i] > ListOfRandomNaturalNumbers[i + 1]:
                ListOfRandomNaturalNumbers[i], ListOfRandomNaturalNumbers[i + 1] = ListOfRandomNaturalNumbers[i + 1], \
                                                                                   ListOfRandomNaturalNumbers[i]
                SwapOfTwoNumbersFromTheList = True

        for j in range(UpperPartOfTheList - 1, LowerPartOfTheList, -1):
            if ListOfRandomNaturalNumbers[j] < ListOfRandomNaturalNumbers[j - 1]:
                ListOfRandomNaturalNumbers[j], ListOfRandomNaturalNumbers[j - 1] = ListOfRandomNaturalNumbers[j - 1], \
                                                                                   ListOfRandomNaturalNumbers[j]
                SwapOfTwoNumbersFromTheList = True


def CombSortListOfRandomNaturalNumbers(ListOfRandomNaturalNumbers):
    GapOfPositionBetweenTheNumbersWeCompareInTheList = len(ListOfRandomNaturalNumbers)
    SwapOfTwoNumbersInTheList = True
    while GapOfPositionBetweenTheNumbersWeCompareInTheList > 1 and SwapOfTwoNumbersInTheList is True:
        SwapOfTwoNumbersInTheList = False
        if GapOfPositionBetweenTheNumbersWeCompareInTheList != 1:
            GapOfPositionBetweenTheNumbersWeCompareInTheList = int(
                GapOfPositionBetweenTheNumbersWeCompareInTheList / 1.3)
        else:
            GapOfPositionBetweenTheNumbersWeCompareInTheList = 1
        for i in range(0, len(ListOfRandomNaturalNumbers) - GapOfPositionBetweenTheNumbersWeCompareInTheList):
            if ListOfRandomNaturalNumbers[i] > ListOfRandomNaturalNumbers[
                i + GapOfPositionBetweenTheNumbersWeCompareInTheList]:
                ListOfRandomNaturalNumbers[i], ListOfRandomNaturalNumbers[
                    i + GapOfPositionBetweenTheNumbersWeCompareInTheList] = ListOfRandomNaturalNumbers[
                                                                                i + GapOfPositionBetweenTheNumbersWeCompareInTheList], \
                                                                            ListOfRandomNaturalNumbers[i]
                SwapOfTwoNumbersInTheList = True


def main():
    ProgramOptions()


main()
