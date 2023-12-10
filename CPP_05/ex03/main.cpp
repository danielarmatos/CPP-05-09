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
#include "Intern.hpp"

int	main(void)
{
	try
	{
        Intern intern;
        AForm* rrf = intern.makeForm("robotomy request", "Bender");
        delete(rrf);
        std::cout << std::endl;

        AForm* form01 = intern.makeForm("ShrubberyCreationForm", "Target");
        std::cout << *form01 << std::endl;
        AForm* form02 = intern.makeForm("RobotomyRequestForm", "Target");
        std::cout << *form02 << std::endl;
        AForm* form03 = intern.makeForm("PresidentialPardonForm", "Target");
        std::cout << *form03;

        delete form01;
        delete form02;
        delete form03;
    }
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}