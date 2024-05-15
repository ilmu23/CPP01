// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<HumanB.cpp>>

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string &name)
{
	this->name = name;
	this->weapon = nullptr;
}

HumanB::HumanB(const HumanB &copy)
{
	*this = copy;
}

HumanB	&HumanB::operator=(const HumanB &copy)
{
	this->name = copy.name;
	this->weapon = copy.weapon;
	return *this;
}

HumanB::~HumanB(void) {}

void	HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon)
		std::cout << this->name << " attacks with their "
			<< this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with their fists" << std::endl;
}
