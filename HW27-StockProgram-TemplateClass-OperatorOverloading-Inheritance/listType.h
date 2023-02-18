//Homework 27

/*
 *  Filename:           listType.h
 * 
 *  Purpose:            Header file for template list class listType
 * 
 *  Author:             Zachary Charles Stewart
 *  Student ID:         105903414
 *  Date:               3/08/2017 18:47 PST
 */

//Preprocessor Directives
#ifndef LISTTYPE_H
#define LISTTYPE_H


#include <iostream>
#include <cstdlib>
#include <cassert>

//Namespace
using namespace std;

//--------------------------------------------------------------------------//

template <class Type>
class listType{

public:
    bool isEmptyList() const;
    // Function returns a nonzero value (TRUE) if list
    // is empty. Otherwise it returns the value 0
    // (FALSE).

    bool isFullList() const;
    // Function returns a nonzero value (TRUE) if list
    // is full. Otherwise it returns the value 0
    // (FALSE).

    void setLength(int len);
    // Function that sets the length of a list.
    // Postcondition: length = len

    int showLength() const;
    // Function that returns the length of a list
    // Postcondition: returns length

    void search(Type searchItem) const;
    // Search the list for searchItem
    // Postcondition: Internal variable found is set
    // to a nonzero value (TRUE) if searchItem is found
    // in the list, otherwise found is set to 0
    // (FALSE). If the searchItem is found, the value
    // and location within the list is
    // printed to the screen, otherwise, a message
    // indicating that the item cannot
    // be found should be printed.

    void insert(Type newElement);
    // Insert newElement in the list
    // Prior to insertion list must not be full
    // Postcondition: List is old list plus the
    // newElement

    void deleteItem(Type deleteElement);
    // If deleteElement is found in the list it is
    // deleted
    // If list is empty output the message:
    // "Cannot delete from the empty list"
    // Postcondition: List is old list minus the
    // deleteItem if deleteItem is found in the list 

    void sort();
    // Sort the list
    // Precondition: List must exist
    // Postcondition: List elements are in ascending
    // order

    void print() const;
    // Output the elements of the list

    void getList(ifstream& ifObject);
    // Read and store elements in the list
    // Postcondition: length = number of elements in
    // the list
    // elements = array holding the input data

    void destroyList();
    // Postcondition: length = 0

    void printList() const;
    // Output the elements of the list

    listType(int listSize);
    // Constructor with parameters
    // Create an array of size specified by the
    // parameter listSize
    // Postcondition: elements contains the base
    // address of the array, length = 0, and
    // maxsize = listSize

    listType();
    // Default constructor
    // Create an array of 50 components
    // Postcondition: elements contains the base
    // address of the array, length = 0, and
    // maxsize = 50

    virtual ~listType();
    // Destructor
    // Delete all elements of the list
    // Postcondition: Array elements is deleted

protected:
    void binarySearch(Type searchItem, int& found, int& index);
    int maxSize;
    // Maximum number that can be stored in the list
    int length;
    // Number of elements in the list
    Type *elements;
    // Pointer to the array that holds list elements 
};

//--------------------------------------------------------------------------//

//--------------------------------------------------------------------------//

//Function:     bool isEmtpy list() const
//
//Inputs:       None
//Outputs:      bool
//Purpose:      The purpose of the function is to determine whether the list
//              is an empty list.
template <class Type>
bool listType<Type>::isEmptyList() const
{
    return (length == 0);
}

//--------------------------------------------------------------------------//

//Function:     bool isFullList() const
//
//Inputs:       None
//Outputs:      bool
//Purpose:      The purpose of this function is to determine whether the list
//              is a full list.
template <class Type>
bool listType<Type>::isFullList() const
{
    return (length == maxSize);
}

//--------------------------------------------------------------------------//

//Function:     bool setLength(int len)
//
//Inputs:       int len
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to set the value of the
//              private member variable length to the value of len passed
//              in the argument of the function.
template <class Type>
void listType<Type>::setLength(int len)
{
    assert(len > 0);
    length = len;
}

//--------------------------------------------------------------------------//

//Function:     void showLength()
//
//Inputs:       None
//Outputs:      int
//Purpose:      The purpose of this function is to return the value of the
//              private member variable length.
template <class Type>
int listType<Type>::showLength() const
{
    return length;
}

//--------------------------------------------------------------------------//

//Function:     void search(Type searchItem) const
//
//Inputs:       Type searchItem
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to search the list to
//              determine whether the list contains an object equivalent to
//              searchItem. The function will then output a message declaring
//              that the item was found and will output it's index if found.
template <class Type>
void listType<Type>::search(Type searchItem) const
{
    int found;
    int index;

    //Implement binary search
    binarySearch(searchItem, found, index);

    //If found, contained in list
    if (found)
    {
        cout << "Item" << searchItem << "is in the list at" << index << endl;
    }
    
    //If not found, not in list
    else
    {
        cout << "Item" << searchItem << "is not in the list" << endl; 
    }
}

//--------------------------------------------------------------------------//

