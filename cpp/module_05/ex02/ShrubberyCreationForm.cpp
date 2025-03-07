#include "ShrubberyCreationForm.hpp"
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
	:AForm("Shrubbery", 145, 137), target(target) {
	std::cout << this->getName() <<	 " Constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm)
	:AForm(shrubberyCreationForm), target(shrubberyCreationForm.getTarget()) {
	std::cout << this->getName() <<	 " copy Constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << this->getName() <<	 " Destructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shrubberyCreationForm) {
	if (this == &shrubberyCreationForm)
		return (*this);
	this->target = shrubberyCreationForm.getTarget();
	this->AForm::operator=(shrubberyCreationForm);
	std::cout <<  " copy Constructor called\n";
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return (this->target);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const  {
	this->validateExecutable(executor);
	std::ofstream File;
	std::string tmp = target + "_shrubbery";
	File.open(tmp.c_str());
	
	std::string ascii ="                      - - - \n\
                   -        -  -     --    - \n\
                -                 -         -  - \n\
                                - \n\
                               -                -- \n\
               -          -            -              - \n\
               -            \'-,        -               - \n\
               -              \'b      * \n\
                -              \'$    #-                --  \n\
               -    -           $:   #:               - \n\
             --      -  --      *#  @):        -   - - \n\
                          -     :@,@):   ,-**:\'   - \n\
              -      -,         :@@*: --**\'      -   - \n\
                       \'#o-    -:(@\'-@*\"\'  - \n\
               -  -       \'bq,--:,@@*\'   ,*      -  - \n\
                          ,p$q8,:@)\'  -p*\'      - \n\
                   -     \'  - \'@@Pp@@*\'    -  - \n\
                    -  - --    Y7\'.\'     -  - \n\
                              :@):. \n\
                             .:@:\'. \n\
                           .::(@:.    ";


	if (!File.is_open()) {
		throw std::exception();
	}
	File << ascii;
	File.close();
}