#include <iostream>
#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
    this->root = nullptr;
    this->r = r;
    this->length = 0;
    this->removed = 0;
} // theta(1)

void SortedBag::add(TComp e) {
    // case 1: add root
    if (this->length == 0) {
        this->root = initNode(e);  this->length++; return;
    }

    BSTNode* currentNode = this->root;
    while (true) {
        // case 2: element already exists
        if (currentNode->info.first == e) {
            currentNode->info.second++; 
            this->length++;
            return; //opreste loop-ul de true
        }
        // case 3: you add to the left where is empty
        if (!this->r(currentNode->info.first, e) && currentNode->left == nullptr) { //ex: 3<2 false
            BSTNode* new_node = initNode(e); currentNode->left = new_node;
            this->length++;
            return; 
        }

        // case 4: you add to the right where is empty
        if (this->r(currentNode->info.first, e) && currentNode->right == nullptr)
        {
            BSTNode* new_node = initNode(e); currentNode->right = new_node;
            this->length++;
            return;
        }

        //left and right are not empty, deci trebe sa mergem pe urmatoru tree. tre sa vedem daca pe ala din stanga sau pe ala din dreapta
        if (!this->r(currentNode->info.first, e) && currentNode->left != nullptr) //daca e<current_node, mergem pe stanga
            currentNode = currentNode->left;
        //if it's not, check if right is empty
        else if (this->r(currentNode->info.first, e) && currentNode->right != nullptr) //daca e>current_node, mergem pe dreapta
            currentNode = currentNode->right;
    }
}
//BC: we want to add the first node, which will become the root:Theta(1)
//WC: we want to add a node on the last level in the tree:Theta(logn)
//AC:O(logn)


bool SortedBag::delete_rec(BSTNode* node, BSTNode* parent, TComp elem) 
//node-nodul curent, parent-parintele lui, elementul pe care vrem sa-l stergem(daca frecv==0, stergem intreg nodul, daca nu, scadem frecv elem)
{   
    if (node == nullptr)
        return false;

    // if element has frequency > 1
    if (node->info.first == elem && node->info.second > 1) //am gasit nodu cu val lui elem si nu il stergem de tot, doar crestem frecventa
    {
        node->info.second--;
        this->removed = 1;
        return true;
        
    }
    // if element has frequency = 1
    if (node->info.first == elem && node->info.second == 1) {
        // case1: The node to be removed has no descendant, so it's a leaf
        if (node->left == nullptr && node->right == nullptr) {
            // if it's only the root in the tree
            if (parent == nullptr) {
                delete node; //delete pt ca in init il aloci dinamic
                this->root = nullptr;
                this->removed = 1;
                return true;
               
            }
            //else, if it has a parent,  remove from parent
            if (node == parent->left) {
                parent->left = nullptr;
                delete node;
                this->removed = 1;
                return true;
                
            }
            if (node == parent->right) {
                parent->right = nullptr;
                delete node;
                this->removed = 1;
                return true;
               
            }
        }

        // case2: a) The node to be removed has one descendant in the left
        if (node->left != nullptr && node->right == nullptr) {
            //nu are parinte
            // if it's root
            if (parent == nullptr) {
                this->root = node->left;
                delete node;
                this->removed = 1;
                return true;
                
            }
            //are parinte
            //daca nodul pe care vrem sa-l stergem este copilul de stanga al parintelui sau, conectam its descendant in stanga parintelui
            if (parent->left == node) {
                parent->left = node->left;
                delete node;
                this->removed = 1;
                return true;
                
            }
            //daca nodul pe care vrem sa-l stergem este copilul de dreapta al parintelui sau, conectam its descendant in dreapta parintelui
            if (parent->right == node) {
                parent->right = node->left;
                delete node;
                this->removed = 1;
                return true;
                
            }
        }

        // case2: b)The node to be removed has one descendant to the right
        if (node->left == nullptr && node->right != nullptr) {
            //nu are parinte
            // if it's root
            if (parent == nullptr) {
                this->root = node->right;
                delete node;
                this->removed = 1;
                return true;
                
            }
            //are parinte
            //daca a fost copil de stanga, conectam descendentu lui de dreapta(has one descendant to the rigth) la stanga parintelui
            if (parent->left == node) {
                parent->left = node->right;
                delete node;
                this->removed = 1;
                return true;
                
            }
            //daca a fost copil de dreapta, conectam descendentu lui de dreapta(has one descendant to the rigth) la dreapta parintelui
            if (parent->right == node) {
                parent->right = node->right;
                delete node;
                this->removed = 1;
                return true;
                
            }
        }

        // case3: The node to be removed has two descendants
        if (node->left != nullptr && node->right != nullptr) {
            //gasesc cel mai mic nod mai mare decat nodul pe care vreau sa-l sterg
            BSTNode* maximum_node = maximum(node);
            TElem value = maximum_node->info.first;
            int freq = maximum_node->info.second;

            // put the maximum node in the current node
            node->info.first = value;
            node->info.second = freq;

            // delete the maximum node
            maximum_node->info.second = 1;
            delete_rec(this->root, nullptr, value);
            this->removed = 1;
            return true;
        }

    }

    // it wasn't found yet
    if (!this->r(node->info.first, elem))
        delete_rec(node->left, node, elem);
    else delete_rec(node->right, node, elem);
    if (this->removed == 0)
   
        return false;
 
} //best case: O(n); worst case O(n^2) -> case4

