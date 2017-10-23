#include <iostream>
#include "pa1.h"
using namespace std;

void pa1::printSquare(int **square, int s) {

  //print the rows in descending order
  for (int i = s-1; i >=0 ; i--) {
    //print the columns in ascending order
    for (int j = 0; j <s; j++) {

      //print each ith jth element, preceded by a tab
      cout << "\t" << square[i][j];
    }

    //finish each line with a new line
    cout << endl;
  }
}

int pa1::getValidSize() {

  bool validSize = false;
  int s;

  do {
    cout << "Enter the size of a magic square: ";
    cin >> s;

    //a valid size is between 1 and 16 noninclusive and odd
    validSize = s > 1 && s < 16 && s%2 == 1;

    if (!validSize) {
      cout << "Invalid magic square size. Pick 3, 5, 7, 9, 11, 13, or 15." << endl;
    }

  } while(!validSize);

  //return the valid size
  return s;
}

void pa1::createSquare(int **square, int s) {

  //start at the element in the top row and the middle column
  //following the Siamese method...

  //i and j correspond to rows and columns
  //x refers to the number to be inserted in it's proper element
  int i = s-1, j = s/2, x = 1;

  square[i][j] = x++;

  for (int k = 0; k < s*s-1; k++) {

    //up and right is valid
    if ((i+1)<s && (j+1)<s && square[i+1][j+1] == 0) {

      i++;
      j++;
      square[i][j] = x++;
    }
    //right is invalid, up is valid
    else if ((i+1)<s && (j+1)>=s && square[i+1][0] == 0) {

      i++;
      j = 0;
      square[i][j] = x++;
    }
    //right is valid, up is invalid
    else if ((i+1)>=s && (j+1)<s && square[0][j+1] == 0) {

      i = 0;
      j++;
      square[i][j] = x++;
    }
    //right is invalid, up is invalid
    else if ((i+1)>=s && (j+1)>=s && square[0][0] == 0) {

      i = 0;
      j = 0;
      square[i][j] = x++;
    }
    //else move down
    else {

      i--;
      j = j;
      square[i][j] = x++;
    }
  }
}

void pa1::checkSquare(int **square, int s) {

  int sum;


  cout << "Checking the sums of every row:\t\t";
  //cycle through the rows
  for (int i = 0; i < s; i++) {
    sum = 0;
    //cycle through the columns in each ith row, summing elements as you go
    for (int j = 0; j < s; j++) {
      sum += square[i][j];
    }
    cout << sum;
    if (i != s-1) cout << " ";
  }
  cout << endl;


  cout << "Checking the sums of every column:\t";
  //cycle through the columns
  for (int j = 0; j < s; j++) {
    sum = 0;
    //cycle though the rows in each ith column, summing elements as you go
    for (int i = 0; i < s; i++) {
      sum += square[i][j];
    }
    cout << sum;
    if (j != s-1) cout << " ";
  }
  cout << endl;


  cout << "Checking the sums of every diagonal:\t";
  //bottom left to top right
  sum = 0;
  for (int i = 0, j = 0; i < s; i++, j++) {
    sum += square[i][j];
  }
  cout << sum << " ";

  //top left to bottom right
  sum = 0;
  for (int i = (s-1), j = (s-1); i >= 0; i--, j--) {
    sum += square[i][j];
  }
  cout << sum << endl;
}

void pa1::subtractSquare(int **square, int s) {

  //subtract each ith jth element from s^2+1
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      square[i][j] = s*s+1 - square[i][j];
    }
  }
}

void pa1::swapRows(int **square, int s) {

  int temp[s][s];

  //swap the rows by holding the swapped elements in a temporary array
  for (int i = 0, k = (s-1); i < s; i++, k--) {
    for (int j = 0, m = 0; j < s; j++, m++) {
      temp[i][j] = square[k][m];
    }
  }

  //reassign the values in square to the values that were held in temp
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      square[i][j] = temp[i][j];
    }
  }
}

void pa1::swapColumns(int **square, int s) {

  int temp[s][s];

  //swap the rows by holding the swapped elements in a temporary array
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      temp[i][j] = square[j][i];
    }
  }

  //reassign the values in square to the values that were held in temp
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < s; j++) {
      square[i][j] = temp[i][j];
    }
  }
}

int main() {

  pa1 p;
  int s;
  int **square;

  //get valid size for the magic squares
  s = p.getValidSize();

  //initialize the dynamically allocated square array
  square = new int *[s];
  for (int i = 0; i < s; i++) {
    square[i] = new int[s];
  }

  //create magic square 1 and print
  cout << "Magic Square #1 is:" << endl;
  p.createSquare(square, s);
  p.printSquare(square, s);
  p.checkSquare(square, s);

  //subtract magic square #1 and print
  cout << "Magic Square #2 is:" << endl;
  p.subtractSquare(square, s);
  p.printSquare(square, s);
  p.checkSquare(square, s);

  //swap rows in magic square #2 and print
  cout << "Magic Square #3 is:" << endl;
  p.swapRows(square, s);
  p.printSquare(square, s);
  p.checkSquare(square, s);

  //subtract magic square #3 and print
  cout << "Magic Square #4 is:" << endl;
  p.subtractSquare(square, s);
  p.printSquare(square, s);
  p.checkSquare(square, s);

  //swap columns in magic square #4 and print
  cout << "Magic Square #5 is:" << endl;
  p.swapColumns(square, s);
  p.printSquare(square, s);
  p.checkSquare(square, s);

  //clean up and end program
  for(int i = 0; i < s; i++) {
      delete [] square[i];
  }
  delete [] square;
  square = NULL;
  return 0;
}
