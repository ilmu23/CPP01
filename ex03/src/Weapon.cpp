// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Weapon.cpp>>

#include "Weapon.hpp"

Weapon::Weapon(void) {}

Weapon::Weapon(const std::string &type)
{
	this->setType(type);
}

Weapon::Weapon(const Weapon &copy)
{
	*this = copy;
}

Weapon	&Weapon::operator=(const Weapon &copy)
{
	this->setType(copy.type);
	return *this;
}

Weapon::~Weapon(void) {}

std::string const &Weapon::getType(void)
{
	return this->type;
}

void	Weapon::setType(const std::string &type)
{
	this->type = type;
}
