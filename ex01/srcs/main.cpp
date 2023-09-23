/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:56:14 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/23 08:38:58 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()  {
    Data        *structPtr = new Data;
    uintptr_t   uPtr = 0;
    Data        *deserialized;

    std::cout << "Value uPtr before serialize : " << std::endl;
    std::cout << uPtr << std::endl;

    structPtr->nb = 1;
    uPtr = Serializer().serialize(structPtr);
    deserialized = Serializer().deserialize(uPtr);
    
    std::cout << "\nValue nb in struct : " << std::endl;
    std::cout << structPtr->nb << std::endl;
    std::cout << "\nValue uPtr after serialize : " << std::endl;
    std::cout << uPtr << std::endl;
    std::cout << "\nValue nb after deserialize : " << std::endl;
    std::cout << deserialized->nb << std::endl;
    std::cout << "\nDiff structPtr == deserialized : " << std::endl;
    std::cout << (deserialized == structPtr) << std::endl;

    delete structPtr;

    return (0);
}