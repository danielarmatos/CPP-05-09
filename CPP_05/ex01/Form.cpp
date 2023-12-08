/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:35:43 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/12/08 19:35:45 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: name("Default"), gradeToSign(0), gradeToExecute(0), signed(false)
{
	std::cout << "Form created" << std::endl;
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute)
		: name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), signed(false)
{
	std::cout << "Form created" << std::endl;
}

Form::Form(const Form& other)
		: name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), signed(other.signed)
{
	std::cout << "Form created (Copy constructor)" << std::endl;
}

Form& Form::operator=(const Form &other)
{
	/* const_cast<std::string&>(this->name) = value.name;
	const_cast<int&>(this->reqGradeSign) = value.reqGradeSign;
	const_cast<int&>(this->reqGradeExec) = value.reqGradeExec; */
	signed = other.signed;
	std::cout << "Form created (Copy assignment)" << std::endl;
	return (*this);
}

Form::~Form() {
}

// -------------------------- //

std::string Form::getName() const {
	return (this->name);
}

bool Form::getSignedValue() const {
	return (this->signed);
}

int Form::getGradeToSign() const {
	return (this->gradeToSign);
}

int	Form::getGradeToExecute() const {
	return (this->gradeToExecute);
}

std::ostream& operator<<(std::ostream& out, Form const& form) {
	out << form.getName() << " Form, Grade to Sign: " << form.getGradeToSign()
		<< ", Grade to Execute: " << form.getGradeToExecute();
	if (form.getSignedValue() == true)
		std::cout << " , is signed" << std::endl;
	else
		std::cout << " , is not signed" << std::endl;
	return (out);
}

const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}
