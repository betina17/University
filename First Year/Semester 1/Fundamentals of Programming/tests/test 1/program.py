#
# Functions section
#
import operator
def add_new_coffee_to_the_list(list_of_coffees, coffee_name, coffee_origin_country, coffee_price):

    if isinstance(coffee_price, float) and coffee_price>0:
        list_of_coffees[coffee_name] = [coffee_origin_country, coffee_price]
    else:
        raise ValueError("The coffee price is not a float greater than 0! Introduce it again")



def sort_coffees_by_country_and_price(list_of_coffees):
   list_of_coffees_sorted_by_country_and_price = sorted(list_of_coffees.items(), key=operator.itemgetter(1,0,1))
   return list_of_coffees_sorted_by_country_and_price
#
# User interface section
#
def print_menu():
    print("Press 1 to add a coffee")
    print("Introduce your option>")
def start_program():
    list_of_coffees = {}
    list_of_coffees["Caffe miel"]=["France", 5.5]
    list_of_coffees["Latte"] = ["Romania", 7.2]
    list_of_coffees["Espresso"] = ["Italy", 4.6]
    list_of_coffees["Frappe"] = ["Argentina", 9.0]
    list_of_coffees["Machiato"] = ["Argentina", 8.9]
    add_coffee = 1
    display_coffees = 0
    exit_program = 2
    while True:
        print("Press 0 to display the list of coffees sorted alphabetically by country and increasingly by price")
        print("Press 1 to add a coffee to the list")
        #print("Press 2 to filter coffees based on country of origin and price")
        print("Press 2 to exit the application")
        print("Introduce your option>")
        option_selected = int(input())
        if option_selected == display_coffees:
            list_of_coffees_sorted_by_country_and_price = sort_coffees_by_country_and_price(list_of_coffees)
            print(list_of_coffees_sorted_by_country_and_price)
        elif option_selected == add_coffee:
            print("Enter coffee name>")
            coffee_name = input()
            print("Enter the country of origin of the coffee>")
            coffee_origin_country = input()
            while(1):
                print("Enter the price of the coffee, which should be a float greater than 0")
                coffee_price = float(input())
                try:
                    add_new_coffee_to_the_list(list_of_coffees, coffee_name, coffee_origin_country, coffee_price)
                    break
                except ValueError as e:
                    print(e)

        elif option_selected == exit_program:
            print("Goodbye!")
            break




if __name__ == '__main__':
    start_program()


