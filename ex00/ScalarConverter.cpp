/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:28:52 by tursescu          #+#    #+#             */
/*   Updated: 2025/04/04 17:24:25 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string& x) {
    return (x.length() == 1 && !std::isdigit(x[0]));
}

static bool isInt(const std::string& x) {
    if (x.empty())
        return false;
    size_t i = 0;
    if (x[0] == '+' || x[0] == '-')
        i = 1;
    if (i == x.length())
        return false;
    for (; i < x.length(); i++) {
        if (!std::isdigit(x[i]))
            return false;
    }
    long val;
    try {
        val = atol(x.c_str());
        if (val > INT_MAX || val < INT_MIN)
            return false;
    }
    catch (...) {
        return false;
    }
    return true;
}

static bool isFloat(const std::string& x) {
    //special cases
    if (x == "nanf" || x == "+inff" || x == "-inff")
    return true;
    //not empty and ending with f
    if (x.empty() || x[x.length() - 1] != 'f')
    return false;
    std::string temp = x.substr(0, x.length() - 1); //remove the f
    
    bool hasDecimal = false;
    size_t i = 0;
    if (temp[0] == '+' || temp[0] == '-')
        i = 1;
    //if empty after sign
    if (i == temp.length())
        return false;
    for (; i < temp.length(); i++) {
        // make sure you have only one decimal point
        if (temp[i] == '.') {
            if (hasDecimal)
                return false;
            else
                hasDecimal = true;
            
        }else if (!std::isdigit(temp[i]))
            return false;
    }
    std::istringstream iss(temp);
    float value;
    iss >> value;
    return (!iss.fail() && iss.eof());
}

static bool isDouble(const std::string& x) {
    if (x == "nan" || x == "+inf" || x == "-inf")
        return true;
    bool hasDecimal = false;
    size_t i = 0;
    if (x[0] == '+' || x[0] == '-')
        i = 1;
    if (i == x.length())
        return false;
    for (; i < x.length(); i++) {
        if (x[i] == '.') {
            if (hasDecimal)
                return false;
            else
                hasDecimal = true;
        } else if (!std::isdigit(x[i]))
            return false;
    }
    std::istringstream iss(x);
    double value;
    iss >> value;
    return (!iss.fail() && iss.eof());
}

void ScalarConverter::convert(const std::string& x) {
    ScalarConverter::Type type = INVALID;
    if (isChar(x))
        type = ScalarConverter::CHAR;
    else if (isInt(x))
        type = ScalarConverter::INT;
    else if (isFloat(x))
        type = ScalarConverter::FLOAT;
    else if (isDouble(x))
        type = ScalarConverter::DOUBLE;
    
    if (type == INVALID) {
        std::cout << RED << "Invalid input type" << RESET << std::endl;
        return;
    }
    
    char c;
    int i;
    float f;
    double d;

    try {
        switch(type) {
            case ScalarConverter::CHAR:
                c = x[0];
                i = static_cast<int>(c);
                f = static_cast<float>(c);
                d = static_cast<double>(c);
                break;
            case ScalarConverter::INT:
                i = atoi(x.c_str());
                c = static_cast<char>(i);
                f = static_cast<float>(i);
                d = static_cast<double>(i);
                break;
            case ScalarConverter::FLOAT:
                if (x == "nanf" || x == "+inff" || x == "-inff") {
                    f = (x == "nanf") ? std::numeric_limits<float>::quiet_NaN() :
                        (x == "+inff") ? std::numeric_limits<float>::infinity() : -std::numeric_limits<float>::infinity();
                    d = static_cast<float>(f);
                    c = 0;
                    i = 0;    
                } else {
                    std::string temp = x.substr(0, x.length() - 1);
                    f = static_cast<float>(atof(temp.c_str()));
                    c = static_cast<char>(f);
                    i = static_cast<int>(f);
                    d = static_cast<double>(f);
                }
                break;
            case ScalarConverter::DOUBLE:
                if (x == "nan" || x == "+inf" || x == "-inf") {
                    d = (x == "nan") ? std::numeric_limits<double>::quiet_NaN() :
                        (x == "+inf") ? std::numeric_limits<double>::infinity() : -std::numeric_limits<double>::infinity();
                    f = static_cast<float>(d);
                    c = 0;
                    i = 0;
                } else {
                    d = atof(x.c_str());
                    c = static_cast<char>(d);
                    i = static_cast<int>(d);
                    f = static_cast<float>(d);
                }
                break;
            default:
                break;
        }
    } catch (std::exception &e) {
        std::cout << RED << "Exception during conversion: " << e.what() << std::endl;
        return;
    }

    //Character
    std::cout << YELLOW << "char: " << RESET;
    if (std::isnan(d) || std::isinf(d) || i < 0 || i > 127)
        std::cout << RED << "impossible" << RESET;
    else if (std::isprint(c)) // else if (i >= 32 && i <= 126)
        std::cout << YELLOW << '\'' << c << '\'' << RESET;
    else
        std::cout << RED << "Non displayable";
    std::cout << std::endl;

    //Integer
    std::cout << BLUE << "int: " << RESET;
    if (std::isnan(d) || std::isinf(d) || d > INT_MAX || d < INT_MIN)
        std::cout << RED << "impossible" << RESET;
    else
        std::cout << BLUE << i << RESET;
    std::cout << std::endl;

    //Float
    std::cout << PINK << "float: " << RESET;
    if (std::isnan(f))
        std::cout << PINK << "nanf" << RESET;
    else if (std::isinf(f) && f > 0)
        std::cout << PINK << "+inf" << RESET;
    else if (std::isinf(f))
        std::cout << PINK << "-inf" << RESET;
    else {
        std::cout << PINK << f;
        if (f == static_cast<int>(f))
            std::cout << ".0";
        std::cout << "f" << RESET;
    }
    std::cout << std::endl;

    //Double
    std::cout << CYAN << "double: " << RESET;
    if (std::isnan(d))
        std::cout << CYAN << "nan" << RESET;
    else if (std::isinf(d) && d > 0)
        std::cout << CYAN << "+inf" << RESET;
    else if (std::isinf(d))
        std::cout << CYAN << "-inf" << RESET;
    else {
        std::cout << CYAN << d << RESET;
        if (d == static_cast<int>(d))
            std::cout << CYAN << ".0" << RESET;
        }
    std::cout << std::endl;
}