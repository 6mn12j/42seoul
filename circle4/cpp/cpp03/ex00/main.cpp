#include "ClapTrap.hpp"

int main(void)
{
	{
		// 10번 공격해서 trap1 이 에너지를 다 잃는 경우.
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
		// 데미지를 받고 1만큼 회복, 다시 데미지를 받아서 attack을 못하는 경우.
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
		// 10번 공격해서 trap1 이 에너지를 다 잃고 1만큼 회복 못하고 attack 하지 못하는 경우.
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
		// 9번 공격해서 trap1 이 에너지를 에너지를 잃고 1만큼 회복 한 후엔 에너지가 없어서 attack 하지 못하는 경우.
		std::cout << "-------------- case 4 ---------------" << std::endl;

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