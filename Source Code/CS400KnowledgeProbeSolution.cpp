// CS400KnowledgeProbeSolution.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
class Q2 {
private:
    std::string firstName;
    std::string lastName;
    int score;
public:
    Q2() = default;
    Q2(std::string fn, std::string ln, int s) :firstName{ fn }, lastName{ ln }, score{ s }{}


    std::string getFirstName() const {
        return firstName;
    }
    std::string getLastName() const {
        return lastName;
    }

    int getScore() const {
        return score;
    }
    void setFisrtName(const std::string fn) {
        firstName = fn;
    }
    void setlastname(const std::string ln) {
        lastName = ln;
    }
    void setScore(int s) {
        score = s;
    }

};


double q3(int numbers[], int size) {
    int tempMax = numbers[0];
    for (int i = 1; i < size; i++) {
        if (numbers[i] > tempMax) {
            tempMax = numbers[i];
        }
    }
    std::cout << "The max value of this array: " << tempMax << std::endl;

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += numbers[i];
    }
    return (sum / size);
}


double q3(std::vector<int> vi) {
    int tempMax = vi.at(0);
    for (int i = 0; i < vi.size(); i++) {
        if (vi.at(i) > tempMax) {
            tempMax = vi.at(i);
        }
    }
    std::cout << "The max value of this array: " << tempMax << std::endl;

    double sum = 0.0;
    for (int i = 0; i < vi.size(); i++) {
        sum += vi[i];
    }
    return sum / vi.size();
}




double q3_avd(int numbers[], int size) {
    std::cout << *std::max_element(numbers, numbers + size) << std::endl;

    return std::accumulate(numbers, numbers + size, 0.0) / size;
}








template <typename T>
T addTwo(T first, T second) {
    return (first + second);
}





int main()
{

    //int numbers[]{ 10, 23, 30, 44 };




    int numbers[]{ 10, 23, 30, 44 };
    //std::cout << *std::max_element(numbers, numbers + std::size(numbers) )<< std::endl;
    double average = q3_avd(numbers, std::size(numbers));
    std::cout << "The average value of this array: " << average << std::endl;









    return 0;
}

