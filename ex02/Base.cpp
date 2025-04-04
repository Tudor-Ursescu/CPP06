/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:43:39 by tursescu          #+#    #+#             */
/*   Updated: 2025/04/04 19:24:04 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void) {
     // we seed the random number generator(once, generationg true randomness)
     static bool seeded = false;
     if (!seeded) {
        srand(time(NULL));
        seeded = true;
     }
     int random = rand() % 3; // generate a number in between 0-2
     switch (random) {
        case 0:
            std::cout << BLUE << "Generated class A" << RESET << std::endl;
            return new A();
        case 1:
            std::cout << YELLOW << "Generated class B" << RESET << std::endl;
            return new B();
        case 2:
            std::cout << PINK << "Generated class C" << RESET << std::endl;
            return new C();
        default:
            return NULL;
     }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << BLUE << "A" << RESET << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << YELLOW << "B" << RESET << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << PINK << "C" << RESET << std::endl;
    else
        std::cout << RED << "Unknown type" << RESET << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;  // To avoid unused variable warning
        std::cout << BLUE << "A" << RESET << std::endl;
        return;
    } catch (...) {}
    
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << YELLOW << "B" << RESET << std::endl;
        return;
    } catch (...) {}
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << PINK << "C" << RESET << std::endl;
        return;
    } catch (...) {}
    
    std::cout << RED << "Unknown type" << RESET << std::endl;
}