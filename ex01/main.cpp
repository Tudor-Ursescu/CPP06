/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main .cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:10:21 by tursescu          #+#    #+#             */
/*   Updated: 2025/04/04 18:20:24 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data base;
    base.val = 42;
    base.text = "Hello";
    base.GDP = 120.1;
    base.c = 'a';

    std::cout << TEAL << "Base address: " << &base << RESET << std::endl;
   
    uintptr_t result = Serializer::serialize(&base);
    std::cout << PINK << "Serialize result: " << result << RESET << std::endl;

    Data* rebase = Serializer::deserialize(result);
    std::cout << TEAL << "Deserialize result: " << rebase << RESET << std::endl;
    
    if (rebase == &base) {
        std::cout << YELLOW << "SUCCESS: Pointers match!" << RESET << std::endl;
        std::cout << LIGHT_YELLOW << rebase->val << std::endl;
        std::cout << rebase->text << std::endl;
        std::cout << rebase->GDP << std::endl;
        std::cout << rebase->c << RESET << std::endl;
    } else {
        std::cout << RED << "ERROR: Pointers don't match!" << RESET << std::endl;
    }
    return 0;
}