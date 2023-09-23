/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:35:56 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/23 08:58:47 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


int main()  {
    Base    *ptr = Base::generate();

    Base::identify(ptr);
    Base::identify(*ptr);
    
    delete ptr;
    
    return (0);
}