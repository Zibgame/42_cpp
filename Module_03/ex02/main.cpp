#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    FragTrap f("Blaster");

    f.attack("Enemy");
    f.takeDamage(20);
    f.beRepaired(10);
    f.highFivesGuys();

    return 0;
}
