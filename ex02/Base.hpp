/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:33:34 by tursescu          #+#    #+#             */
/*   Updated: 2025/04/04 18:56:12 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <iomanip>
# include <cmath>
# include <sstream>
# include <string>
# include <limits.h>
# include <limits>
# include <stdint.h>

# define RED "\033[31m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define PINK "\033[38;5;205m"
# define TEAL "\033[38;5;30m"
# define LAVENDER "\033[38;5;183m"
# define CYAN "\033[38;5;51m"
# define LIGHT_YELLOW "\033[38;5;229m"
# define RESET "\033[0m"

class Base
{
public:
    virtual ~Base(){};    
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);

#endif