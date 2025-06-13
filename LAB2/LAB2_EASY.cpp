#include <iostream>
using namespace std;

int main(){
// PUZZLE ONE // 
// Easy: Check given matrix is magic square or not //

int n;

cout << "Enter number of rows & columns: ";
cin >> n;

int testArray[n][n];

cout << "Enter values for array (row by row)"<<endl;

for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout << "Value for ["<< i << ", " << j << "] :";
        cin >> testArray[i][j];
    }
}

// To check input
cout << "Given array:" << endl;
for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
        cout << testArray[i][j];
        cout << "  ";
    }
    cout << endl;
}

int sumd_primary=0;
int sumd_secondary=0;
int rowSum=0;
int colSum=0;

for (int i=0; i<n; i++){
        sumd_primary+=testArray[i][i];
        sumd_secondary+=testArray[i][n-i-1];
}

for (int i=0; i<n; i++){
    for (int j=0; j<n; j++){
         rowSum += testArray[i][j];
        colSum += testArray[j][i];
    }
}

if (sumd_secondary==sumd_primary && rowSum==colSum){
    cout << "Yes, magic square because the sum of each row and each column and diagonals sum is same = " << rowSum;
} else {
    cout << "No, it is not magic square because the sum of each row and each column and diagonals sum is not the same";
}

}
