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
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
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
		Bureaucrat bureaucrat(argv[1], atoi(argv[2]));

        ShrubberyCreationForm sForm("Target");
        bureaucrat.signForm(sForm);
        bureaucrat.executeForm(sForm);
        std::cout << std::endl;

        RobotomyRequestForm rForm("Target");
        bureaucrat.signForm(rForm);
        bureaucrat.executeForm(rForm);
        std::cout << std::endl;

        PresidentialPardonForm pForm("Target");
        bureaucrat.signForm(pForm);
        bureaucrat.executeForm(pForm);
    }
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}