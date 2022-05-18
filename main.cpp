#include <iostream>
#include "Matrix.hpp"

int     main() {
    Matrix<int> m;

    std::vector<int> a(2, 4);
    std::vector<int> b(2, 7);
    std::vector<int> c(1, 3);
    std::vector<int>* d;
    // std::vector<int>* e;
    // std::vector<int>* error;
    m.insert(a);
    m.insert(b);
    m.insert(c);

    d = a + b;
    // e = a * b;
    // error = a + c;
    m.insert(*d);
    // m.insert(*e);
    // m.insert(*error);
    m.print();

    // delete d;
    // delete e;
    // delete error;
    return (0);
}
