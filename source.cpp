#include <iostream>
using namespace std;

const int tablesize=25, tablenum=25;

//initialise() initialise the array table
//Tables which are available for customers store 0
//Tables which are occupied store 1
//others store -1
void initialise(int table[tablesize][tablenum]){
    
    for (int i=0; i<tablesize; i++){
        for (int j=0; j<tablenum; j++){
            table[i][j]=-1;
            
            //initialise table of 2//
            if (i==2){
                if (j<4){
                    table[i][j]=0;
                }
            }
            
            //initialise table of 4//
            if (i==4){
                if (j<4){
                    table[i][j]=0;
                }
            }
            
            //initialise table of 6//
            if (i==6){
                if (j<2){
                    table[i][j]=0;
                }
            }
            
            //initialise table of 8//
            if (i==8){
                if (j<2){
                    table[i][j]=0;
                }
            }
            
            //initialise table of 12//
            if (i==12){
                if (j<1){
                    table[i][j]=0;
                }
            }
            
            }
    }
    
}

void setting(int table[tablesize][tablenum], int price){
    
    //Reset the price per head
    cout << "Price per head is : ";
    cin >> price;
    
    //Reset the table
    int size,num;
    for (int i=0; i<tablesize; i++){
        for (int j=0; j<tablenum; j++){
            table[i][j]=-1;
        }
    }
    
    //For users to input table size and corresponding number of table
    //Enter 0 for size when all settings are done
    cout << "Table size of : ";
    cin >> size;
    while(size!=0){
        cout << "Number of table of " << size << " is : ";
        cin >> num;
        for (int i=0; i<num; i++){
            table[size][i]=0;
        }
        cout << "Table size of : ";
        cin >> size;
    }
    
}

int main(){
    int table[tablesize][tablenum];
    int price=180;
    initialise(table);
    
    string userinput;
    //search,occupy,release,setting
    cout << "Operate : ";
    cin >> userinput;
    if (userinput == "setting")
        setting(table,price);
    
    return 0;
}

