"""
In Python, objects can be classified as mutable or immutable based on whether they can be changed after they are created or not.

Immutable objects: An object is considered immutable if its value cannot be changed after it is created. This means that any
operation that appears to modify the object actually creates a new object with a new value. Examples of immutable objects in
 Python include numbers, strings, and tuples.

Mutable objects: A mutable object, on the other hand, can be changed after it is created. This means that any operation
that modifies the object actually changes its value. Examples of mutable objects in Python include lists, sets, and dictionaries.

Here's an example to illustrate the difference between mutable and immutable objects in Python:
"""

# immutable object (string)
s=(2,5,8)
z=s
s+=(4,) #this is how you append a new elem to a tuple, but s will point to a new address now, this is a new tuple
#cauta ca poti sa transformi tuple in lista si lista in tuple
print(z)
print(s)
a = "hello"
b = a
a += " world"
print(a)   # "hello world"
print(b)   # "hello"
x=5
y=x
x+=1
print(x)
print(y)
# mutable object (list)
c = [1, 2, 3]
d = c
c.append(4)
print(c)   # [1, 2, 3, 4]
print(d)   # [1, 2, 3, 4]


"""
In the example, the string a is immutable, so when we add " world" to it, a new string is created with the value "hello world".
 The original string a is not modified, and b still points to the original "hello" string.

On the other hand, the list c is mutable, so when we append 4 to it, the list is modified in place. The variable d also 
points to the modified list.
"""
"""
A IS A POINTER TO THE STRING HELLO, SO AT ADDRESS A(NUMBER X), WE HAVE THE STRING HELLO
B IS A POINTER TO THE ADDRESS A(NUMBER X), WHERE IS THE STRING HELLO
A AND B POINT TO THE SAME ADDRESS
STRINGS ARE IMMUTABLE OBJECTS, SO WHEN YOU DO AN OPERATION ON THE STRING, IN OUR CASE, WE ADD A NEW STRING TO IT, "WORLD"
YOU DON T ACTUALLY CHANGE THE VALUE OF THE INITAL STRING, BUT YOU CREATE A NEW STRING THAT REPRESENTS THE INITIAL STRING
WITH THE OPERATION APPLIED TO IT ("HELLO WORLD"). SO BECAUSE WE APPLY A NEW OPEARTION TO A, IT WILL CREATE A NEW STRING, 
SO NOW IN MEMORY WE HAVE 2 STRINGS: HELLO, TO WHICH B POINTS, AND HELLO WORLD, TO WHICH A POINTS
WHEN WE WRITE A+="WORLD", A NEW STRING IS CREATED, WITH A NEW PLACE IN MEMORY, EMANING WITH A NEW ADDRESS, AND A WILL
NO LONGER POINT TO THE ADDRESS OF HELLO(NUMBER X), IT WILL POINT TO THE ADDRESS OF HELLO WORLD(NUMBER Y)

IMMUTABLE: THE VALUE OF THE OBJECT IS NOT CHANGED, INSTEAD, A NEW OBJECT IS CREATED
MUTABLE: THE VALUE OF THE OBJECT CHANGES (SO ALL THE POINTERS TO THAT OBJECT WILL POINT TO THE NEW VERSION OF THE OBEJCT)

IMMUTABLE:STRINGS, NUMBERS, TUPLES
MUTABLE: LISTS, SETS:unique elements, DICTIONARIES
you can t change the elements in a tuple, only if you

tup = ([3, 4, 5], 'myname') 
The tuple consists of a string and a list. Strings are immutable so we can’t change its value. But the contents of the list
 can change. The tuple itself isn’t mutable but contain items that are mutable.
"""

