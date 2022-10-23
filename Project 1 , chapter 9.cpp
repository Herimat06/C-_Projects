/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Project 1 , chapter 9.
//Programmer : Heri Matabaro
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Functions prototype 

void initialize_array(int [] , int);
int * shuffle_array (const int[]  , int);
void print_array(int [] , int);
int *createOddArray(const int [], int, int &); 
int * createEvenArray(const int [], int, int &);
void array_war(int *, int, int *, int);
void sort_array(int *, int);



int main()
{    
     // Variables declaration.
     int userInput = 0;
     int& size = userInput;
     //Int array[size];
    
     
    // Prompting the user to enter the size of the array.
     
     cout << "Please enter the size of the array : "<< endl;
     cin  >> size;
     
    // Validate the input 
     
     while ( size < 1 || size > 52)
     {
      cout << "The size of your array must be between 1 and 52.";
      cout << " Please enter a size in that range : "<<endl;
      cin  >> size;
     }
     
    // Calling Function initialize_array
    int* array = new int [size];
    cout << "The original array is : ";
    initialize_array( array, size );
    cout << endl;
    
    // Calling the shuffle_array function
    int *shuffled = nullptr; //Define pointers for the shuffle array.
    shuffled = shuffle_array(array, size);
    
    // Display the Shuffle array 
    cout << "The shuffled  array is : ";
    print_array(shuffled,size);
    cout << endl;
    
    
    //Call and display the Odd array.
    int* ptrToOddArr = nullptr;
    int oddNum = 0;
    
    cout << "After call to createOddArray, odd array is : ";
    ptrToOddArr = createOddArray(shuffled, size, oddNum);
    cout << "[";
    for(int i = 0; i < oddNum; i++) 
    {
        cout << *(ptrToOddArr + i) << " ";
    
    }   cout << "]";
        cout << endl;
    
    //Calling and displaying the Even array
    int * ptrToEvenArr = nullptr;
    int  evenNum = 0;
    cout << "After call to createEvenArray, even array is : ";
    ptrToEvenArr = createEvenArray(shuffled , size , evenNum);
    cout << "[";
    for ( int i = 0 ; i < evenNum ; i++)
    {
        cout << *(ptrToEvenArr + i) << " "; 
    
        
    }   cout << "]";
        cout << endl;
        
    // Calling the array_war function
    array_war(ptrToOddArr, oddNum, ptrToEvenArr, evenNum);
    

    

    return 0;
}
void initialize_array(int array[] , int size)
{  
    /*this function initializes an array by assigning a random number to each element of the dynamically allocated array*/
    //Initialize array with whole number from 0 to size-1
    for ( int i = 0 ; i < size ; i++)
    {
        array [i] = i ; 
    }
    
    // Display the array
    cout << "[";
    for ( int i = 0 ; i < size ; i++)
    {
        cout << array[i] << " ";
    }
    cout << "]";
}

int * shuffle_array (const int array [], int size)
{
    // In this function we will create a new array with a new allocation memory .
    
    int *newArray = nullptr;
    newArray = new int[size];
    
   // Copy the array's content to the new array
    for ( int i = 0 ; i < size ; i++)
    {
        newArray[i]= array[i];
    }
    // Using another  loop to randomly shuffle the original array
     srand(time(0));
    
    for ( int i = (size - 1) ; i > 0 ; i--)
    {   
        int j = rand () % (i + 1) ;
        int temp = newArray[j];
        newArray[j]= newArray[i];
        newArray[i]= temp;
    }
    return newArray;
}
void print_array( int array[], int size)
{
       cout << "[";
    for ( int i = 0 ; i < size ; i++)
    {
      cout << array[i]<< " ";
      
    }
       cout<< "]";
}
int * createOddArray(const int array [], int size, int &Odd)
{  
    
   for ( int i = 0 ; i < size ; i++)   
   {
        if ((array[i] % 2) != 0)
        {
            Odd++;
        }
    }
    
    int *newOddarray = new int [Odd];
    int y = 0;
    for ( int i = 0 ; i < size; i++)
    {
        if ((array[i] % 2) != 0)
        {
            newOddarray[y] = array[i];
            y++;
        }
    }    
    return newOddarray;
}
int * createEvenArray(const int array [], int size, int &Even)
{
    
    for ( int i = 0 ; i < size ; i++)
    {
        if (array[i] % 2 == 0)
        {
            Even++;
        }
    }
    
    int *newEvenarray = new int [Even];
    int z = 0;
    for ( int i = 0 ; i < size ; i++)
    {
        if (array[i] % 2 == 0)
        {
            newEvenarray[z] = array[i];
            z++;
        }
    }
    return newEvenarray;
}
void array_war(int *ptrToOddArr, int oddNum, int *ptrToEvenArr, int evenNum)
{
    //The function should compare the size of both array , even and ood array and also compare the elements inside both arrays
    int larger = 0 ; 
    int smallest ;
    int* NewarrayFight = nullptr;
    NewarrayFight = new int [larger];
    
    
    if ( oddNum > evenNum ) // Comparing the size of both array 
    {
        
        cout << "The array fight winners were : ";
        cout << "[";
        for (int i = 0 ; i < oddNum ; i++)
        {
            
            larger = *(ptrToEvenArr + i);
            smallest = *(ptrToOddArr + i);
            
            if ( larger > smallest)
            {
                NewarrayFight[i] = larger;
            }
            else
            {
                NewarrayFight[i] = smallest;
            }
            cout << NewarrayFight[i] << " ";       
        }
        cout << "]";
    }
    
    else //In this case the even number won
    {
        
        cout << "The array fight winners were : ";
        cout << "[";
        for ( int i = 0 ; i< evenNum ; i++)
        {   
            
            larger = *(ptrToEvenArr + i);
            smallest  = *(ptrToOddArr + i);
            
            if (larger > smallest)
            {
                NewarrayFight[i] = larger;
            }
            else 
            {
                NewarrayFight[i] = smallest;
            }
            cout << NewarrayFight[i] << " "; 
        }
        
    }
    cout << "]";
    cout << endl;
    
    sort_array(NewarrayFight, larger);
    cout << "Sorted ArrayFight winners were : [";
    for (int i = 0 ; i < larger   ; i++)
     {
         cout <<*(NewarrayFight + i) <<" ";
     }
       cout << "]";
}   
void sort_array(int *NewarrayFight, int size)
{ 
    int temp;
    
    for (int maxElement = size - 1 ; maxElement > 0 ; maxElement--)
    {
            for (int index = 0; index < maxElement ; index++)
            {
                
                if (NewarrayFight[index] > NewarrayFight[index + 1])
                {
    
                    temp = NewarrayFight[index];
                    NewarrayFight[index] = NewarrayFight[index + 1];
                    NewarrayFight[index + 1] = temp;
                    
                }
            }
    }
}























