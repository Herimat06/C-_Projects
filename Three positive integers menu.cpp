/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{	//declare variables
	int num1, num2, num3; //the three integers the user will have to enter
	int bigger , middle , smallest;
	int options;
	bool a, b;
	bool check = false; // To check if an input is already entered.

	//constants for the menu choices

	     a = true,
	     b = false; //planning to use it to determine whether it is a triangle or not
	int choice ;// to hold the menu choice

 	// Display a menu and get a choice from the user
 do
 {

	cout << "\t Three positive integers menu.\n\n"
	    << "1. Enter three positive integers less than equal to 100 : \n"
	    << "2. List all the three positive integers in ascending order : \n"
	    << "3. Do the three integers form sides of a triangle ? \n"
	    << "4. Quit \n\n"
	    << "Enter your choice : ";
       cin>>choice;




    switch (choice)
    {



        case 1 : do

               {
                cout<< "Enter three positive integers less than equal to 100 : "<<endl;
                cin>>num1>>num2>>num3;

               }while ((num1 <= 0 || num1 > 100) || (num2 <= 0 || num2 > 100) || (num3 <= 0 || num3 > 100));
               // while (!(((num1 && num2 && num3) > 0) && ((num1 && num2 && num3)<=100)))
               check = true;
  				break;

			// Before the second and the third  option get executed we have to make sure if the first option is executed , for that I am tgnking abt using a boolean variable to check if true or false the number has been enterred and if they are positive and less than equal to 100.

		case 2 : if (check)
                {
                    if (num1 > num2){
                        if (num1 > num3){
                            if (num2 > num3){
                                cout << num3 << " " << num2 << " " << num1 << endl;
                            }
                            else {
                                cout << num2 << " " << num3 << " " << num1 << endl;
                                }
                        }
                    }
                    if (num2 > num1){
                        if (num2 > num3){
                            if (num1 > num3){
                                cout << num3 << " " << num1 << " " << num2 << endl;
                            }
                            else {
                                cout << num1 << " " << num3 << " " << num2 << endl;
                                }
                            }
                        }

                    if  (num3 > num1){
                        if (num3 > num2){
                            if (num1 > num2){
                                cout << num2 << " " << num1 << " " << num3 << endl;
                            }
                            else {
                                cout << num1 << " " << num2 << " " << num3 << endl;
                            }
                        }
                    }
                } else {
                    cout << "Please, enter three positive integers that are less than or equal to 100, first!" << endl;
                }

           break;

		case 3 :
				   if (check){
                        if (num1 > num2){
                            if (num1 > num3){
                                if (num2 > num3){
                                    smallest = num3;
                                    middle = num2;
                                    bigger = num1;
                                }
                                else {
                                    smallest = num2;
                                    middle = num3;
                                    bigger = num1;
                                    }
                            }
                        }
                        if (num2 > num1){
                            if (num2 > num3){
                                if (num1 > num3){
                                    smallest = num3;
                                    middle = num1;
                                    bigger = num2;
                                }
                                else {
                                    smallest = num1;
                                    middle = num3;
                                    bigger = num2;
                                    }
                                }
                            }

                        if  (num3 > num1){
                            if (num3 > num2){
                                if (num1 > num2){
                                    smallest = num2;
                                    middle = num1;
                                    bigger = num3;
                                }
                                else {
                                    smallest = num1;
                                    middle = num2;
                                    bigger = num3;
                                }
                            }
                        }



                        if (smallest+middle >= bigger){
                            cout << "It is a triangle" << endl;
                        }
                        else{
                            cout << "That ain't no triangle fool!!!!!!!" << endl;
                        }

				   }
				   else {
                        cout << "Please, enter three positive integers that are less than or equal to 100, first!" << endl;
				   }
                 break;

        case 4 : choice = 4;
                break;
    }

 } while ( choice != 4);



return 0;
}
