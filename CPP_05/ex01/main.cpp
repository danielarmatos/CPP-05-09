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

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <name> <grade to sign> <grade to execute>" << std::endl;
		return (1);
	}
	try
	{
		Bureaucrat b(argv[1], atoi(argv[2]));
		std::cout << b;
		b.decrementGrade();
		b.incrementGrade();

		std::cout << std::endl << std::endl;
		Bureaucrat c = b;
		std::cout << c;
		Bureaucrat d("DANI", 5);
		std::cout << d;
		d = b;
		std::cout << d;
		std::cout << std::endl << std::endl;

		Form f("Form01", atoi(argv[2]), atoi(argv[3]));
		std::cout << f;
		f.beSigned(b);
		std::cout << f;
		std::cout << std::endl << std::endl;

		Form g("Form02", 5, 5);
		b.signForm(g);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}