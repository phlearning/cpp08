/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:56:42 by pvong             #+#    #+#             */
/*   Updated: 2023/12/08 15:13:37 by pvong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stdexcept>

#ifndef SHOWMSG
#define SHOWMSG 1
#endif /* SHOWMSG */

#ifndef MYCOLORS
#define MYCOLORS
#define RESET "\033[0m"
#define BLACK "\033[30m"              /* Black */
#define RED "\033[31m"                /* Red */
#define GREEN "\033[32m"              /* Green */
#define YELLOW "\033[33m"             /* Yellow */
#define BLUE "\033[34m"               /* Blue */
#define MAGENTA "\033[35m"            /* Magenta */
#define CYAN "\033[36m"               /* Cyan */
#define WHITE "\033[37m"              /* White */
#define BOLDBLACK "\033[1m\033[30m"   /* Bold Black */
#define BOLDRED "\033[1m\033[31m"     /* Bold Red */
#define BOLDGREEN "\033[1m\033[32m"   /* Bold Green */
#define BOLDYELLOW "\033[1m\033[33m"  /* Bold Yellow */
#define BOLDBLUE "\033[1m\033[34m"    /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m" /* Bold Magenta */
#define BOLDCYAN "\033[1m\033[36m"    /* Bold Cyan */
#define BOLDWHITE "\033[1m\033[37m"   /* Bold White */

#define MSG_SEP "============================"
#define MSG_SEP2 "============="
#define COLOR(text, color) color << text << RESET
#define MY_SEP() std::cout << COLOR(MSG_SEP, BOLDBLACK) << std::endl
#define MY_SEP2(msg) std::cout << COLOR(MSG_SEP2, BOLDWHITE) << " " << msg << " " << COLOR(MSG_SEP2, BOLDWHITE) << std::endl

#endif /* MYCOLORS */

class Span {
    public:
        // Canonical Form
        Span(void);
        Span(Span const &src);
        ~Span(void);
        Span &operator=(Span const &rhs);
        
        // My constructor
        Span(unsigned int N);

        // Member functions
        void addNumber(int n);
        void addNumber(std::vector<int>::iterator it1, std::vector<int>::iterator it2);
        int shortestSpan(void);
        int longestSpan(void);
        unsigned int getSize(void) const;
        std::vector<int> getContainer(void) const;

    private:
        unsigned int _size;
        std::vector<int> _container;
};

std::ostream &operator<<(std::ostream &o, Span const &rhs);

#endif /* SPAN_HPP */