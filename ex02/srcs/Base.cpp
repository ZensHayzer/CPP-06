/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:21:52 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/23 09:13:32 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <A.hpp>
#include <B.hpp>
#include <C.hpp>

Base::~Base()   {
    
}

Base    *Base::generate(void)   {
    int     rnd;

    srand(time(NULL));
    rnd = rand() % 3 + 1;
    
    if (rnd == 1)
        return (new A());
    else if (rnd == 2)
        return (new B());
    else if (rnd == 3)
        return (new C());
    
    return (NULL);
}

void    Base::identify(Base *p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type is A." << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type is B." << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type is C." << std::endl;
}

void    Base::identify(Base &p) {
    try {
        p = dynamic_cast<A &>(p);
        std::cout << "Type is A." << std::endl;
    }
    catch (const std::exception &e) {}

    try {
        p = dynamic_cast<B &>(p);
        std::cout << "Type is B." << std::endl;
    }
    catch (const std::exception &e) {}

    try {
        p = dynamic_cast<C &>(p);
        std::cout << "Type is C." << std::endl;
    }
    catch (const std::exception &e) {}
}