BSTNode* SortedBag::maximum(BSTNode* node)
{
    if (node == nullptr)
        return nullptr;

    node = node->right; //trebuie sa gasim cel mai mic element, mai mare decat nodul nostru
    //in primu rand trebuie sa fie mai mare decat nodul nostru, deci pornim din stanga lui

    //dupa, trebe sa gasim cel mai mic nod dintre cei mai mari decat nodul nostru, asa ca mergem pana la capat pe ramura
    //daca acel nod e direct cel din dreapta nodului meu, nu va mai intra in while pt ca asta va insemna ca in stanga nodului din dreapta am null
    while (node->left != nullptr)
        node = node->left;
    return node;
} // O(n)

bool SortedBag::remove(TComp e) {
    if (!search(e))
        return false; 

    if (delete_rec(this->root, nullptr, e))
    {
        this->length--;
        this->removed = 0;
        return true;
    }
    else return false;
} // same as delete_rec


bool SortedBag::search(TComp elem) const {
    BSTNode* node = this->root;
    // case 1: tree doesn't exist
    if (node == nullptr)
        return false;

    while (true) {
        // case 2: element was found
        if (node->info.first == elem)
            return true;
        //case3: nodul cautat e mai mic decat nodul curent->mergem pe partea stanga
        if (!this->r(node->info.first, elem) && node->left != nullptr) {
            node = node->left; continue;
        }
        // case 4: nodul cautat e mai mare decat nodul curent->mergem pe partea dreapta
        if (this->r(node->info.first, elem) && node->right != nullptr) {
            node = node->right; continue;
        }
        // case 5: nodul cautat e mai mic decat nodul curent->mergem pe partea stanga, daca partea stanga e nula, nu am gasit nodul deloc
        if (!this->r(node->info.first, elem) && node->left == nullptr)
            return false;
        // case 6: nodul cautat e mai mare decat nodul curent->mergem pe partea dreapta, daca partea dreapta e nula, nu am gasit nodul deloc
        if (this->r(node->info.first, elem) && node->right == nullptr)
            return false;
    }
} // O(n)


int SortedBag::nrOccurrences(TComp elem) const {
    BSTNode* currentNode = this->root;
    // if it doesn't exist just return 0
    if (!this->search(elem))
        return 0;

    while (true) {
        if (currentNode->info.first == elem) {
            return currentNode->info.second;
        }
        //elem<current_node, mergem in stanga
        if (!this->r(currentNode->info.first, elem))
            currentNode = currentNode->left;
        //elem>current_node, mergem sal cautam in dreapta
        else if (this->r(currentNode->info.first, elem))
            currentNode = currentNode->right;
    }
} // O(n) for search * O(n) for while => O(n^2)



int SortedBag::size() const {
    return this->length;
} // theta(1)


bool SortedBag::isEmpty() const {
    if (this->root == nullptr)
        return true;
    return false;
} // theta(1)


SortedBagIterator SortedBag::iterator() const {
    return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    //InOrder traversal(left->root->right)
    auto** arr = new BSTNode * [this->length];
    int currentPos = 0;
    BSTNode* currentNodee = this->root;
    BSTNode* nodeToDelete;
    while (currentNodee != nullptr)
    {
        arr[currentPos] = currentNodee;
        currentPos++;
        currentNodee = currentNodee->left;
    }

    while (currentPos != 0)
    {
        currentNodee = arr[currentPos - 1];
        currentPos--;
        nodeToDelete = currentNodee;
       
        currentNodee = currentNodee->right;
        delete nodeToDelete; //trebuie neaparat pus acest delete dupa linia de mai sus, ca sa poti sa ii mai accesezi rigth-ul inainte sa il stergi
        while (currentNodee != nullptr)
        {
            arr[currentPos] = currentNodee;
            currentPos++;
            currentNodee = currentNodee->left;
        }
    }
    //ideea generala e ca merge pe linia cea mai din stanga, pana jos. acolo se opreste, sterge ultimul elem, si verifica pt cel de mai sus daca
    //are ceva in partea dreapta. cand gaseste ceva in partea dreapta, merge pe stanga acelei parti, deci pe alta linie stanga, pana la finalul ei
    //si se repeta procesul. daca in partea dreapta, nodul acela nu mai are parti stangi, o sa il stearga pe el(root-ul), si apoi verifica de 
    //parti din dreapta iar. daca nu sunt nici dinalea, se intoarce la linia stanga initiala. deci practic, sterge tot de pe stanga ce nu are
    //ceva in dreapta, cand ajunge la ceva de pe stanga care are ceva in dreapta, merge pe stanga acelei drepte si se repeta procesu.
    //cand nu mai e de sters in stanga principala, se sterge root-ul si se verfica dreapta root-ului, daca e ceva acolo pe stanga se merge pe stanga.
    //daca nu, se intoarce la stanga initiala bla bla

} // O(n)
//in order=in ordine. daca le pui in vector,elem vor fi sortate. si e si logic. stanga e cea mai mica, apoi 
//root-ul, apoi dreapta
//ca sa stergi tree-ul, tre sa il traversezi ca sa stergi fiecare nod



BSTNode* SortedBag::initNode(TElem e) const
{
    auto* node = new BSTNode;
    node->info.first = e; //info este perechea(valoarea, frecventa)
    node->info.second = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;

} //theta(1)