/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:35:48 by dreis-ma          #+#    #+#             */
/*   Updated: 2023/12/08 19:35:50 by dreis-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	AForm();
	AForm(const AForm &other);
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	AForm &operator=(const AForm &other);
	~AForm();

	std::string getName() const;
	bool getSignedValue() const;
	int getGradeToSign() const;
	int	getGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const& executor) const = 0;

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, AForm const& form);

#endif