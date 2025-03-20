#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Function Prototypes
void ReadIntoDataArray(int array[], int* ptrArray[], unsigned int size, ifstream& inFile);
void SwapIntPtr(int** a, int** b);
void BubbleSortArray (int* ptrArray[], unsigned int size);
void DisplayArray(int dataArray[], unsigned int size);
void DisplayArray(int* ptrArray[], unsigned int size);

//Main Function
int main()
{
    const string fileName= "arrayData.txt";
    ifstream inFile(fileName);
    
    unsigned int size;
    
    if (inFile.is_open()) //Check if file is open
        {
            while(inFile.good()) 
            {

                while(!inFile.eof()) 
                {
                    inFile >> size;
                    
                    int array[size];
                    int* ptrArray[size];
                    
                    ReadIntoDataArray(array, ptrArray, size, inFile);
                    BubbleSortArray(ptrArray, size);
                    
                    cout << "The Pointer Array of sorted pointer elements: " << endl << endl;
                    DisplayArray(ptrArray, size); //Sorted Display Function
                    
                    cout << "Data Array elements are: " << endl << endl;
                    DisplayArray(array, size);
                    
                    //Pause before next iteration
                    cout << "\nPress the enter key once or twice to continue..." << endl << endl;
                    cin.ignore();
                    cin.get();
                }
                
            }
            cout << "Program done" << endl; 
        } else 
        {
            //Handles the case in which the file cannot be opened (Error)
            cout << "Error. File could not be opened" << endl; 
        }
        
    inFile.close();
    return 0;
}

//Function to read from file and store into array
void ReadIntoDataArray(int array[], int* ptrArray[], unsigned int size, ifstream& inFile) 
{
    string line;
    getline(inFile, line);
    
    if (inFile.is_open()) 
    {
        for (int i = 0; i < size; i++) 
        {
            inFile >> array[i];
            ptrArray[i] = &array[i]; //Assign pointer array to regular array by respective index
        }
    } 
    else 
    {
        cout << "Error" << endl;
        return;
    }
    
}

//Function to swap elements
void SwapIntPtr(int** a, int** b) 
{
    int* temp = *a;
    *a = *b;
    *b = temp;
    
}

//(Bubble Sort) Function to sort pointer array 
void BubbleSortArray(int* ptrArray[], unsigned int size) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (*ptrArray[j] > *ptrArray[j + 1]) 
            {
                SwapIntPtr(&ptrArray[j], &ptrArray[j + 1]);
            }
        }
    }
    
}

//Function to display original array
void DisplayArray(int dataArray[], unsigned int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << setw(6) << dataArray[i] << " ";
    }
    cout << endl << endl;
}

//Function to display sorted pointer array
void DisplayArray(int* ptrArray[], unsigned int size) 
{
    for (int i = 0; i < size; i++) 
    {
        cout << setw(6) << *ptrArray[i] << " ";
    }
    cout << endl << endl;
}

    