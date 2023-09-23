/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:49:10 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/23 06:57:46 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()    {
    
}

Serializer::Serializer(Serializer const & src)  {
    if (this != &src)
        *this = src;
}

Serializer::~Serializer()   {
    
}

Serializer  &Serializer::operator=(Serializer const & src)  {
    (void)src;
    return (*this);
}

uintptr_t   Serializer::serialize(Data  *dataPtr)   {
    return reinterpret_cast<uintptr_t>(dataPtr);
}

Data    *Serializer::deserialize(uintptr_t uPtr) {
    return  reinterpret_cast<Data *>(uPtr);
}