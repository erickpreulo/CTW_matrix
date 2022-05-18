#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include "Matrix.hpp"

template < typename T >
class tester
{
    private:
        Matrix<T> _mtxA;
        Matrix<T> _mtxB;
    public:

        tester()
        {
            for (auto i = 1; i < 10; ++i)
            {
                _mtxA.insert(i);
                _mxtB.insert(i);
            }
        }


        void print(const Matrix<T> &matrix)
        {
            for (int i = 0; i < 10; ++i)
            {
                for (int j = 0; i < 10; ++j)
                    std::cout << matrix[i][j];

            }
        }

        void TestPlusOperator()
        {
            Matrix<T> temp;

            temp = _mtxA + _mtxB;

            print(temp);


        }

        void TestMinusOperator()
        {

        }


        ~tester();
};

tester::tester(/* args */)
{
}

tester::~tester()
{
}





#endif