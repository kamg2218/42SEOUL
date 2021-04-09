#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form(target, 145, 137)
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &sbcf)
{
	this->_sign = sbcf._sign;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::action() const
{
	std::ofstream	ofs;

	ofs.open(_name + "_shrubbery", std::ofstream::out);
	if (!ofs.is_open())
	{
		std::cout << "Error: Unable to open file" << std::endl;
		return ;
	}
	ofs << "                 __/\\__" << std::endl;
	ofs << "                 \\ ** /" << std::endl;
	ofs << "                 /_**_\\" << std::endl;
	ofs << "                 / \\/ \\" << std::endl;
	ofs << "               // ^  $ \\\\" << std::endl;
	ofs << "             /____________\\" << std::endl;
	ofs << "            //  *  %    \\\\^" << std::endl;
	ofs << "          ^/ /  @   +  #  \\ \\"<< std::endl;
	ofs << "         /__/______________\\__\\^" << std::endl;
	ofs << "        * /  /   +        \\  \\ *" << std::endl;
	ofs << "       /%  /$ M E R R Y * \\ # \\" << std::endl;
	ofs << "     ^/____/____o___________\\____\\" << std::endl;
	ofs << "     * /  ^/            @  \\    \\ *" << std::endl;
	ofs << "     / %  /C H R I S T M A S\\   # \\" << std::endl;
	ofs << "  o/^    /o          #   %   \\o    ^\\" << std::endl;
	ofs << "/_____/_______________________\\______\\" << std::endl;
	ofs << "*   o   *    o   | * |  o   *    o   *" << std::endl;
	ofs << "                 |   |" << std::endl;
	ofs << "                 |___|" << std::endl;
	ofs.close();
}
/*
void	ShrubberyCreationForm::check(Bureaucrat const &executor) const
{
	if (this->_sign == false)
		throw Form::IsNotSigned();
	else if (executor.getGrade() > this->_exec_grade)
		throw Form::GradeTooLowException();
}
*/
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try{
		check(executor);
		action();
	}
	catch (std::exception& ex){
		std::cout << executor.getName() << " can not execute this form, ";
		std::cout << "because " << ex.what();
	}
}
