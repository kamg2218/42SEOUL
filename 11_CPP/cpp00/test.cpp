//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>

int		main(int argc, char *argv[])
{
	int age;
	std::cout << "나이를 입력하세요." << std::endl;
	std::cin >> age;

	char job[10];
	std::cout << "직업을 입력하세요." << std::endl;
	std::cin >> job;

	std::string name;
	std::cout << "이름을 입력하세요." << std::endl;
	std::cin >> name;

	std::cout << "당신의 이름은 " << name << "이고, "
		<< "나이는 " << age << "살이고, "
		<< "직업은 " << job << "입니다." << std::endl;
	return (0);
}
