/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:51:43 by pvong             #+#    #+#             */
/*   Updated: 2023/12/08 14:36:32 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {
    if (SHOWMSG)
        std::cout << COLOR("MutantStack default constructor called", GREEN) << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &src) : std::stack<T>(src) {
    if (SHOWMSG)
        std::cout << COLOR("MutantStack copy constructor called", GREEN) << std::endl;
}

template <typename T>
MutantStack<T>::~MutantStack() {
    if (SHOWMSG)
        std::cout << COLOR("MutantStack destructor called", RED) << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &src) {
    if (SHOWMSG)
        std::cout << COLOR("MutantStack assignation operator called", GREEN) << std::endl;
    if (this != &src)
        std::stack<T>::operator=(src);
    return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
    return this->c.end();
}



#endif // MUTANTSTACK_TPP