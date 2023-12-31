/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:53:38 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/12/03 16:07:51 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int main(void)
{
    // Test with int array:
    Array<int> intArray(5);

    for (int i = 0; i < 5; i++) {
        intArray[i] = i * 2;
        std::cout << "Element at index " << i << ": " << intArray[i] << std::endl;
    }
    std::cout << std::endl;

    // Test with char array:
    Array<char> charArray(4);

    for (int i = 0; i < 4; i++) {
        charArray[i] = 'A' + i;
        std::cout << "Element at index " << i << ": " << charArray[i] << std::endl;
    }

    // Test with dynamically allocated int
    int* a = new int();
    *a = 3;

    std::cout << std::endl << "Dynamically allocated int value: " << *a << std::endl;
    Array<int> intArray2(*a);
    for (unsigned int i = 0; i < intArray2.size(); i++) {
        intArray2[i] = i * 2;
        std::cout << "Element at index " << i << ": " << intArray2[i] << std::endl;
    }
    delete a;
    std::cout << std::endl;

    // Test with copy constructor
    Array<int> originalArray(3);
    originalArray[0] = 10;
    originalArray[1] = 20;
    originalArray[2] = 30;

    Array<int> copiedArray(originalArray);

    std::cout << "Original Array:" << std::endl;
    for (std::size_t i = 0; i < originalArray.size(); ++i) {
        std::cout << originalArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copied Array (copy constructor):" << std::endl;
    for (std::size_t i = 0; i < copiedArray.size(); ++i) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // Test with assignment operator
    Array<double> originalArray2(4);
    originalArray2[0] = 1.1;
    originalArray2[1] = 2.2;
    originalArray2[2] = 3.3;
    originalArray2[3] = 4.4;

    Array<double> copiedArray2;

    copiedArray2 = originalArray2;

    std::cout << "Original Array:" << std::endl;
    for (std::size_t i = 0; i < originalArray2.size(); ++i) {
        std::cout << originalArray2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Copied Array (assignment operator):" << std::endl;
    for (std::size_t i = 0; i < copiedArray2.size(); ++i) {
        std::cout << copiedArray2[i] << " ";
    }
    std::cout << std::endl << std::endl;

    originalArray2[1] = 100;
    std::cout << "Modified Original Array:" << std::endl;
    for (std::size_t i = 0; i < originalArray2.size(); i++) {
        std::cout << originalArray2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Unchanged Copied Array:" << std::endl;
    for (std::size_t i = 0; i < copiedArray2.size(); ++i) {
        std::cout << copiedArray2[i] << " ";
    }
    std::cout << std::endl << std::endl;

    // Test with index out of bounds
    try
    {
        std::cout << "Element at index 100: " << charArray[100] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}