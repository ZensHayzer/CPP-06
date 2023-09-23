/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanne <ajeanne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 06:43:12 by ajeanne           #+#    #+#             */
/*   Updated: 2023/09/23 06:41:22 by ajeanne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()  {
    
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)  {
    if (this != &src)
        *this = src;
}

ScalarConverter::~ScalarConverter() {
    
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const & src)    {
    (void)src;
    return (*this);
}

void    ScalarConverter::convert(std::string entry) {
    if (!isPLiterals(entry) && nbLetters(entry) <= 1)  {
        if (nbComas(entry) > 1) {
            std::cout << "char type : impossible" << std::endl;
            std::cout << "int type : impossible" << std::endl;
            std::cout << "float type : impossible" << std::endl;
            std::cout << "double type : impossible" << std::endl;
        }
        else if (nbComas(entry) == 0)   {
            if (isChar(entry)) {}
            else if(isInt(entry))   {}
        }
        else if (nbComas(entry) == 1 ) {
            if (isFloat(entry))    {}
            else if (isDouble(entry))    {}
        }
        else
            std::cout << "Wrong input" << std::endl;
    }
    else
        std::cout << "Wrong input" << std::endl;
}

bool    ScalarConverter::isChar(std::string const & entry)  {
    std::istringstream iss(entry);
    float   tmp;

    if (!((iss >> tmp) && (iss.eof())) && entry.size() == 1)    {
        std::cout << "| Entry is a char |" << std::endl;
        char c;
        std::istringstream oss(entry);
        oss >> c;
        std::cout << "char type : " << c << std::endl;
		std::cout << "int type : " << static_cast<int>(c) << std::endl;
		std::cout << "float type : " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double type : " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
    }
    
    return (false);
}

bool    ScalarConverter::isInt(std::string const & entry)   {
    std::istringstream  iss(entry);
    int forInt;
    
    if ((iss >> forInt) && (iss.eof()))  {
        std::cout << "| Entry is an int |" << std::endl;
        if (static_cast<int>(forInt) >= 32 && static_cast<int>(forInt) <= 126)
            std::cout << "char type : " << static_cast<char>(forInt) << std::endl;
        else if ((static_cast<int>(forInt) >= 0 && static_cast<int>(forInt) <= 31) || static_cast<int>(forInt) == 127)
            std::cout << "char type : non displayable" << std::endl;
        else
            std::cout << "char type : impossible" << std::endl;
        std::cout << "int type : " << forInt << std::endl;
		std::cout << "float type : " << std::fixed << std::setprecision(1) << static_cast<float>(forInt) << "f" << std::endl;
		std::cout << "double type : " << std::fixed << std::setprecision(1) << static_cast<double>(forInt) << std::endl; 
        return (true);
    }
    else if ((forInt >= INT_MAX || forInt <= INT_MIN) && entry.find(".") == std::string::npos)
        return (std::cout << "Overflow" << std::endl, true);
    
    return (false);
}

bool ScalarConverter::isFloat(std::string const & entry)    {
    std::string reduced = entry;
    int i = 0;

    if (reduced.substr(reduced.size() - 1) == "f" && reduced.substr(0, reduced.size() - 2).find(".") != std::string::npos)  {
        reduced = entry.substr(0, entry.size() - 1);
        i = reduced.substr(reduced.find(".")).size() > 6 ? 6 : reduced.substr(reduced.find(".")).size() - 1;
    }
    else
        return (false);
    
    std::istringstream  iss(entry);
    float   f;
    
    if (!((iss >> f) && (iss.eof())))   {
        std::cout << "| Entry is a float |" << std::endl;
        if (static_cast<int>(f) >= 32 && static_cast<int>(f) <= 126)
            std::cout << "char type : " << static_cast<char>(f) << std::endl;
        else if ((static_cast<int>(f) >= 0 && static_cast<int>(f) <= 31) || static_cast<int>(f) == 127)
            std::cout << "char type : non displayable" << std::endl;
        else
            std::cout << "char type : impossible" << std::endl;
        if (static_cast<int>(f) >= INT_MAX || static_cast<int>(f) <= INT_MIN)
            std::cout << "int type : impossible" << std::endl;
        else
            std::cout << "int type : " << static_cast<int>(f) << std::endl;
        std::cout << "float type : " << std::fixed << std::setprecision(i) << f << "f" << std::endl;
		std::cout << "double type : " << std::fixed << std::setprecision(i) << static_cast<double>(f) << std::endl;
        return (true);
    }
    else if ((f <= FLT_MIN || f >= FLT_MAX) && entry.find_first_not_of("0123456789.") == std::string::npos)
        return (std::cout << "overflow" << std::endl, true);
    
    return (false);
}

bool    ScalarConverter::isDouble(std::string const & entry)  {
    int i = 0;
    
    if (entry.find(".") == std::string::npos)
        return (false);
    else
        i = entry.substr(entry.find(".")).size() > 6 ? 6 : entry.substr(entry.find(".")).size() - 1;
    
    std::istringstream   iss(entry);
    double  d;
    
    if ((iss >> d) && (iss.eof()))  {
        std::cout << "| Entry is a double |" << std::endl;
        if (static_cast<int>(d) >= 32 && static_cast<int>(d) <= 126)
            std::cout << "char type : " << static_cast<char>(d) << std::endl;
        else if ((static_cast<int>(d) >= 0 && static_cast<int>(d) <= 31) || static_cast<int>(d) == 127)
            std::cout << "char type : non displayable" << std::endl;
        else
            std::cout << "char type : impossible" << std::endl;
        if (static_cast<int>(d) >= INT_MAX || static_cast<int>(d) <= INT_MIN)
            std::cout << "int type : impossible" << std::endl;
        else
            std::cout << "int type : " << static_cast<int>(d) << std::endl;
        if (static_cast<float>(d) <= -FLT_MAX || static_cast<float>(d) >= FLT_MAX)
            std::cout << "float type : impossible" << std::endl;
        else
            std::cout << "float type : " << std::fixed << std::setprecision(i) << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double type : " << std::fixed << std::setprecision(i) << d << std::endl;
        return (true);
    }
    else if ((d >= DBL_MAX || d <= DBL_MIN) && entry.find_first_not_of("0123456789.") == std::string::npos)
        return (std::cout << "overflow" << std::endl, true);
    return (false);
}

int ScalarConverter::nbComas(std::string const & entry) {
    int count = 0;
    
    for (int i = 0; i < (int)entry.size(); i++)  {
        if (entry[i] == '.')
            count++;
    }
    return (count);
}

bool    ScalarConverter::isPLiterals(std::string const & entry) {
    if (entry == "nan" || entry == "+inf" || entry == "-inf")   {
        std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << entry << "f" << std::endl;
		std::cout << "double : " << entry << std::endl;
		return (true);
    }
    else if (entry == "nanf" || entry == "+inff" || entry == "-inff")   {
        std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : " << entry << std::endl;
		std::cout << "double : " << entry.substr(0, entry.size() - 1) << std::endl;
		return (true);
    }

    return (false);
}

int  ScalarConverter::nbLetters(std::string const & entry)  {
    int cnt = 0;
    
    for (int i = 0; i < (int)entry.size(); i++)  {
        if (isalpha(entry[i]))
            cnt++;
    }
    
    return (cnt);
}