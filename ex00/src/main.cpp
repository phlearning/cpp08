/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:02:03 by pvong             #+#    #+#             */
/*   Updated: 2023/12/08 11:54:30 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

// template <typename T>
// void print(T &container)
// {
//     typename T::iterator it;

//     for (it = container.begin(); it != container.end(); it++)
//         std::cout << *it << " ";
//     std::cout << std::endl;
// }

// template <typename T>
// std::vector<T> &operator<<(std::vector<T> &v, T n)
// {
//     v.push_back(n);
//     return (v);
// }

// template <typename T>
// std::vector<T> &operator,(std::vector<T> &v, T n)
// {
//     v.push_back(n);
//     return (v);
// }

int main(void) {
    std::vector<int> v;
    std::list<int> l;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    try {
        std::cout << *easyfind(v, 3) << std::endl;
        std::cout << *easyfind(l, 3) << std::endl;
        std::cout << *easyfind(v, 5) << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Not found" << std::endl;
    }
    return (0);
}
