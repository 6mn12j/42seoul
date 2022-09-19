#include "Convert.hpp"

int main(int argc,char *argv[])
{
	if (argc != 2)
	{
		std::cout << "인자가 부족 합니다." << std::endl;
		return (0);
	}

	Convert convert(static_cast<std::string>(argv[1]));
	convert.printAll();
}