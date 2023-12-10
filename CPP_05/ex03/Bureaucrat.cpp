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

void Bureaucrat::incrementGrade() {
	if (this->grade > 1) {
		this->grade -= 1;
		std::cout	<< this->name << " had the grade increased: " << this->grade
					<< std::endl;
	}
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	if (this->grade < 150)
	{
		this->grade += 1;
		std::cout	<< this->name << " had the grade decreased: " << this->grade
					<< std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
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

// -------------------------- //

void Bureaucrat::signForm(AForm& form) {
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->name << " couldn’t sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
    try
    {
        form.execute(*this);
        if (!form.getSignedValue())
        {
            std::cout << this->name << " couldn’t execute " << form.getName()
                      << " because form is not signed\n";
            return;
        }
        std::cout << this->name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << this->name << " couldn’t execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}
