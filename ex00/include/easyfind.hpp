/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:57:20 by pvong             #+#    #+#             */
/*   Updated: 2023/12/08 11:55:06 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::exception();
    return (it);
}

/* Version sans std::find */
// template <typename T>
// typename T::iterator easyfind(T &container, int n)
// {
//     typename T::iterator it;

//     for (it = container.begin(); it != container.end(); it++)
//         if (*it == n)
//             return (it);
//     if (it == container.end())
//         throw std::exception();
//     return (it);
// }

#endif /* EASYFIND_HPP */