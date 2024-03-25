// CS400QueueApplication02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <string>

// In this example, we demonstrate a job scheduling system using a queue.

// The Job struct represents a job with a name and priority.
struct Job {
    std::string name;
    int priority;

    Job(const std::string& n, int p) : name(n), priority(p) {}
};



// The scheduleJob function takes a reference to the job queue and processes each job in the order they were received.
void scheduleJob(std::queue<Job>& jobQueue) {
    while (!jobQueue.empty()) {
        Job job = jobQueue.front();
        jobQueue.pop();
        // In this simplified example, it only prints the job name and priority. 
        std::cout << "Executing job: " << job.name << " (Priority: " << job.priority << ")" << std::endl;
        // Perform job processing here
    }
}

int main() {
    //std::queue<Job> jobQueue;

    //// Enqueue jobs with different priorities
    //jobQueue.push(Job("Job A", 3));
    //jobQueue.push(Job("Job C", 1));
    //jobQueue.push(Job("Job B", 2));


    //// Schedule and execute jobs in the queue
    //scheduleJob(jobQueue);

    std::priority_queue<int> q;
    q.push(1);
    q.push(7);
    q.push(2);
    q.push(10);

    while (!q.empty()) {
        int number = q.top();
        q.pop();
        std::cout << "numer: " << number << std::endl;
    }

    return 0;
}
