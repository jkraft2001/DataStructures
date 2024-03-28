/***************************************************************
 * A program to use a queue to simulate the queue of customers *
 * in a bank and find the corresponding statistics 		 	 *
 ***************************************************************/
#include <queue>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <utility>
#include<iostream>

struct Customer {
	int arriveDelay;
	int serveTime;

	Customer(int arriveDelay, int serveTime) : arriveDelay{ arriveDelay }, serveTime{ serveTime }{}
};



 // Definition of a randNum function
int randNum(int low, int high)
{
	int temp = rand();
	int num = temp % (high - low + 1) + low;
	return num;
}






int main()
{
	// Declaration of variables
	int size = 15;
	int arriveDelay;
	int serveTime;
	int arrive = 0;
	int start = 0;
	int leave = 0;
	int wait = 0;
	int totalServeTime = 0;
	int totalWait = 0;

	// Instantiation of a queue object called line
	//std::queue <std::pair <int, int > > line;
	std::queue<Customer> line;

	// Simulation of customer arrivals and push the information into queue
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		//std::pair < int, int> p(randNum(1, 6), randNum(5, 10));
		Customer p{ randNum(1, 6), randNum(5, 10) };
		line.push(p);
	}
	// Printing the header for statistical data
	std::cout << std::left << std::setw(10) << "Arrive" << std::setw(10) << "Start";
	std::cout << std::left << std:: setw(10) << "Wait" << std::setw(10) << "Leave";
	std::cout << std::left << std::setw(10) << "Serve time" << std::endl;

	// Calculation and printing statistics
	while (line.size() > 0)
	{
		//arriveDelay = line.front().first;
		arriveDelay = line.front().arriveDelay;
		//serveTime = line.front().second;
		serveTime = line.front().serveTime;

		arrive = arrive + arriveDelay;
		if (arrive >= leave)
		{
			start = arrive;
		}
		else
		{
			start = leave;
		}
		//leave = start + line.front().second;
		leave = start + line.front().serveTime;
		wait = start - arrive;
		std::cout << std::left << std::setw(10) << arrive << std::setw(10) << start;
		std::cout << std::left << std::setw(10) << wait;
		std::cout << std::setw(10) << leave;
		std::cout << std::left << std::setw(12) << serveTime << std::endl;

		totalServeTime += serveTime;
		totalWait += wait;
		line.pop();
	}
	// Printing the summary 
	double averageWait = static_cast <double> (totalWait) / size;
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "Total serve time: " << totalServeTime << std::endl;
	std::cout << "Average Wait: " << averageWait << std::endl;
	return 0;
}


