#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <dos.h>

int main() {
	std::time_t a = std::time(nullptr);
	std::tm* b = std::localtime(&a);
		
	std::cout << "Enter time: ";
	std::cin >> std::get_time(b, "%M:%S");
	std::cout << std::put_time(b, "%M:%S") << std::endl;

	for (int i = (std::time_t)b; i != 1; --i) {
		std::cout << std::put_time(b, "%M:%S") << std::endl;
		if (!b->tm_sec && b->tm_min > 0) {
			b->tm_sec = 60;
			b->tm_min -= 1;
		}
		else if (!b->tm_sec && !b->tm_min) {
			std::cout << "DING! DING! DING!" << std::endl;
			break;
		}
		b->tm_sec -= 1;
		_sleep(1000);
	}

	return 0;
}