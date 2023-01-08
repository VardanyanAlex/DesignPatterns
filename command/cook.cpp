
#include "cook.h"

#include <iostream>
#include <chrono>
#include <thread>

void CCook::MakeBBQ()
{
	std::cout << "Making your BBQ, please wait some seconds\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	std::cout << "\tHere it is, you can take it\n";
}

void CCook::MakeFish()
{
	std::cout << "Making your fish, please wait some seconds\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));

	std::cout << "\tHere it is, you can take it\n";
}

void CCook::MakeDessert()
{
	std::cout << "Making your dessert, please wait some seconds\n\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	std::cout << "\tHere it is, you can take it\n";
}
