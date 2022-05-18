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
		int _height;
		int _whidth;
		std::vector< std::vector<T> > _matrix;
	public:
		Matrix() {}
		Matrix( size_t a, size_t b ) : _height(a), _whidth(b) {}
		~Matrix() {}

		void	insert( std::vector<T> element ) {
			_matrix.push_back(element);
		}

		int		getSize() const {
			return(_matrix.size());
		}

		void print()
		{
			for ( auto row : _matrix)
			{
				for (auto cols : row)
				{
					std::cout << cols << " ";
				}
				std::cout << "\n";
			}
		}

};

template <typename T>
std::vector<T>*	operator+( std::vector<T> a, std::vector<T> b ) {
	std::vector<T> *cpy = new std::vector<T>();

	if (a.size() != b.size()) {
		std::cout << "Cant some diferent vectors!" << std::endl;
		return (cpy);
	}

	for (int i = 0; i < a.size(); i++)
		cpy->push_back(a[i] + b[i]);
	return (cpy);
}

template <typename T>
std::vector<T>*	operator*( std::vector<T> a, std::vector<T> b ) {
	std::vector<T> *cpy = new std::vector<T>();

	if (a.size() != b.size()) {
		std::cout << "Cant multiply diferent vectors!" << std::endl;
		return (cpy);
	}

	for (int i = 0; i < a.size(); i++)
		cpy->push_back(a[i] * b[i]);
	return (cpy);
}

#endif
