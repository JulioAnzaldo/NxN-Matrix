#include <iostream>
#include <math.h>

using namespace std;

//Function
int getDeterminant(int matrix[10][10], int n);

int main() {
  int n;
  int matrix[10][10];
  
  //Initialize matrix with desired size
  cout << "Enter desired size of our NxN matrix: ";
  cin >> n;

  //Grabs elements for our matrix
  cout << "Enter the elements of the matrix: ";
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> matrix[i][j];
    }
  }
  
  //Prints out the matrix
  cout << "The chosen matrix is:" << endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
  cout << endl;
  
  //Prints out the determinant
  cout << endl << "The determinant of the matrix is: " << getDeterminant(matrix, n);

  return 0;
};

//Function definition
int getDeterminant(int matrix[10][10], int n) {

  //Initialize our variables for the determinant and the smaller matricies we will break the bigger ones up into
  int det = 0, i, j, k;
  int subMatrix[10][10];

  //If matrix is a 1x1 return the only element
  if(n == 1)
    return matrix[0][0];
  
  //If matrix is a 2x2 then we can return the simple 2x2 formula 
  if(n == 2)
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);

  //If matrix is not a 1x1 or 2x2 then we need to break it into smaller matrices
  else
  {
    for (k = 0; k < n; k++) {
       int subi = 0;
       for (i = 1; i < n; i++) {
          int subj = 0;
          for (j = 0; j < n; j++) {
             if (j == k)
             continue;
             subMatrix[subi][subj] = matrix[i][j];
             subj++;
          }
          subi++;
       }
      //Calls function recursevly to break down the matrix into smaller matrices
       det = det + (pow(-1, k) * matrix[0][k] * getDeterminant(subMatrix, n - 1));
    }
  }
  return det;
}
