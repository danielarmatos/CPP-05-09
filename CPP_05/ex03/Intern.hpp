#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    const std::string target;

public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    AForm* makeForm(const std::string& name, const std::string& target);
    typedef AForm* (*FormFunction)(const std::string&);

    /* This creates a type alias named FormFunction. It represents a pointer to a function that takes a
     * const std::string& parameter and returns a pointer to an object of type AForm.*/
};