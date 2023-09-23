/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 08:15:22 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/23 09:12:59 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <stdlib.h>
#include <time.h>

class Base  {
    public:
        virtual ~Base();
    
        static Base    *generate(void);
        static void    identify(Base* p);
        static void    identify(Base& p);
};

#endif