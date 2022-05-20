#include <iostream>
#include "Matrix.hpp"

int     main() {
    Matrix<double> m(6,10);
    //Matrix<int> m1(6,10);
   // Matrix<int> mcpy(0, 1);


    // std::vector<int>* d;
    // // std::vector<int>* e;
    // // std::vector<int>* error;


    m.insert(5,5, 5);
   // m1 + m;
   try
   {
        m[20][19] = 9;
   }
   catch (std::exception &e)
   {
       std::cout << e.what() << std::endl;
   }
    //std::cout << m;

    // m1[5][5] = 2;
    // mcpy = m + m1;
    
    m.incremetRows(5);

    std::cout << m << std::endl;

    // e = a * b;
    // error = a + c;
   // m.insert(*d);
    // m.insert(*e);
    // m.insert(*error);


    // delete d;
    // delete e;
    // delete error;
    return (0);
}
