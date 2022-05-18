#include <iostream>
#include "Matrix.hpp"

int     main() {
    Matrix<int> m(10,10);


    // std::vector<int>* d;
    // // std::vector<int>* e;
    // // std::vector<int>* error;

    m.insert(5,5, 5);
   m.print();

   m[5];

   // std::cout << m[2] << std::endl;
    //d = a + b;
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
