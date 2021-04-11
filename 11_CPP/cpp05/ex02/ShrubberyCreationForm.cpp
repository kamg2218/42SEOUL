#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: Form(target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &sbcf) { *this = sbcf; }

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
	std::cout << "drawing tree..." << std::endl;
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
