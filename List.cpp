//
// Created by faraz098 on 5/21/17.
//

#include "List.h"
/*Assignment #2

 * List.cpp
 *
 * Class Description: List data collection ADT.

 *
 * Last modified on: june 2017
 * Author: Faraz Fazlalizadeh
 */
// Default constructor
//
List::List()
    {

//       creates an array of 10 type arr
        MAX_ELEMENTS = 10;
        CareCardList= new arr [MAX_ELEMENTS];    // Data structure with capacity of MAX_ELEMENTS
    // fills up the care card list with empty patient arrays
        for(int i =0; i < MAX_ELEMENTS;i++){
            CareCardList[i].elementscount =0;

            CareCardList[i].cap = 3;
            CareCardList[i].PatientList = new Patient[CareCardList[i].cap];

        }
    }

// Constructor
// does the same thing as above but you can control the capazity of each pattient list
List::List(int Capacity){

    MAX_ELEMENTS = 10;
    CareCardList= new arr [MAX_ELEMENTS];    // Data structure with capacity of MAX_ELEMENTS
    for(int i =0; i < MAX_ELEMENTS;i++){

        CareCardList[i].elementscount =0;
        CareCardList[i].cap = Capacity;
        CareCardList[i].PatientList = new Patient[CareCardList[i].cap];

    }


}

//gets the first number of the careCArd
int List::GetFirstNum (const Patient& needed){
    string newElementCareCard = needed.getCareCard();
    char firstNum = newElementCareCard[0];
    int first_num = firstNum - '0';
    return first_num;
}


