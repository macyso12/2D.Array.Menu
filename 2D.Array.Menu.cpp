// Macy So
#include <iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

const int r = 3;
const int c = 4;

void FillArray(int num [r][c], int);
void RowSum (int num[r][c], int) ;
void ColSum (int num[r][c], int) ;
void TolSum (int num[r][c], int) ;
void LargestRowSum (int num[r][c], int) ;
void LargestColSum (int num[r][c], int) ;


string PrintMenu (){
    int choice ;
    string choice1;
    int num [3][4] ;

    do {
        cout << "1. Fill 2d array" << endl ;
        cout << "2. Find row sum" << endl ;
        cout << "3. Find col sum" << endl ;
        cout << "4. Find total sum" << endl ;
        cout << "5. Find row with largest sum" << endl;
        cout << "6. Find col with largest sum" << endl ;
        cout << "7. Quit" << endl ;
        cin >> choice ;
    
        if (choice == 7){
            cout << "Goodbye!" << endl ;
            break;
        }
        if (choice == 1){
            FillArray(num,c);
        }
        if (choice == 2){
            RowSum (num,r);
        }
        if (choice == 3) {
            ColSum (num,r) ;
        }
        if (choice == 4){
            TolSum (num,r);
        }
        if (choice == 5){
            LargestRowSum (num,r);
        }
        if (choice == 6){
            LargestColSum (num,r);
        }
    }
    while (choice != '0' || choice != '1' || choice != '2' || choice!= '3'|| choice != '4' || choice != '5' || choice != '6' || choice != '7');
    
    return choice1;
}

int main() {
    
    PrintMenu();
    
    return 0;
}
void FillArray (int num [r][c], int c ){
    srand((unsigned) time(0)) ;
    for ( int i = 0; i < r; ++i){
        for( int j = 0;  j < c ; ++j){
            num [i][j] = rand()%10;
        }
    }
    for( int i = 0; i < r; ++i){
        cout << "[" ;
        for( int j = 0; j < c; ++j){
            cout << num [i][j] << " " ;
        }
        cout << "]" ;
        cout << endl ;
    }
}
void RowSum (int num[r][c], int numRows){
    int total = 0 ;
    int userNum ;
    cout << "Enter row index? 0-2: " ;
    cin >> userNum ;
    for (int i = 0; i < c ; i ++){
        total += num[userNum][i] ;
    }
    cout << endl ;
    cout << "For row " << userNum << " sum = " << total  << endl ;
    cout << endl ;
}

void ColSum (int num[r][c], int numRows){
    int total = 0 ;
    int userNum ;
    cout << "Enter column index? 0-3:  " ;
    cin >> userNum ;
    for (int i = 0; i < r ; i ++){
        total += num[i][userNum] ;
    }
    cout << endl ;
    cout << "The sum of all column " << userNum << " numbers is " << total  << endl ;
    cout << endl ;
}

void TolSum (int num[r][c], int numRows){
    int total = 0 ;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            total += num [i][j];
        }
    }
    cout << "The total sum is " << total << endl ;
    cout << endl ;
}

void LargestRowSum (int num[r][c], int numRows){
    int Largest = 0;
    int idx = -1;
    int total = 0 ;
    
    for (int i = 0; i < r; i++){
        total = 0;
        
        for (int j = 0; j < c; j++){
            total += num [i][j];
        }
        if (total > Largest){
            Largest = total ;
            idx = i;
        }
    }
    cout << "Row " << idx << " has the largest sum " << total << endl ;

}
void LargestColSum (int num[r][c], int numRows){
    int Largest = 0;
    int idx = -1;
    int total = 0 ;
    
    for (int i = 0; i < c; i++){
    total = 0;
    for (int j = 0; j < r; j ++){
        total += num [j][i];
    }
        if (total > Largest){
            Largest = total ;
            idx = i;
        }
    }
    cout << "Column " << idx << " has the largest sum " << total << endl ;

}