//Function:     void insert(Type newElement)
//
//Inputs:       Type newElement
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to insert in element at the
//              end of the array.
template <class Type>
void listType<Type>::insert(Type newElement)
{
    assert(!isFullList());
    elements[length] = newElement;
    length++;
}

//--------------------------------------------------------------------------//

//Function:     void deleteItem(Type deleteItem)
//
//Inputs:       Type deleteItem
//Outputs:      None, return type void
//Purpose:      

template <class Type>
void listType<Type>::deleteItem(Type deleteElement)
{
    bool found = false;
    int index = 0;
    //Search for item
    binarySearch(deleteElement, found, index);
    //If not found
    if((index < 0 || index >= length) || !found)
    {
        cout << "The location of the item to be removed is out of range.";
        cout << endl;
    }
    //Else, found
    else
    {
        //Copy successive elements into index
        //This is equivalent to shifting every element after the index
        //to the left
        for(int i = index; i < length - 1; i++)
        {
            elements[i] = elements[i+1];
        }
        length--;
    }
}

//--------------------------------------------------------------------------//

//Function:     void sort()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to sort a list in
//              ascending order from least to greatest.
template <class Type>
void listType<Type>::sort()
{
    assert(!isEmptyList());
    //Placeholder temp variable
    Type temp;
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length - 1; j++)
        {
            //Compare elements
            if(elements[j] > elements[j+1])
            {
                //Swap if items at index j < items at index j+1
                temp = elements[j];
                elements[j] = elements[j+1];
                elements[j+1] = temp;
            }
        }
    }
}

//--------------------------------------------------------------------------//

//Function:     void print()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to print the items contained
//              in the private member variable elements.
template <class Type>
void listType<Type>::print() const
{
    //Cycle through list, output values
    for(int i = 0; i < length; i++)
    {
        cout << elements[i] << " ";
    }
    cout << endl;
}

//--------------------------------------------------------------------------//

//Function:     getList(ifstream &)
//
//Inputs:       ifstream &ifObject
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to read the elements of the
//              list into the ifstream variable passed in the argument
//              of the function.
template <class Type>
void listType<Type>::getList(ifstream& ifObject)
{
    //Set length to zero
    destroyList();
    //Read items from input stream into elements array
    for(int i = 0; i < maxSize; i++)
    {
        ifObject >> elements[i];
        length++;
    }
}

//--------------------------------------------------------------------------//

//Function:     void destroyList()
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to "destroy" the list by 
//              setting the value of the private member variable length 
//              to be equal to zero.
template <class Type>
void listType<Type>::destroyList()
{
    length = 0;
}

//--------------------------------------------------------------------------//

//Function:     void printList() const
//
//Inputs:       None
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to print the elements of the
//              private member variable elements.
template <class Type>
void listType<Type>::printList() const
{
    //Cycle through list, output values
    for(int i = 0; i < length; i++)
    {
        cout << elements[i] << " ";
    }
    cout << endl;
}

//--------------------------------------------------------------------------//

//Function:     binarySearch(Type searchitem, int &found, int &index))
//
//Inputs:       Type searchItem, int &found, int &index
//Outputs:      None, return type void
//Purpose:      The purpose of this function is to implement a binary search
//              function.
template <class Type>
void listType<Type>::binarySearch(Type searchItem, int& found, int& index)
{
    int first = 0;
    int last = length - 1;
    int mid;

    found = 0;

    while (!found && (first<=last) )
    {
        mid = (first+last)/2;

        if (elements[mid] == searchItem)
        {
            found = 1;
        }
        else if (elements[mid] > searchItem)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }

    if (found)
    {
        index = mid;
    }
    
    else
    {
        index = -1;
    }
     
}

//--------------------------------------------------------------------------//

//Function:     listType(int listSize)  |  Constructor
//
//Inputs:       int listSize
//Outputs:      None, Constructor implementation
//Purpose:      The purpose of this function is to implement the Constructor
//              with parameters for the listType class.
template <class Type>
listType<Type>::listType(int listSize)
{
    //If invalid input for size of array
    if(listSize <= 0)
    {
        cout << "the array size must be positive. Creating an array of the ";
        cout << "size 50." << endl;
        //Default array size to 50
        maxSize = 50;
    }
    else
    {
        //Set array size to user input
        maxSize = listSize;
    }
    //Initialize length to 0, initialize list to point to array of size
    //maxSize
    length = 0;
    elements = new Type[maxSize];
}

//--------------------------------------------------------------------------//

//Function:     listType()  |  Constructor
//
//Inputs:       None
//Outputs:      None, Constructor implementation
//Purpose:      The purpose of this function is to implement the Constructor
//              without parameters for the listType class.
template <class Type>
listType<Type>::listType()
{
    maxSize = 50;
    length = 0;
    elements = new Type[maxSize];
}

//--------------------------------------------------------------------------//

//Function:     listType()  |  Destructor
//
//Inputs:       None
//Outputs:      None, Destructor implementation
//Purpose:      The purpose of this function is to implement the Destructor
//              for the listType class.
template <class Type>
listType<Type>::~listType()
{
    delete [] elements;
}

//--------------------------------------------------------------------------//

#endif /* LISTTYPE_H */

