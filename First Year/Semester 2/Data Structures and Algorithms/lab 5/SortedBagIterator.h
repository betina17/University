#pragma once
#include "SortedBag.h"

class SortedBag;

struct Stack
{
    BSTNode** array;
    int size;
};

class SortedBagIterator
{
    friend class SortedBag;

private:
    const SortedBag& bag;
    SortedBagIterator(const SortedBag& b);
    BSTNode* currentNode;
    Stack stack;
    int currentPosition;
    void InOrderTraversal(BSTNode* node);

    //TODO - Representation

public:
    TComp getCurrent();
    bool valid();
    void next();
    void first();

    //changes the current element from the iterator to the previous element, or, if the current element was the first, makes the iterator invalid
    //throws an exception if the iterator is not valid
    void previous();
};
