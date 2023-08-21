
import random


def GenerateListOfRandomNaturalNumbers(ListOfRandomNaturalNumbers):
    for i in range(0, 10):
        ListOfRandomNaturalNumbers.append(random.randint(0, 100))
    return ListOfRandomNaturalNumbers



def CocktailSortListOfRandomNaturalNumbers(ListOfRandomNaturalNumbers, step):
    SwapOfTwoNumbersFromTheList=True
    LowerPartOfTheList=0
    UpperPartOfTheList=len(ListOfRandomNaturalNumbers)
    NumberOfSwapsMade=0
    while SwapOfTwoNumbersFromTheList is True:
        SwapOfTwoNumbersFromTheList = False
        for i in range(LowerPartOfTheList, UpperPartOfTheList-1):
            if ListOfRandomNaturalNumbers[i] > ListOfRandomNaturalNumbers[i+1]:
                ListOfRandomNaturalNumbers[i], ListOfRandomNaturalNumbers[i + 1] = ListOfRandomNaturalNumbers[i + 1],  ListOfRandomNaturalNumbers[i]
                NumberOfSwapsMade+=1
                if  NumberOfSwapsMade%step==0:
                    print(f'The partially sorted list after a number of {NumberOfSwapsMade} swaps: ')
                    print (ListOfRandomNaturalNumbers)
                SwapOfTwoNumbersFromTheList=True

        for j in range(UpperPartOfTheList-1, LowerPartOfTheList, -1):
            if ListOfRandomNaturalNumbers[j]<ListOfRandomNaturalNumbers[j-1]:
                ListOfRandomNaturalNumbers[j], ListOfRandomNaturalNumbers[j-1] = ListOfRandomNaturalNumbers[j-1], ListOfRandomNaturalNumbers[j]
                NumberOfSwapsMade+=1
                if NumberOfSwapsMade%step == 0:
                    print(f' The partially sorted list after a number of {NumberOfSwapsMade} swaps: ')
                    print(ListOfRandomNaturalNumbers)
                SwapOfTwoNumbersFromTheList=True
    if NumberOfSwapsMade % step != 0:
        print(f'The sorted list after a number of  {NumberOfSwapsMade} swaps: ')
        print(ListOfRandomNaturalNumbers)

def CombSortListOfRandomNaturalNumbers(ListOfRandomNaturalNumbers, step):
     GapOfPositionBetweenTheNumbersWeCompareInTheList=len(ListOfRandomNaturalNumbers)
     NumberOfSwapsMade = 0
     SwapOfTwoNumbersInTheList=True
     while GapOfPositionBetweenTheNumbersWeCompareInTheList>1 and SwapOfTwoNumbersInTheList==True :
        SwapOfTwoNumbersInTheList = False
        if GapOfPositionBetweenTheNumbersWeCompareInTheList!=1:
            GapOfPositionBetweenTheNumbersWeCompareInTheList=int(GapOfPositionBetweenTheNumbersWeCompareInTheList/1.3)
        for i in range(0,len(ListOfRandomNaturalNumbers)-GapOfPositionBetweenTheNumbersWeCompareInTheList ):
             if ListOfRandomNaturalNumbers[i]>ListOfRandomNaturalNumbers[i+GapOfPositionBetweenTheNumbersWeCompareInTheList]:
                 ListOfRandomNaturalNumbers[i],ListOfRandomNaturalNumbers[i+GapOfPositionBetweenTheNumbersWeCompareInTheList]=ListOfRandomNaturalNumbers[i+GapOfPositionBetweenTheNumbersWeCompareInTheList], ListOfRandomNaturalNumbers[i]
                 NumberOfSwapsMade +=1
                 if NumberOfSwapsMade%step== 0:
                     print(f'The partially sorted list after a number of {NumberOfSwapsMade} swaps: ')
                     print(ListOfRandomNaturalNumbers)
                 SwapOfTwoNumbersInTheList = True
     if NumberOfSwapsMade%step!=0:
         print(f'The sorted list after a number of  {NumberOfSwapsMade} swaps: ')
         print(ListOfRandomNaturalNumbers)

def main():

    print('Press 1 to generate a list of 10 random natural numbers. Generated numbers must be between 0 and 100.')
    print('Press 2 to sort the list using cocktail sort')
    print('Press 3 to sort the list using comb sort')
    print('Press 4 to exit the program')
    while True:
        key = input("Press one of the four keys to execute the option that you want: ")
        if key == "1":
            ListOfRandomNaturalNumbers = []
            ListOfRandomNaturalNumbers = GenerateListOfRandomNaturalNumbers(ListOfRandomNaturalNumbers)
            print("The 10 random natural numbers in our list are: ")
            print(ListOfRandomNaturalNumbers)
        elif key == "2":
            step = int(input(
                "Introduce a number that represents the number of swaps done in cocktail sort after which the partially sorted list will be displayed: "))
            print('This is the list sorted with cocktail sort: ')
            print(CocktailSortListOfRandomNaturalNumbers(ListOfRandomNaturalNumbers, step))
        elif key == "3":
            step = int(input(
                "Introduce a number that represents the number of swaps done in comb sort after which the partially sorted list will be displayed: "))
            print('This is the list sorted with comb sort: ')
            print(CombSortListOfRandomNaturalNumbers(ListOfRandomNaturalNumbers, step))
        elif key == "4":
            break
        else:
            print("Wrong option! Try again!")


main()


