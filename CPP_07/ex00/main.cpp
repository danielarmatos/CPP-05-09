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

#include "whatever.hpp"

/* int	main(void)
{
    int a = 5, b = 10;
    std::cout << "Before swap: " << a << ", " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: " << a << ", " << b << std::endl;

    int minResult = min(a, b);
    std::cout << "Min value: " << minResult << std::endl;

    int maxResult = max(a, b);
    std::cout << "Max value: " << maxResult << std::endl;

    std::string str1 = "Hello";
    std::string str2 = "World";

    std::cout << "Before swap: " << str1 << ", " << str2 << std::endl;
    swap(str1, str2);
    std::cout << "After swap: " << str1 << ", " << str2 << std::endl;

    std::string minResultS = ::min(str1, str2);
    std::cout << "Min value: " << minResultS << std::endl;

    std::string maxResultS = ::max(str1, str2);
    std::cout << "Max value: " << maxResultS << std::endl;
} */

int main(void)
{
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}

/* We use the two dots :: before calling the template functions to avoid
 * conflicts with the std::min and std::max */