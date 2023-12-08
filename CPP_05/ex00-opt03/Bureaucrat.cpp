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

Bureaucrat::Bureaucrat() : name("Default"), grade(1) {
	std::cout << "Bureaucrat created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	: name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		this->grade = grade;
		std::cout	<< "Bureaucrat " << name << " with grade " << grade
					 << " created " << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	: name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat created (Copy constructor)" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	grade = other.grade;

	/*	const_cast<std::string&>(name) = other.name;

	If name is intended to be constant, there is no need to modify it.
	Using const_cast in this context assumes that modifying name in the
	copy assignment operator is a valid and desired behavior. */

	std::cout << "Bureaucrat created (Copy assignment)" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

// -------------------------- //

std::string Bureaucrat::getName() const {
	return (this->name);
}

int Bureaucrat::getGrade() const {
	return (this->grade);
}

/* Using exceptions for normal control flow (such as incrementing or
 * decrementing a grade) can be considered an anti-pattern in C++.
 * Exceptions are typically reserved for exceptional conditions, errors,
 * or situations where normal control flow cannot proceed. In this case,
 * it might be more appropriate to use conditional checks instead of
 * relying on exceptions for control flow. */

void Bureaucrat::incrementGrade() {
	try
	{
		if (this->grade > 1) {
			this->grade -= 1;
			std::cout	<< this->name << " had the grade increased: " << this->grade
						 << std::endl;
		}
		else
			throw GradeTooHighException();
	}
	catch (GradeTooHighException &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

void Bureaucrat::decrementGrade() {
	try
	{
		if (this->grade < 150)
		{
			this->grade += 1;
			std::cout	<< this->name << " had the grade decreased: " << this->grade
						 << std::endl;
		}
		else
			throw GradeTooLowException();
	}
	catch (GradeTooLowException &e)
	{
		std::cout << RED << "Exception caught: " << e.what() << RESET << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade "
		<< bureaucrat.getGrade() << std::endl;
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}
