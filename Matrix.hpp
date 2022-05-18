/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomes <egomes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:08:58 by egomes            #+#    #+#             */
/*   Updated: 2022/05/17 20:08:58 by egomes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
# define MATRIX_HPP

#include <iostream>
#include <vector>
#include <exception>

template <typename T>
class Matrix {
	public:
		typedef std::vector< std::vector<T> > value_type;
		Matrix (size_t lines, size_t colunms) : _rows(lines), _cols(colunms)
		{
			_matrix.resize(lines);
			for (size_t i = 0; i < lines; ++i)
			{
				for (size_t j = 0; j < colunms; ++j)
				{
					_matrix[i].push_back(1);
				}
			}
		}

		Matrix(value_type const &matrix) : _matrix(matrix), _rows(matrix.size()) {
			size_t cols = matrix[0].size();

			for (int i = 1; i < _rows; i++) {
				if (cols != matrix[i].size())
					std::cerr << "Matrix Error!\n";
			}
		}

		virtual ~Matrix() {}

		void insert(size_t x, size_t y, T element) 
		{
			_matrix[x][y] = element;
		}

		const size_t getCols() const { return (_cols);}
		const size_t getRows() const { return (_rows);}
		const size_t getSize() const { return (_rows * _cols);}

		void	incremetRows( size_t n = 1 ) 
		{
			_matrix.resize(_rows + n);
			for (int i = _rows; i < (_rows + n); ++i) 
				for (int j = 0; j < _cols; ++j)
					_matrix[i].push_back(0);
			_rows += n;
		}

		T det() {
			switch (getSize()) {
				case 1:
					return _matrix[0].at(0);
				case 4:
					return (_matrix[0].at(0) * _matrix[1].at(1) + _matrix[0].at(1) * _matrix[1].at(0));
				case 9:
					return _orderThreeDet();
				default:
					return 0;				
			}
			std::cout << "Matrix too big" << std::endl;
		}
		
		Matrix operator+( const Matrix &other)
		{
			if (other._rows != this->_rows || other.cols != this->cols)
				throw std::out_of_range("Matrix Error: Out of range");
	
			Matrix<T> newM(_rows, _cols);
			for (int i = 0; i < _matrix.size(); i++)
					for (int j = 0; j < _matrix[i].size(); j++)
						newM[i][j] = _matrix[i][j] + other._matrix[i][j];
	
			return (newM);
		}

		Matrix operator+=( const Matrix &other)
		{
			if (other._rows != this->_rows || other.cols != this->cols)
				throw std::out_of_range("Matrix Error: Out of range");
			for (int i = 0; i < _matrix.size(); i++)
				for (int j = 0; j < _matrix[i].size(); j++)
					_matrix[i][j] += other._matrix[i][j];
			return (*this);
		}

		Matrix operator-( const Matrix &other)
		{
			if (other._rows != this->_rows || other.cols != this->cols)
				throw std::out_of_range("Matrix Error: Out of range");
	
			Matrix<T> newM(_rows, _cols);
			for (int i = 0; i < _matrix.size(); i++)
				for (int j = 0; j < _matrix[i].size(); j++)
					newM[i][j] = _matrix[i][j] - other._matrix[i][j];
			return (newM);
		}

		Matrix operator-=( const Matrix &other)
		{
			if (other._rows != this->_rows || other.cols != this->cols)
				throw std::out_of_range("Matrix Error: Out of range");

			for (int i = 0; i < _matrix.size(); i++)
				for (int j = 0; j < _matrix[i].size(); j++)
					_matrix[i][j] -= other._matrix[i][j];
		
			return (*this);
		}

		Matrix operator*(const Matrix& other)
		{
			if (other._rows != this->_rows || other.cols != this->cols)
				throw std::out_of_range("Matrix Error: Out of range");
			Matrix<T> newMatrix(_matrix.size(), _matrix.size());
			for (size_t i = 0; i < _matrix.size(); i++) {
				for (size_t j = 0; j < _matrix[i].size(); j++) {
					newMatrix._matrix[i][j] = _linexCol(i,j,_matrix, other._matrix);
				}
			}
			return(newMatrix);
		}

		Matrix operator*=(const Matrix& other)
		{
			Matrix<T> newMatrix = *this;
			if (other._rows != this->_rows || other.cols != this->cols)
				throw std::out_of_range("Matrix Error: Out of range");
			for (size_t i = 0; i < _matrix.size(); i++) {
				for (size_t j = 0; j < _matrix[i].size(); j++) {
					newMatrix._matrix[i][j] = _linexCol(i,j,_matrix, other._matrix);
				}
			}
			*this = newMatrix;
			return *this;
		}

		std::vector<T> &operator[](const int i)
		{
			if (i > _rows)
				throw std::out_of_range("Matrix Error: Out of range");
			return _matrix[i];
		}

		void print() const
		{
			for (int i = 0; i < _rows; ++i)
			{
				for (int j = 0; j < _cols; ++j)
					std::cout << _matrix[i][j] << " ";
				std::cout << "\n";
			}
		}

		private:
			std::vector< std::vector<T> > _matrix;
			size_t _cols;
			size_t _rows;

			T _linexCol(size_t line, size_t col, value_type v1, value_type v2) {
				T element = T();
				size_t i = 0;
				for (size_t j = 0; i < v1.size() and j < v2.size(); j++) {
					element += v1[line][j] * v2[i][col];
					i++;
				}
				return(element);
			}

		T _primaryDiagonal() {
			T det = T();
			det += _matrix[0].at(0) * _matrix[1].at(1) * _matrix[2].at(2);
			det += _matrix[0].at(1) * _matrix[1].at(2) * _matrix[2].at(0);
			det += _matrix[0].at(2) * _matrix[1].at(0) * _matrix[2].at(2);
			return det;
		}

		T _secondaryDiagonal() {
			T det = T();
			det += _matrix[0].at(1) * _matrix[1].at(0) * _matrix[2].at(2);
			det += _matrix[0].at(0) * _matrix[1].at(2) * _matrix[2].at(1);
			det += _matrix[0].at(2) * _matrix[1].at(1) * _matrix[2].at(0);
			return det;
		}

		T _orderThreeDet()
		{ return (_primaryDiagonal() - _secondaryDiagonal()); }

};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T> &mat)
{
	mat.print();
	return os;
}

#endif
