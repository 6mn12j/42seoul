#include "ClapTrap.hpp"

int main(void)
{
	{
		// 10번 공격해서 trap1 이 에너지를 다 잃음.
		std::cout << "-------------- case 1 ---------------" << std::endl;
		ClapTrap trap1("trap1");

		for (int i = 0; i < 10; i++)
		{
			std::cout << "i : " << i << " ";
			trap1.attack("trap2");
		}
		trap1.attack("trap2");
	}

	{
		// 기본 HP인 10 만큼 공격 받아서 HitPoints가 0이됨.
		std::cout << "-------------- case 2 ---------------" << std::endl;

		ClapTrap trap1("trap1");

		std::cout << trap1.getName() << " [HitPoints] : " << trap1.getHitPoints() << std::endl;
		trap1.takeDamage(5);

		std::cout << trap1.getName() << " [HitPoints] : " << trap1.getHitPoints() << std::endl;
		trap1.beRepaired(1);

		std::cout << trap1.getName() << " [HitPoints] : " << trap1.getHitPoints() << std::endl;
		trap1.takeDamage(5);

		trap1.attack("trap2");
	}

	{
		// 10번 공격해서 trap1 이 에너지를 다 잃고 1만큼 회복 못함.
		std::cout << "-------------- case 3 ---------------" << std::endl;

		ClapTrap trap1("trap1");
		for (int i = 0; i < 10; i++)
		{
			std::cout << "i : " << i << " ";
			trap1.attack("trap2");
			std::cout << trap1.getName() << " [EnergyPoints] : " << trap1.getEnergyPoints() + 1 << " -> " << trap1.getEnergyPoints() << std::endl;
		}
		trap1.beRepaired(1);
		trap1.attack("trap2");
	}

	{
		// 9번 공격해서 trap1 이 에너지를 다 잃고 1만큼 회복 함.
		std::cout << "-------------- case 3 ---------------" << std::endl;

		ClapTrap trap1("trap1");
		for (int i = 0; i < 9; i++)
		{
			std::cout << "i : " << i << " ";
			trap1.attack("trap2");
			std::cout << trap1.getName() << " [EnergyPoints] : " << trap1.getEnergyPoints() + 1 << " -> " << trap1.getEnergyPoints() << std::endl;
		}
		trap1.beRepaired(1);
		trap1.attack("trap2");
	}
}