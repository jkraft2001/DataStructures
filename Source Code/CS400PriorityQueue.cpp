// CS400PriorityQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <string>

//struct Job {
//    std::string name;
//    int priority;
//
//    Job(const std::string& n, int p) : name(n), priority(p) {}
//};

struct Person {
    std::string name;
    int age;

    Person(const std::string& n, int a) :name{ n }, age{ a }{}

};

struct CompareByAge {
    bool operator()(const Person& p1, const Person& p2) {
        return p1.age < p2.age; // sort by age in ascending order
    }
};




// Custom comparison function for sorting jobs based on priority
//struct CompareJobs {
//    bool operator()(const Job& job1, const Job& job2) {
//        // Higher priority jobs have higher priority values
//        return (job1.priority < job2.priority);
//    }
//};

int main() {
    // create a priority queue and push all three person objects into the queue:
    std::priority_queue<Person, std::vector<Person>, CompareByAge> pq;

    pq.push(Person{ "Alice", 25 });
    pq.push(Person{ "Bob", 45 });
    pq.push(Person{ "Rong", 18 });


    while (!pq.empty()) {
        std::cout << pq.top().name << std::endl;
        pq.pop();
    }




    // Create a priority queue of jobs using the custom comparison function
    //std::priority_queue<Job, std::vector<Job>, CompareJobs> jobQueue;
    //
    //// Enqueue jobs with different priorities
    //jobQueue.push(Job{ "Job A", 2 });
    //jobQueue.push(Job{ "Job B", 1 });
    //jobQueue.push(Job{ "Job C", 3 });
    //jobQueue.push(Job{ "Job D", 5 });
    //jobQueue.push(Job{ "Job E", 4 });

    //
    //// Process the jobs based on their priority
    //while (!jobQueue.empty()) {
    //    Job currentJob = jobQueue.top();
    //    jobQueue.pop();

    //    // Process the job (print its name in this example)
    //    std::cout << "Processing job: " << currentJob.name << " Priority: " << currentJob.priority << std::endl;
    //}

    


    return 0;
}
