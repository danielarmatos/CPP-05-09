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

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
    // Test with a Vector
    std::vector<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);
    myVector.push_back(40);
    myVector.push_back(50);

    try {
        std::vector<int>::iterator result = easyfind(myVector, 30);
        std::cout << "Value found in vector at position: " << std::distance(myVector.begin(), result) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator result = easyfind(myVector, 60);
        std::cout << "Value found in vector at position: " << std::distance(myVector.begin(), result) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test with a List
    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);
    myList.push_back(50);

    try {
        std::list<int>::iterator result = easyfind(myList, 30);
        std::cout << "Value found in list at position: " << std::distance(myList.begin(), result) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        std::list<int>::iterator result = easyfind(myList, 60);
        std::cout << "Value found in list at position: " << std::distance(myList.begin(), result) << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}