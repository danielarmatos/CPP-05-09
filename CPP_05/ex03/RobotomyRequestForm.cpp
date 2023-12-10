#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
        : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
        : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
        : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), target(other.target)
{
    std::cout << "RobotomyRequestForm created (Copy constructor)" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

// -------------------------- //

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->getGradeToExecute())
    {
        std::cout << "The Robotomy Request Form failed." << std::endl;
        throw AForm::GradeTooLowException();
    }

    else if (this->getSignedValue())
        std::cout << "* drilling noises * " << this->target << " has been robotomized successfully 50% of the time." << std::endl;
    else
        std::cout << "The Robotomy Request Form failed." << std::endl;
}