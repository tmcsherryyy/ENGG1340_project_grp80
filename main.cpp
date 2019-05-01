#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <cmath>
using namespace std;

const int tablesize=25, tablenum=25;

struct set{
    int ava, time, child, adult;
};


//to initialise the array table
//Tables which are available for customers store 0
//Tables which are occupied store 1
//others store -1
void setting(set table[tablesize][tablenum], int &price_a, int &price_c, int &timeallowance){
    
    //Reset the price per head
    cout << "Price per head for adult is : ";
    cin >> price_a;
    cout << "Price per head for child is : ";
    cin >> price_c;
    
    //time allowance
    cout << "Time allowance for each table (in mins) : ";
    cin >> timeallowance;
    
    //Reset the table
    int size,num;
    for (int i=0; i<tablesize; i++){
        for (int j=0; j<tablenum; j++){
            table[i][j].ava = -1;
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
            table[size][i].ava=0;
        }
        cout << "Table size of (Enter 0 to finish setting) : ";
        cin >> size;
    }
}


void newtable(set table[tablesize][tablenum]){
    
    int adu, chi, num;
    cout << "Number of adults : ";
    cin >> adu;
    cout << "Number of child : ";
    cin >> chi;
    
    num = adu + chi ;
    if (num>tablesize)
        cout << "No suitable table for " << num << " customers" << endl;
    
    //find a suitable table
    for (int i=num; i<tablesize; i++){
        
        //check the smallest table size for number of customers input
        if (table[i][0].ava != -1){
            
            //check if there is table available
            for (int j=0; j<tablenum; j++){
                
                //return table number that waiter should bring customers to
                if (table[i][j].ava == 0){
                    cout << "Please bring them to table " << i << j << " " << endl;
                    table[i][j].adult = adu ;
                    table[i][j].child = chi ;
                    table[i][j].ava = 1 ;
                    
                    
                    break;
                }
                //return "Pleaese wait!" when there is no table available
                else if ((table[i][j].ava == 1) && (table[i][j+1].ava == -1)){
                    cout << "Please wait!" << endl;
                }
                
            }
            break;
        }
        if (i == tablesize-1)
            cout << "No suitable table for " << num << " customers" << endl;
    }
    
}


int seperatetableno(int num, int &i, int &j){
    
    if (num<100){
        i = num/10;
        j = num%10;
    }
    else if (num>99){
        i = num/100;
        j = num%10;
    }
    return i;
}


void release(set table[tablesize][tablenum], int price_a, int price_c){
    
    int num,i,j;
    cout << "Table number : ";
    cin >> num;
    seperatetableno(num,i,j);
    
    cout << "------------------" << endl << "RECEIPT" << endl;
    cout << "Number of adults : " << table[i][j].adult << endl;
    cout << "Number of child : " << table[i][j].child << endl;
    
    int total=0;
    cout << price_c << price_a;
    total = (price_c * table[i][j].child) + (price_a * table[i][j].adult) ;
    
    cout << "Net total before service charge: " << total << endl;
    cout << "Total amount = " << total*1.1 << endl << "------------------" << endl;
    
    table[i][j].child = 0;
    table[i][j].adult = 0;
    table[i][j].ava = 0;
    table[i][j].time = 0;
}


void searchtable(set table[tablesize][tablenum]){
    
    int num,i,j;
    cout << "Table number : ";
    cin >> num;
    seperatetableno(num,i,j);
    
    if (table[i][j].ava == 1){
        cout << "This table is occupied" << endl;
        cout << "Number of adults of this table : " << table[i][j].adult << endl;
        cout << "Number of child of this table : " << table[i][j].child << endl;
        cout << "Time remaining for this table : " << endl;
    }
    else if (table[i][j].ava == 0)
        cout << "This table is available for " << i << endl;
    else if (table[i][j].ava == -1)
        cout << "Table number doesn't exist!" <<  endl;
    
}


int main(){
    set table[tablesize][tablenum];
    int price_a, price_c, timeallowance;
    setting(table, price_a, price_c,timeallowance);
    
    
    int userinput;
    cout << endl;
    cout << "(1:New Table ; 2:Bill & Release Table ; 3:Search Table ; 4:Reset ; 9:Quit Program)" << endl << "Operate : " ;
    cin >> userinput;
    cout << endl;
    
    while (userinput != 9){
        switch (userinput) {
            case 1:
                newtable(table);
                break;
                
            case 2:
                release(table, price_a, price_c);
                break;
                
            case 3:
                searchtable(table);
                break;
                
            case 4:
                setting(table,price_a, price_c, timeallowance);
                break;
                
        }
        cout << endl;
        cout << "(1:New Table ; 2:Bill & Release Table ; 3:Search Table ; 4:Reset ; 9:Quit Program)" << endl << "Operate : " ;
        cin >> userinput;
        cout << endl;
        
    }
    
    cout << "System turning off..." <<endl;
    return 0;
}

