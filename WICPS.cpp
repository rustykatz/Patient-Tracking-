#include <iostream>
#include "List.h"

/*Assignment #2

 * WICPS.cpp
 *
 * Class Description: List data collection ADT.

 *
 * Last modified on: june 2017
 * Author: Faraz Fazlalizadeh
 */

using namespace std;
int main() {


    //store user input
    string userInput;
    //store the given patients
    List list(2);

    while(userInput[0] != 'e' || userInput[0] != 'E') {
        //flag for knowing when the list is empty
        bool flag = true;
        if (userInput[0] == 'e' || userInput[0] == 'E') {
            break;
        }

        cout << "\n\n(a)to Add a Patient type \"add\"" << endl;
        cout << "(r)to remove a Patient type \"remove\"" << endl;
        cout << "(s)to search a Patient type \"search\"" << endl;
        cout << "(m)to edit Patients type \"modify\"" << endl;

        cout << "(c)to clear list a Patient type \"clear\"" << endl;
        cout << "(p)to print the list of Patients type \"print\"" << endl;

        cin >> userInput;
        //if the user inputs the letter a then
        // the care card, name , address, phone number, email will be added to
        // the patients information and after that the patiet will be added to
        // the created list
        if (userInput[0] == 'a' || userInput[0] == 'A') {

            string careC;
            string name;
            string ad;
            string phoneNum;
            string newEmail;

            cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                    "               insert              \n"
                    "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";


            cout << "please enter user care Card number: ";
            cin >> careC;
            Patient one(careC);

            cout << "please enter user name : ";
            cin.ignore();
            getline(cin , name);
            one.setName(name);

            cout << "please enter user address : ";
            getline(cin, ad);
            one.setAddress(ad);
            cout << "please enter user phone: ";
            getline(cin , phoneNum);

            one.setPhone(phoneNum);

            cout << "please enter user Email : ";
            getline(cin, newEmail);
            one.setEmail(newEmail);
            list.insert(one);

        }




        if (userInput[0] == 'r' || userInput[0] == 'R' ) {

            // checks to see if the list is empty or not
            if(list.getElementCount() == 0){
                cout << "the list is empty...\n";
                flag = false;
            }

            if (flag){
                cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                        "               remove             \n"
                        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

                string remove;
                // creates a temp patient with the given care card number then
                // removes the patient that equals to the temporary one
                cout << "please enter the care card number that you would like to remove... \n";
                cin >> remove;
                Patient temp(remove);
                list.remove(temp);
            }
//
        }
        if (userInput[0] == 's' || userInput[0] == 'S' ) {
            // check to see if the list is empty or not
            if(list.getElementCount() == 0){
                cout << "the list is empty...\n";
                flag = false;
            }
//
            if(flag ){

                cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                        "               search              \n"
                        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                //makes a temp patient with the same care card number
                //creates a patient* in order to save the searched patient
                string search;
                cout << "Please enter the care card number? ";
                cin >> search;
                Patient temp(search);
                Patient *tp;
                tp = list.search(temp);
                if  (tp == NULL){
                    cout << "\nPatient not found...\n";

                }else{


                    cout << endl;
                    tp->printPatient();

                }

            }

        }
        if (userInput[0] == 'm' || userInput[0] == 'M' ) {
            string edit;
            string who;
            string new_name;
            string new_email;
            string new_address;
            string new_phone;
            if(list.getElementCount() == 0){
                cout << "the list is empty...\n";
                flag =false;
            }
            if(flag) {


                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                        "               Modify              \n"
                        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                cout << "enter the care card number that you want to modify?";
                cin >> who;
                Patient looking(who);

                //create a patient * and sets it equal to the patient we are modifying
                Patient *tp;
                tp = list.search(looking);


                while (edit[0] != 'F') {
                    if (tp == NULL) {
                        cout << "patient not found...\n";
                        break;
                    }
                    cout << "what would you like to modify?\n"
                         << "(N)name...\n"
                         << "(E)email...\n"
                         << "(A)address...\n"
                         << "(P)phone...\n"
                         << "(F) finish editing\n";

                    cin >> edit;
                    if (edit[0] == 'f' || edit[0] == 'F') {
                        break;
                    }

                    cin.ignore();
                    if (edit[0] == 'n' || edit[0] == 'N') {
                        cout << "enter the new name...\n";
                        getline(cin, new_name);
                        tp->setName(new_name);
                        cout << "changes has been made...\n";


                    }
                    if (edit[0] == 'E' || edit[0] == 'e') {
                        cout << "enter the new email...\n";

                        getline(cin, new_email);
                        tp->setEmail(new_email);
                        cout << "changes has been made...\n";


                    }
                    if (edit[0] == 'a' || edit[0] == 'A') {
                        cout << "enter the new address...\n";

                        getline(cin, new_name);
                        tp->setAddress(new_address);
                        cout << "changes has been made...\n";

                    }
                    if (edit[0] == 'p' || edit[0] == 'P') {
                        cout << "enter the new Phone number...\n";

                        getline(cin, new_name);
                        tp->setPhone(new_phone);
                        cout << "changes has been made...\n";

                    }
                }
            }
//
        }
         if (userInput[0] == 'c' || userInput[0] == 'C') {
            list.removeAll();
            cout << "your list is now clear...press E to exit the program\n";
        }
        if (userInput[0] == 'p' || userInput[0] == 'P') {
            if (list.getElementCount() == 0) {
                cout << "the list is empty...\n";
                flag = false;
            }
            if (flag) {
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
                        "               print              \n"
                        "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
                list.printList();
            }
        }
    }



    return 0;
}