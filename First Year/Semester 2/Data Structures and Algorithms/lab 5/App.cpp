#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

int main() {
	testAll();
	testAllExtended(); 
	//doar test remove nu merge
	
	cout << "Test over" << endl;
	system("pause");
}

/*nu merge remove pentru ca asa cum sunt adaugate in tree, de la -100 la 99, nu vor fi niciodata elemente pe partea stanga
*/
//Best case:Theta(1)-cazul specific in care nu gaseste elementul
//Worst case:Theta(capacity)-cazul specific in care parcurge toata lista
//Average case:O(capacity)-nu e un caz specific, de aia e average, nu e nici best nu e nici worst, e cumva o medie intre ele.O comes from overall.
//O(capacity) inseamna ca se poate intampla sa am intre 1 si capacity iteratii, adica intre best si worst case


//for BST: we can insert, find and delete in O(h)-height = O(logn)-n, nr of nodes

/*In Big O notation, n generally represents the size of the input to the function or algorithm. It's a way of describing how the run-time grows
as the input size increases.

In the case of a binary search tree, n typically represents the number of nodes in the tree. So when we say the search operation in a balanced
binary search tree has a time complexity of O(log n), we mean that the time it takes to search for an item grows logarithmically in relation to
the number of nodes in the tree.

In simpler terms, even if the number of nodes in the tree doubles, the number of steps needed to find a node (in the worst case) only increases
by one. This is because each step in a search operation in a binary search tree effectively halves the number of possible nodes the search item
can be in, due to the property of binary search trees where for any given node, all the nodes in its left subtree are less than the node and all
the nodes in its right subtree are greater.
*/

//e un alg de cautare f rapid bst