#ifndef PA1
#define PA1

#include <iostream>
using namespace std;

class pa1 {

  public:
    void printSquare(int **square, int s);
    int getValidSize();
    void createSquare(int **square, int s);
    void checkSquare(int **square, int s);
    void swapRows(int **square, int s);
    void swapColumns(int **square, int s);
    void subtractSquare(int **square, int s);
};

#endif
