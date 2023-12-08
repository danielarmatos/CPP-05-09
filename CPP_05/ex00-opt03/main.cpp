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
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		std::cout << "Usage: " << argv[0] << " <name> <grade>" << std::endl;
		return (1);
	}
	try
	{
		Bureaucrat b(argv[1], atoi(argv[2]));
		std::cout << b;
		b.decrementGrade();
		b.incrementGrade();
		b.decrementGrade();
		b.decrementGrade();
		std::cout << b;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
		std::cerr << "Exception 01: " << e.what() << std::endl;
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cerr << "Exception 02: " << e.what() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Unknown exception: " << e.what() << std::endl;
	}
}