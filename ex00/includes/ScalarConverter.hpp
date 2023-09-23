/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 06:25:46 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/23 05:49:29 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <sstream>
#include <iomanip>
#include <string>

class ScalarConverter    {
    
    public:
        ScalarConverter();
        ScalarConverter(ScalarConverter const & src);
        ~ScalarConverter();
        
        ScalarConverter       &operator=(ScalarConverter const & src);
        static void           convert(std::string entry);
        static bool           isPLiterals(std::string const & entry);
        static bool           isChar(std::string const & entry);
        static bool           isInt(std::string const & entry);
        static bool           isFloat(std::string const & entry);
        static bool           isDouble(std::string const & entry);
        static int            nbComas(std::string const & entry);
        static int            nbLetters(std::string const & entry);
};

#endif