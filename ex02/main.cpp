/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:15:39 by tursescu          #+#    #+#             */
/*   Updated: 2025/04/04 19:18:33 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
    std::cout << CYAN << "Creating random object." << RESET << std:: endl;
    Base* randomObj = generate();
    std::cout << TEAL << "Identifing by pointer: " << RESET;
    identify(randomObj);
    std::cout << LAVENDER << "Identifing by reference: " << RESET;
    identify(*randomObj);

    delete randomObj;
    return 0;
} 