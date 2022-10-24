//The Demetris Leadership Center.
//Problem solving and program design : A case to study
//Programmer : HERI MATABARO , Sophomore in computer science.
#include <iostream>
#include <string>
#include <array>
using namespace std ;
int getProdNum();
int binarySearch(const int [] , int , int);
void displayProd(const string[], const string[],double prices , int);
const int num_prods = 9;
const int min_prodnum = 914;
const int max_prodnum = 922;
int main()
{   int prodNum;
    int index;
    char repeat;
   string producttitle[9] = { "Six Steps To Leadership" ,
                             "Six Steps To Leadership",
			     "The Road to Excellence",
			     "Seven Lessons of Quality",
			     "Seven lessons of Quality",
			     "Seven Lessons of Quality",
			     "Teams Are made, Not Born",
			     "Leadership for the Future",
   			     "Leadership for the Future"};
   string productdescription[9]= { "Book" , "Audio CD",
				   "DVD" , "Book" ,"Audio CD",
				   "DVD" , "Book" , "Book",
				   "Audio CD" };
   int productnumber[9] = { 914 , 915 , 916, 917 , 918 , 919 , 920 , 921 , 922};
   double price[9] = { 12.95 , 14.95 , 18.95 , 16.95 , 21.95 , 31.95 , 14.95 , 14.95 , 16.95 };
  do
  {
     prodNum = getProdNum();
     index = binarySearch( id , num_prods , prodNum);
    if (index == -1 )
    { cout << "That product number does not exist \n";
    }
    else
     displayProd(title, description , prices , index);
    // Ask the user if he would like to continue again.
    cout << "Would you like to make another choice ?\n Press Y to continue and N to end the program : ";
    cin>> repeat;
   } while ( repeat ! == "N" || repeat ! == "n" );
return 0;
}

int getProdNum()
{
   int ProdNum;
   cout<< "Which Product would you like to purchase ? ";
   cin>>ProdNum;
   //The input must be validate by the user, let's use a while loop statement for that
   while ( ProdNum < min_prodnum && ProdNum > max_prodnum)
   { cout << "This an invalid choice, please make a choice in a range of 914 - 922 : ";
     cin>>ProdNum;
   }
  return ProdNum;
}
int binarySearch( const int [] , int , int)
{ int value;
  int first = 0,
      last = num_prods - 1,
      middle,
      position = -1;// the program will return -1 , if the position is not found.
  bool found = false; // Flag.
 while (!found && first <= last)
 { middle = (first + last ) / 2;
   if ( array[middle] == value )
   {
     found = true;
     position = middle;
    }
   else if (array[middle] > value)
    last = middle - 1;
   else
    first = middle + 1;
  }return position;
}
void displayProd(const string title [] , const string description [], const double prices[] , int index)
{
  cout << "Title : " << title[index] << endl;
  cout << "Description : " << description[index] <<endl;
  cout << "Price : $ " << prices[index] << endl;
}
