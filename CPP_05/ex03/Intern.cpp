#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern created" << std::endl;
}

Intern::Intern(const Intern&)
{
    std::cout << "Intern created (Copy constructor)" << std::endl;
}

Intern& Intern::operator=(const Intern &)
{
    std::cout << "Intern created (Copy assignment)" << std::endl;
    return (*this);
}

Intern::~Intern() {
}

// -------------------------- //

static AForm* presidentialPardonForm(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}

static AForm* robotomyRequestForm(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}

static AForm* shrubberyCreationForm(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}

// -------------------------- //

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string formNames[] = {
            "ShrubberyCreationForm",
            "RobotomyRequestForm",
            "PresidentialPardonForm"
    };
    FormFunction formFunctions[] = {
            &shrubberyCreationForm,
            &robotomyRequestForm,
            &presidentialPardonForm
    };

    for (int j = 0; j < 3; j++)
    {
        if (name == formNames[j])
        {
            AForm* form = formFunctions[j](target);
            std::cout << "Intern creates " << name << std::endl;
            return (form);
        }
    }
    std::cout << "Error: " << name << " is an invalid form name" << std::endl;
    return (NULL);
}