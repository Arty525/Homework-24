#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>

int main(){
	std::string command;
    std::time_t start = 0;
    std::time_t end;
    std::fstream taskList;
    std::string taskName;

    do {
        std::cout << "Command: ";
        std::cin >> command;
        if (command == "begin") {
            if (start != 0) {
                end = std::time(nullptr);
                std::tm* endLocal = std::localtime(&end);
                double dif = std::difftime((std::time_t)end, (std::time_t)start);
                taskList.open("C://users//newar//Desktop//list.txt", std::ios::app);
                taskList << "end: " << std::put_time(endLocal, "%d.%m.%Y %H:%M:%S") << " time spent: " << (int)dif / 3600 << ":" << (int)dif / 60 << ":" << (int)dif << std::endl;
                std::cout << taskName << " end: " << std::put_time(endLocal, "%d.%m.%Y %H:%M:%S") << " time spent: " << (int)dif / 3600 << ":" << (int)dif / 60 << ":" << (int)dif << std::endl;
                taskList.close();
                start = 0;
            }
            std::cout << "Task name: ";
            std::cin >> taskName;
            start = std::time(nullptr);
            std::tm* startLocal = std::localtime(&start);
            taskList.open("C://users//newar//Desktop//list.txt", std::ios::app);
            taskList << taskName << " start: " << std::put_time(startLocal, "%d.%m.%Y %H:%M:%S") << " ";
            std::cout << taskName << " start: " << std::put_time(startLocal, "%d.%m.%Y %H:%M:%S") << std::endl;
            taskList.close();
        }
        else if (command == "end") {
            end = std::time(nullptr);
            std::tm* endLocal = std::localtime(&end);
            double dif = std::difftime((std::time_t)end, (std::time_t)start);
            taskList.open("C://users//newar//Desktop//list.txt", std::ios::app);
            taskList << "end: " << std::put_time(endLocal, "%d.%m.%Y %H:%M:%S") << " time spent: " << (int)dif/3600 << ":" << (int)dif/60 << ":" << (int)dif << std::endl;
            std::cout << taskName << " end: " << std::put_time(endLocal, "%d.%m.%Y %H:%M:%S") << " time spent: " << (int)dif / 3600 << ":" << (int)dif / 60 << ":" << (int)dif << std::endl;
            taskList.close();
            start = 0;
        }
        else if (command == "status") {
            std::string line;
            taskList.open("C://users//newar//Desktop//list.txt");
            while (!taskList.eof()) {
                std::getline(taskList, line);
                std::cout << line << std::endl;
            }
        }
    } while (command != "exit");
    return 0;
}