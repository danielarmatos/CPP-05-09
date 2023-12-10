#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
        : AForm("PresidentialPardonForm", 25, 5), target("Default")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
        : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
        : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), target(other.target)
{
    std::cout << "PresidentialPardonForm created (Copy constructor)" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

// -------------------------- //

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (this->getSignedValue())
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    else
        std::cout << "Could not execute the Presidential Pardon Form." << std::endl;

}