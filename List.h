//
// Created by faraz098 on 5/21/17.
//

#ifndef A1CMPT225_LIST_H
#define A1CMPT225_LIST_H

/*Assignment #2

 * List.h
 *
 * Class Description: List data collection ADT.

 *
 * Last modified on: june 2017
 * Author: Faraz Fazlalizadeh
 */
                     // Actual maximum capacity of element array
/*
 * List.h
 *
 * Class Description: A value-oriented List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - It is sorted by ascending sort order of its PatientList.
 *                   - Its data structure is expandable: when full, it expands to accommodate
 *                     new insertion. This is done unbeknown to the client code.
 *
 * Last modified on: May 2017
 * Author: AL
 */

#pragma once
#include <string>
#include <iostream>
using namespace std;
#include "Patient.h"

using namespace std;

struct arr{
    int cap ;
    //    Patient *PatientList= new Patient [cap];    // Data structure with capacity of MAX_ELEMENTS

    Patient *PatientList ;    // Data structure with capacity of MAX_ELEMENTS
    int elementscount ;

};
class List  {

private:

// As we are testing the code of our assignment, we can change the value given to this constant.

    int MAX_ELEMENTS ; // Small capacity so can test when data collection becomes full
    arr *CareCardList;    // Data structure with capacity of MAX_ELEMENTS

    int elementCount ;                  // Current element count in element array
    int GetFirstNum (const Patient& needed);
public:

// We must add at least 1 constructor and a destructor


    // Default constructor
    List();


    //constructor
    List(int Capacity);
//    List(const Patient& copyPatient);
// *** Start of Public Interface ***
// Note: Public Interface must not be modified.

    // Description: Returns the total element count currently stored in List.
    int  getElementCount() const;

    // Description: Insert an element.
    //              When "this" List is full, its data structure is expanded to accommodate
    //              a new element. This is done unbeknown to the client code.
    //              If the insertion is successful, true is returned otherwise, false is returned.
    // Precondition: newElement must not already be in data collection.
    // Postcondition: newElement inserted and the appropriate elementCount has been incremented.
    bool insert(const Patient& newElement);

    // Description: Remove an element.
    //              If the removal is successful, true is returned otherwise, false is returned.
    // Postcondition: toBeRemoved is removed, the appropriate elementCount has been decremented.
    bool remove( const Patient& toBeRemoved );

    // Description: Remove all PatientList.
    void removeAll();

    // Description: Search for target element and returns a pointer to it if found,
    //              otherwise, returns NULL.
    Patient* search(const Patient& target);

    // Description: Prints all n PatientList stored in List in sort order and does so in O(n).
    void printList();

    //destructor
    ~List();
// *** End of Public Interface ***

}; // end List
#endif