#include "ScavTrap.hpp"

int main(void)
{

	{
		// 데미지를 받고 1만큼 회복, 다시 데미지를 받아서 attack을 못 하는 경우. (HitPoints 0)
		std::cout << "-------------- case 1 ---------------" << std::endl;

		ScavTrap trap1("trap1");

		std::cout << trap1.getName() << " [HitPoints] : " << trap1.getHitPoints() << std::endl;
		trap1.takeDamage(50);

		std::cout << trap1.getName() << " [HitPoints] : " << trap1.getHitPoints() << std::endl;
		trap1.beRepaired(1);

		std::cout << trap1.getName() << " [HitPoints] : " << trap1.getHitPoints() << std::endl;
		trap1.takeDamage(52);
		std::cout << trap1.getName() << " [HitPoints] : " << trap1.getHitPoints() << std::endl;

		trap1.attack("trap2");
		trap1.guardGate();
	}

	{
		// 50번 공격해서 trap1 이 에너지를 다 잃어서 회복도 못하고 attack 하지 못하는 경우. (EnergyPoints 0)
		std::cout << "-------------- case 2 ---------------" << std::endl;

		ScavTrap trap1("trap1");
		for (int i = 0; i < 50; i++)
		{
			std::cout << "i : " << i << " ";
			trap1.attack("trap2");
			std::cout << trap1.getName() << " [EnergyPoints] : " << trap1.getEnergyPoints() + 1 << " -> " << trap1.getEnergyPoints() << std::endl;
		}
		trap1.beRepaired(1);
		trap1.attack("trap2");
		trap1.guardGate();
	}

	{
		// trap1이 repaired, attack 으로 에너지 포인트를 다 잃는 경우.
		std::cout << "-------------- case 3 ---------------" << std::endl;

		ScavTrap trap1("trap1");
		for (int i = 0; i < 25; i++)
		{
			std::cout << "i : " << i << " ";
			trap1.attack("trap2");
			std::cout << trap1.getName() << " [EnergyPoints] : " << trap1.getEnergyPoints() + 1 << " -> " << trap1.getEnergyPoints() << std::endl;
		}

		for (int i = 0; i < 25; i++)
		{
			std::cout << "i : " << i << " ";
			trap1.beRepaired(1);
			std::cout << trap1.getName() << " [EnergyPoints] : " << trap1.getEnergyPoints() + 1 << " -> " << trap1.getEnergyPoints() << std::endl;
		}

		trap1.attack("trap2");
		trap1.guardGate();
	}
}