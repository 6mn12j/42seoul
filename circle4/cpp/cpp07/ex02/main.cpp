#include <iostream>
#include "Array.hpp"

#define LEN   5
int main() {
  std::cout << "---------- int ----------" << std::endl;
  try {
    Array<int> arrayInt(LEN);
    for (int i = 0; i < LEN; i++)
      arrayInt[i] = i + 1;
    for (int i = 0; i < LEN; i++)
      std::cout << arrayInt[i] << " ";
    std::cout << std::endl;
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "---------- const int ----------" << std::endl;
  try {
 	Array<int> arrayInt(LEN);
	const Array<int> arrayIntCopy(arrayInt);

	for (int i = 0; i < LEN; i++)
    	arrayInt[i] = i + 1;


	for (int i = 0; i < LEN; i++)
      std::cout << arrayInt[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < LEN; i++)
      std::cout << arrayIntCopy[i] << " ";
    std::cout << std::endl;

  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "---------- error: [] ----------" << std::endl;
  try {
    Array<int> arrayInt(LEN);
    for (int i = 0; i < LEN; i++)
      arrayInt[i] = i + 1;
    std::cout << arrayInt[LEN]; // ERROR !
    std::cout << std::endl;
  } catch(std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
