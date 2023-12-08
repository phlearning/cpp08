/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:14:09 by pvong             #+#    #+#             */
/*   Updated: 2023/12/08 15:26:58 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

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

void print_separator(int len, char c, std::string str, std::string color) {
    int str_len = str.length();
    int left_len = (len - str_len) / 2;
    int right_len = len - str_len - left_len;
    std::cout << color << std::string(left_len, c) << ' ' << str << ' ' << std::string(right_len, c) << RESET << std::endl;
}

void print_vector(std::vector<int> v) {
    std::cout << COLOR("Vector: ", BOLDWHITE);
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
        std::cout << *it << ' ';
    std::cout << std::endl;
}

int main(void) {
    try {
        print_separator(100, '=', "SUBJECT TEST", BOLDBLACK);
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        // std::vector<int> numbersToAdd;
        // numbersToAdd << 7, 4, 20, 10, 11; // Don't forget to uncomment the template above
        // sp.addNumber(numbersToAdd.begin(), numbersToAdd.end());

        print_vector(sp.getContainer());
        std::cout << COLOR("Shortest span: ", BOLDWHITE) << sp.shortestSpan() << std::endl;
        std::cout << COLOR("Longest span: ", BOLDWHITE) << sp.longestSpan() << std::endl; 
    } catch (std::exception &e) {
        std::cout << COLOR("Error: ", RED) << e.what() << std::endl;
}
    }