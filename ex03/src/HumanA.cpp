// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<HumanA.cpp>>

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon): weapon(weapon)
{
	this->name = name;
}

HumanA::HumanA(const HumanA &copy): weapon(copy.weapon)
{
	*this = copy;
}

HumanA	&HumanA::operator=(const HumanA &copy)
{
	this->name = copy.name;
	this->weapon = copy.weapon;
	return *this;
}

HumanA::~HumanA(void) {}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their "
		<< this->weapon.getType() << std::endl;
}
