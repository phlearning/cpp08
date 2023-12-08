/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:02:03 by pvong             #+#    #+#             */
/*   Updated: 2023/12/08 15:13:40 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* -------------------------------------------------------------------------- */
/*                               CANONICAL FORM                               */
/* -------------------------------------------------------------------------- */

Span::Span(void) : _size(0) {
    if (SHOWMSG)
        std::cout << COLOR("Default constructor called.", GREEN) << std::endl;
    return;
}

Span::Span(Span const &src) {
    if (SHOWMSG)
        std::cout << COLOR("Copy constructor called.", GREEN) << std::endl;
    *this = src;
    return;
}

Span::~Span(void) {
    if (SHOWMSG)
        std::cout << COLOR("Destructor called.", RED) << std::endl;
    return;
}

Span &Span::operator=(Span const &rhs) {
    if (SHOWMSG)
        std::cout << COLOR("Assignation operator called.", GREEN) << std::endl;
    if (this != &rhs)
        this->_size = rhs._size;
    return *this;
}

/* ----------------------------- MY CONSTRUCTOR ----------------------------- */

Span::Span(unsigned int N) : _size(N) {
    if (SHOWMSG)
        std::cout << COLOR("Constructor called: ", GREEN) << "size set to " << this->_size << std::endl;
    return;
}

/* -------------------------------------------------------------------------- */
/*                              MEMBER FUNCTIONS                              */
/* -------------------------------------------------------------------------- */

void Span::addNumber(int n) {
    if (this->_container.size() < this->_size)
        this->_container.push_back(n);
    else
        throw std::length_error("Span is full.");
    return;
}


/**
 * Calculates the shortest span between any two elements in the container.
 * 
 * @return The shortest span between any two elements.
 * @throws std::length_error if the container has less than 2 elements.
 */
int Span::shortestSpan(void) {
    if (this->_container.size() < 2)
        throw std::length_error("Span is too short.");
    std::vector<int> v = this->_container;
    std::sort(v.begin(), v.end());
    int min = v[1] - v[0];
    for (std::vector<int>::iterator it = v.begin(); it != v.end() - 1; it++)
        if (*(it + 1) - *it < min)
            min = *(it + 1) - *it;
    return min;
}


/**
 * Calculates the longest span between any two elements in the container.
 * Throws std::length_error if the container size is less than 2.
 * 
 * @return The longest span between any two elements.
 */
int Span::longestSpan(void) {
    if (this->_container.size() < 2)
        throw std::length_error("Span is too short.");
    std::vector<int> v = this->_container;
    std::sort(v.begin(), v.end());
    return v[v.size() - 1] - v[0];
}

void Span::addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2) {
    if (this->_container.size() + std::distance(it1, it2) > this->_size)
        throw std::length_error("Span is full.");
    this->_container.insert(this->_container.end(), it1, it2);
    return;
}

/* ------------------------------ GET FUNCTIONS ------------------------------ */

unsigned int Span::getSize(void) const {
    return this->_size;
}

std::vector<int> Span::getContainer(void) const {
    return this->_container;
}

/* ---------------------- OVERLOADING OSTREAM OPERATOR ---------------------- */

std::ostream &operator<<(std::ostream &o, Span const &rhs) {
    o << "Span size: " << rhs.getSize() << std::endl;
    o << "Span container: ";
    std::vector<int> v = rhs.getContainer();
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        o << *it << " ";
    o << std::endl;
    return o;
}
