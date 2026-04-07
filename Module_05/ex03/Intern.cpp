#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern& other) { (void)other; }
Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}
Intern::~Intern() {}

static AForm* createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string name, const std::string target)
{
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*funcs[3])(std::string) = {
		createShrubbery,
		createRobotomy,
		createPresidential
	};

	int i = 0;
	while (i < 3)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << names[i] << std::endl;
			return funcs[i](target);
		}
		i++;
	}
	std::cout << "Error: form not found" << std::endl;
	return NULL;
}