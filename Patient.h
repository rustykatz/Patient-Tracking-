//
// Created by faraz098 on 5/21/17.
//

#ifndef A1CMPT225_PATIENT_H
#define A1CMPT225_PATIENT_H
#include <iostream>
using namespace std;

/*Assignment #2

 * Patient.h
 *
 * Class Description: List data collection ADT.

 *
 * Last modified on: june 2017
 * Author: Faraz Fazlalizadeh
 */

#pragma once

#include <iostream>
#include <string>
using namespace std;

class Patient {

private:
    string name;
    string address;
    string phone;
    string email;
    string careCard;

public:
    // Default Constructor
    // Description: Create a patient with a care card number of "0000000000".
    // Postcondition: All data members set to "To be entered",
    //                except the care card number which is set to "0000000000".
    Patient();

    // Parameterized Constructor
    // Description: Create a patient with the given care card number.
    // Postcondition: If aCareCard does not have 10 digits, then care card is set to "0000000000".
    //                All other data members set to "To be entered".
    Patient(string aCareCard);

    // Getters and setters
    // Description: Returns patient's name.
    string getName() const;

    // Description: Returns patient's address.
    string getAddress() const;

    // Description: Returns patient's phone number.
    string getPhone() const;

    // Description: Returns patient's email.
    string getEmail() const;

    // Description: Returns patient's care card number.
    string getCareCard() const;

    // Description: Sets the patient's name.
    void setName(const string aName);

    // Description: Sets the patient's address.
    void setAddress(const string anAddress);

    // Description: Sets the patient's phone number.
    void setPhone(const string aPhone);

    // Description: Sets the patient's email.
    void setEmail(const string anEmail);

    // Overloaded Operators
    // Description: Comparison operator. Compares "this" Patient object with "rhs" Patient object.
    //              Returns true if both Patient objects have the same care card number.
    bool operator==(const Patient & rhs);

    // Description: Greater than operator. Compares "this" Patient object with "rhs" Patient object.
    //              Returns true if the care card number of "this" Patient object is > the care card number of "rhs" Patient object.
    bool operator>(const Patient & rhs);

    // Description: Prints the content of "this" patient.
    void printPatient();

};
// end of Patient.h


#endif //A1CMPT225_PATIENT_H
