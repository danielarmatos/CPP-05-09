#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
        : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
        : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
        : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()), target(other.target)
{
    std::cout << "ShrubberyCreationForm created (Copy constructor)" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

// -------------------------- //

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (this->getSignedValue())
    {
        std::ofstream sFile((this->target + "_shrubbery").c_str());
        sFile << "              * *    \n"
                 "           *    *  *\n"
                 "      *  *    *     *  *\n"
                 "     *     *    *  *    *\n"
                 " * *   *    *    *    *   *\n"
                 " *     *  *    * * .#  *   *\n"
                 " *   *     * #.  .# *   *\n"
                 "  *     \"#.  #: #\" * *    *\n"
                 " *   * * \"#. ##\"       *\n"
                 "   *       \"###\n"
                 "             \"##\n"
                 "              ##.\n"
                 "              .##:\n"
                 "              :###\n"
                 "              ;###\n"
                 "            ,####.\n"
                 "/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\";
        sFile.close();
    }

    else
        std::cout << "Could not execute the Shrubbery Creation Form." << std::endl;

}