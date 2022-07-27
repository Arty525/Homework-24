#include <iostream>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>

void endTask(std::time_t start, std::time_t end, std::string name) {
	double dif = std::difftime(end, start);
	std::ofstream taskList("C:\\Users\\newar\\Desktop\\list.txt", std::ios::app);
	taskList << name << " start time: " << start << ", end time: " << end << ", spent time: " << dif << std::endl;
	taskList.close();
}

void list() {
	std::ifstream taskList("C:\\Users\\newar\\Desktop\\list.txt");
	std::string task;
	if (taskList.peek() != EOF) {
		std::cout << "Completed tasks: " << std::endl;
	}
	while (std::getline(taskList, task)) {
		std::cout << task << std::endl;
	}
	taskList.close();
}

int main() {
	std::time_t startTime = 0;
	std::time_t endTime;
	std::string command;
	std::string taskName;

	do {
		std::cout << "Enter command: ";
		std::cin >> command;
		if (command == "begin") {
			if (startTime > 0) {
				endTime = std::time(nullptr);
				endTask(startTime, endTime, taskName);
				taskName.clear();
			}
			startTime = std::time(nullptr);
			std::cout << "Enter task name: ";
			std::cin >> taskName;
			std::cout << "Task \"" << taskName << "\" started. Time: " << startTime << std::endl;
		}
		else if (command == "end") {
			endTime = std::time(nullptr);
			endTask(startTime, endTime, taskName);
			taskName.clear();
			startTime = 0;
		}
		else if (command == "status") {
			list();
			if (!taskName.empty()) {
				std::cout << "Current task:" << std::endl;
				std::cout << taskName << " started at " << startTime << std::endl;
			}
		}
		else if (command == "exit") {
			return 0;
		}
		else {
			std::cout << "UNKOWN COMMAND" << std::endl;
		}
	} while (command != "exit");
}