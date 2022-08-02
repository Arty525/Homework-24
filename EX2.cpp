#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>

struct friends {
	std::string name;
	std::time_t a = std::time(nullptr);
	std::tm b = *std::localtime(&a);
};

struct near {
	std::string name;
	std::time_t a = std::time(nullptr);
	std::tm b = *std::localtime(&a);
};

int main() {
	std::vector<friends> f;
	std::vector<near> nearBd;
	std::time_t today = std::time(nullptr);
	std::tm* local = std::localtime(&today);
	std::string command;
	for (int i = 0; command != "end"; ++i) {
		std::cout << "input: " << std::endl;
		std::cin >> command;
		if (command != "end") {
			f.push_back(friends());
			f[i].name = command;
			std::cin >> std::get_time(&f[i].b, "%d.%m.%Y");
			if (f[i].b.tm_mon > local->tm_mon || (f[i].b.tm_mon == local->tm_mon && f[i].b.tm_mday >= local->tm_mday)) {
				if (!nearBd.size()) {
					nearBd.push_back(near());
					nearBd[0].name = f[i].name;
					nearBd[0].b = f[i].b;
				}
				else {
					if (f[i].b.tm_mon == nearBd[0].b.tm_mon && f[i].b.tm_mday == nearBd[0].b.tm_mday) {
						nearBd.push_back(near());
						nearBd[nearBd.size() - 1].name = f[i].name;
						nearBd[nearBd.size() - 1].b = f[i].b;
					}
					else if (f[i].b.tm_mon < nearBd[0].b.tm_mon || (f[i].b.tm_mon == nearBd[0].b.tm_mon && f[i].b.tm_mday <= nearBd[0].b.tm_mday)) {
						nearBd.resize(1);
						nearBd[0].name = f[i].name;
						nearBd[0].b = f[i].b;
					}
				}
			}
		}
		else if (command == "end") {
			if (!nearBd.size()) {
				std::cout << "All birthdays are over." << std::endl;
			}
			else {
				for (int j = 0; j < nearBd.size(); ++j) {
					std::cout << nearBd[j].name << " " << std::put_time(&nearBd[j].b, "%d.%m") << std::endl;
				}
				if (nearBd[0].b.tm_mon == local->tm_mon && nearBd[0].b.tm_mday == local->tm_mday) {
					std::cout << "Don't forget congratulate today!" << std::endl;
				}
			}
		}
	}

	return 0;
}
/*
A 01.08.1999
B 15.08.2000
C 15.08.1996
D 16.08.2001
E 01.09.1973
*/
