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

#include "Span.hpp"

int main()
{
    // Test from the subject
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    // Test with Maximum number of elements
    try
    {
        Span sp = Span(2);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test with not enough elements
    try
    {
        Span sp = Span(1);

        sp.addNumber(6);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    // Test with more than 10 000 elements
    try
    {
        Span sp = Span(11000);

        std::vector<int> v(11000);

        std::srand(std::time(0)); // Initializes the random number generator with the current time
        std::generate(v.begin(), v.end(), std::rand); // Fills the vector with random integers
        sp.addNumbers(v.begin(), v.end());

        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}