#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap s("Guardian");

    s.attack("Enemy");
    s.guardGate();

    return 0;
}
