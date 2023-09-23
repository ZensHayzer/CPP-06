/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:05:24 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/23 08:39:05 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc == 2)   {    
        ScalarConverter::convert(argv[1]);
    }
    else
        std::cout << "Wrong number of arguments" << std::endl;
    
    return (0);
}