/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 06:43:59 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/23 06:57:53 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    int nb;
};

class   Serializer  {
    public:
        Serializer();
        Serializer(Serializer const & src);
        ~Serializer();
        
        Serializer  &operator=(Serializer const & src);

        static uintptr_t    serialize(Data *dataPtr);
        static Data         *deserialize(uintptr_t uPtr);
};

#endif