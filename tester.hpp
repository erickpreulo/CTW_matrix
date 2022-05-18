#ifndef TESTER_HPP
#define TESTER_HPP

#include <iostream>
#include "Matrix.hpp"
#include <exception>

template < typename T >
class err_tester : std::exception
{
    private:
        Matrix<T> _mtxA(10,10);
        Matrix<T> _mtxB(10,10);
    public:

        tester()
        {
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