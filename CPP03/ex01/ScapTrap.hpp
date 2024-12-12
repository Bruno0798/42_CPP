#ifndef SCAPTRAP_HPP
#define SCAPTRAP_HPP

#include "ClapTrap.hpp"

class ScapTrap : public ClapTrap
{
public:
	ScapTrap();
	ScapTrap(const std::string& name);
	ScapTrap(const ScapTrap& obj);
	~ScapTrap();
	void guardGate();

};

#endif SCAPTRAP_HPP
