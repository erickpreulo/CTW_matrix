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

template <typename T>
class Matrix {
	private:
		std::vector< std::vector<T> > _matrix;
	public:
		Matrix (size_t lines, size_t colunms)
		{
			_matrix.resize(lines);
			for (size_t i = 0; i < lines; ++i)
			{
				for (size_t j = 0; j < colunms; ++j)
				{
					_matrix[i].push_back(0);
				}
			}
		}

		~Matrix() {}

		void insert(size_t x, size_t y, T element) 
		{
			_matrix[x][y] = element;
		}


		// T &operator[](int i)
		// {
		// 	return _matrix[i];
		// }

		void print()
		{
			for (int i = 0; i < 10; ++i)
			{
				for (int j = 0; j < 10; ++j)
					std::cout << _matrix[i][j];
				std::cout << "\n";
			}
		}

};

#endif