// Description: Returns the total element count currently stored in List.
int  List::getElementCount() const{

    return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
bool List::insert(const Patient& newElement){

    // temp patient with no information for swapping

    Patient tp;

    // finds the first care card number of newElement
    int first_num = GetFirstNum(newElement);

    // checks to see if patient already exists
    if(search(newElement) != NULL){
        cout << "\n\nPatient already exist! \n\n";
    }
    else{

        // if element count is bigger than max amount of element don't allow inserting
        if (CareCardList[first_num].elementscount >=  CareCardList[first_num].cap){
            int cap = CareCardList[first_num].cap * 2;				//make a int cap for the size of temp array
            Patient *temp = new Patient[cap];			//make a temporary array


            for (int i = 0; i <CareCardList[first_num].elementscount ; i++) {	//move everythig from old array to new array
                temp[i]  = CareCardList[first_num].PatientList[i];
            }
            delete[] CareCardList[first_num].PatientList;						//clean the old array
            CareCardList[first_num].PatientList = NULL;

            CareCardList[first_num].cap = 2* CareCardList[first_num].cap;			//double the capacity of the original array

            cout << "\n the new size is " << CareCardList[first_num].cap << endl;
            CareCardList[first_num].PatientList = temp;							//set old array to new one
//            delete[] temp;						//clean the old array
//           temp = NULL;

        }


       // if it the first patient add in at index 0 and increment the element count
        if (CareCardList[first_num].elementscount  == 0 ){

            CareCardList[first_num].PatientList[0] = newElement;

            CareCardList[first_num].elementscount++;
            elementCount++;

        }else {
            // else add the at index of element count

            CareCardList[first_num].PatientList[CareCardList[first_num].elementscount] = newElement;
            CareCardList[first_num].elementscount++;
            elementCount++;



        }


        cout << "\n\nelements count : " <<CareCardList[first_num].elementscount << endl << endl;



        //sorting in ascending order
        //go through the list and if the care card number of the next patient is
        //less than the previous one then swap. and do that for the entire list
        for (int i =0 ; i < CareCardList[first_num].elementscount; i++) {
            for(int j = i+1; j < CareCardList[first_num].elementscount;j++){

                if (CareCardList[first_num].PatientList[i] > CareCardList[first_num].PatientList[j]) {
                    tp = CareCardList[first_num].PatientList[i];
                    CareCardList[first_num].PatientList[i]= CareCardList[first_num].PatientList[j];
                    CareCardList[first_num].PatientList[j] = tp;



                }

            }

        }
    }
    cout << "\n\nPatient has been added!\n\n";
    return true;

}
// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
bool List::remove( const Patient& toBeRemoved ){
    // gets the first care card number of toBERemoved
    int first_num = GetFirstNum(toBeRemoved);
    Patient tmp;
    //check to see if the patient already exits
    if(search(toBeRemoved) == NULL){
        cout << "cannot find the person you are looking for \n\n";;
        return false;
    }else{

        // if the patient does not already exits then
        // move back all the other patients one spot and decrease the element count
        for (int i =0; i < CareCardList[first_num].elementscount; i++){
                if(CareCardList[first_num].PatientList[i] == toBeRemoved){

                    for(int w = i; w < CareCardList[first_num].elementscount-1 ; w++){
                        CareCardList[first_num].PatientList[w] = CareCardList[first_num].PatientList[w+1];
                    }
                    CareCardList[first_num].PatientList[CareCardList[first_num].elementscount -1 ] = tmp;
                    CareCardList[first_num].elementscount--;
                    elementCount--;

                }


        }
        cout << "Patient has been removed from the list\n";

        return true;


    }





}

// Description: Remove all PatientList.
void List::removeAll(){
//    int counter = 9;
    Patient tmp;
    //calls the remove method until the element counter is 0
      for(int counter= 0;counter < 10;counter++){

            for (int i = 0; i < CareCardList[counter].elementscount;i++){
                cout << "i is:" << i << endl;
                CareCardList[counter].PatientList[i] = tmp;
                if(remove(CareCardList[counter].PatientList[i]) == false){

                    cout << "called...\n";
                }

            }



      }

//
//
//    cout <<"list is now empty\n\n";
//    cout << "Elements count  :   ... \n";
//    cout << CareCardList[0].elementscount <<endl;
//    cout << CareCardList[1].elementscount <<endl;
//    cout << CareCardList[2].elementscount <<endl;
//    cout << CareCardList[3].elementscount <<endl;
//    cout << CareCardList[4].elementscount <<endl;
//    cout << CareCardList[5].elementscount <<endl;
//    cout << CareCardList[6].elementscount <<endl;
//    cout << CareCardList[7].elementscount <<endl;
//    cout << CareCardList[8].elementscount <<endl;
//    cout << CareCardList[9].elementscount <<endl;
//
//    cout << "cap .... \n";
//    cout << CareCardList[0].cap << endl;
//    cout << CareCardList[1].cap << endl;
//    cout << CareCardList[2].cap << endl;
//    cout << CareCardList[3].cap << endl;
//    cout << CareCardList[4].cap << endl;
//    cout << CareCardList[5].cap << endl;
//    cout << CareCardList[6].cap << endl;
//    cout << CareCardList[7].cap << endl;
//    cout << CareCardList[8].cap << endl;
//    cout << CareCardList[9].cap << endl;
//
//
//
//    cout << elementCount;

}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target){

    int first_num = GetFirstNum(target);

    //go through the entire code and if the u find the target patient
    //return a pointer to it

    for (int i =0; i < CareCardList[first_num].elementscount; i ++){

        if (CareCardList[first_num].PatientList[i] == target){
            return &CareCardList[first_num].PatientList[i];
        }else{ continue;}

    }


    return NULL;



}

// Description: Prints all PatientList stored in List.
void List::printList( ){
    if(getElementCount() == 0){
        cout << "The list is empty...\n";
    }else{



        for (int i =0 ; i < MAX_ELEMENTS;i++){

            for(int j =0; j< CareCardList[i].elementscount;j++){
                if(CareCardList[i].PatientList[j].getCareCard() == "0000000000"){
                    continue;
                }else{

                    CareCardList[i].PatientList[j].printPatient();
                    cout << endl << endl;
                }
            }
        }
    }




}
// Destructor
List::~List() {
    //delete all the patient list arrays stored in careCArd list
    for(int i =0; i < MAX_ELEMENTS;i++){

        delete[] CareCardList[i].PatientList;
        CareCardList[i].PatientList = NULL;

    }
    // delete CareCardList and set it to NULL
    delete[] CareCardList;
    CareCardList =NULL;
}