/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:35:43 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/12/08 19:35:45 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: name("Default"), isSigned(false), gradeToSign(0), gradeToExecute(0)
{
	std::cout << "AForm created" << std::endl;
}

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute)
		: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else
		std::cout << this->name << " Form created" << std::endl;
}

AForm::AForm(const AForm& other)
		: name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "AForm created (Copy constructor)" << std::endl;
}

AForm& AForm::operator=(const AForm &other)
{
	/* const_cast<std::string&>(this->name) = value.name;
	const_cast<int&>(this->reqGradeSign) = value.reqGradeSign;
	const_cast<int&>(this->reqGradeExec) = value.reqGradeExec; */
	isSigned = other.isSigned;
	std::cout << "AForm created (Copy assignment)" << std::endl;
	return (*this);
}

AForm::~AForm() {
}

// -------------------------- //

std::string AForm::getName() const {
	return (this->name);
}

bool AForm::getSignedValue() const {
	return (this->isSigned);
}

int AForm::getGradeToSign() const {
	return (this->gradeToSign);
}

int	AForm::getGradeToExecute() const {
	return (this->gradeToExecute);
}

std::ostream& operator<<(std::ostream& out, AForm const& form) {
	out << "Form name: " << form.getName() << "; Grade to Sign: " << form.getGradeToSign()
		<< "; Grade to Execute: " << form.getGradeToExecute();
	if (form.getSignedValue() == true)
		std::cout << "; Is signed" << std::endl;
	else
		std::cout << "; Is not signed" << std::endl;
	return (out);
}

const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;
}

