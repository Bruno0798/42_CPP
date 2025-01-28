#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", reqSign, execSign, "Default")
{
	std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("Shrubbery", reqSign, execSign, target)
{
	std::cout << "Data Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
	std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Assignment Operator Called" << std::endl;
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::executor() const
{
	std::ofstream file((this->getTarget() + "_shrubbery").c_str());

	if(file.fail())
	{
		std::cout << "Failed opening file" << std::endl;
		return ;
	}
	else
	{
		file << "              _{\\ _{\\{\\/}/}/}__" << std::endl;
		file << "             {/{/\\}{/{/\\}(\\}{/\\} _" << std::endl;
		file << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _" << std::endl;
		file << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}" << std::endl;
		file << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << std::endl;
		file << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}" << std::endl;
		file << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}" << std::endl;
		file << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}" << std::endl;
		file << "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}" << std::endl;
		file << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}" << std::endl;
		file << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)" << std::endl;
		file << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}" << std::endl;
		file << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}" << std::endl;
		file << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}" << std::endl;
		file << "          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)" << std::endl;
		file << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}" << std::endl;
		file << "             {/{\\{\\{\\/}/}{\\{\\\\}/}" << std::endl;
		file << "              {){/ {\\/}{\\/} \\}\\}" << std::endl;
		file << "              (_)  \\.-'.-/" << std::endl;
		file << "          __...--- |'-.-'| --...__" << std::endl;
		file << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__" << std::endl;
		file << " -\"    ' .  . '    |.'-._| '  . .  '   jro" << std::endl;
		file << " .  '-  '    .--'  | '-.'|    .  '  . '" << std::endl;
		file << "          ' ..     |'-_.-|" << std::endl;
		file << "  .  '  .       _.-|-._ -|-._  .  '  ." << std::endl;
		file << "              .'   |'- .-|   '." << std::endl;
		file << "  ..-'   ' .  '.   `-._.-�   .'  '  - ." << std::endl;
		file << "   .-' '        '-._______.-'     '  ." <<std::endl;
		file << "        .      ~," << std::endl;
		file << "    .       .   |\\   .    ' '-." << std::endl;
		file << "    ___________/  \\____________" << std::endl;
		file << "   /  Why is it, when you want \\" << std::endl;
		file << "  |  something, it is so damn   |" << std::endl;
		file << "  |    much work to get it?     |" << std::endl;
		file << "   \\___________________________/" << std::endl;
		file << std::endl;
		file.close();
		std::cout << "File " << this->getTarget() << "_shrubbery created!" << std::endl;
	}
}


