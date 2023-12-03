/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:54:57 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/12/03 15:54:58 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Default"), grade(0) {
	std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	std::cout	<< "Bureaucrat " << name << " with grade " << grade
				<< " created " << std::endl;
	try {
		if (grade < 1)
			throw (grade);
	//	else if (grade > 150)
	}
	catch (int grade) {
		std::cout << "Grade exception! " << grade << std::endl;
	}

}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	*this = other;
	std::cout << "Bureaucrat created (Copy constructor)" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
	//	name = other.name;
	}
	std::cout << "Bureaucrat created (Copy assignment)" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destroyed" << std::endl;
}

// -------------------------- //