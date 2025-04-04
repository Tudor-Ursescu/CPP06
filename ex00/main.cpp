/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:28:48 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/31 16:23:49 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << RED << "Usage : ./convert <literal>" << RESET << std::endl;
        return 1;
    }
    else {
        std::string input = av[1];

        ScalarConverter::convert(input);
        return (0);
    }
}
