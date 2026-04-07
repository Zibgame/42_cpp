/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 17:02:35 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/07 17:02:37 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data data;

    data.id = 42;
    data.name = "zib";

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original: " << &data << std::endl;
    std::cout << "Serialized: " << raw << std::endl;
    std::cout << "Deserialized: " << ptr << std::endl;

    if (ptr == &data)
        std::cout << "OK: same pointer" << std::endl;
    else
        std::cout << "Error" << std::endl;

    return 0;
}
