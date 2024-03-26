#include <algorithm>
#include <iostream>
using namespace std;

// A structure to represent a job
struct Job {
    char id;      // Unique identifier for the job
    int deadline; // Deadline by which the job needs to be completed
    int profit;   // Profit gained if the job is completed on or before the deadline
};

// Comparator function for sorting jobs by profit in descending order
bool comparison(Job a, Job b) {
    return (a.profit > b.profit);
}

// Function to find the maximum profit sequence of jobs
void printJobScheduling(Job arr[], int n) {
    // Sort all jobs in descending order of profit
    sort(arr, arr + n, comparison);

    int result[n]; // To store the result (Sequence of jobs)
    bool slot[n];  // To keep track of available time slots

    // Initialize all time slots to be available
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Iterate through all given jobs
    for (int i = 0; i < n; i++) {
        // Find an available time slot for this job
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--) {
            // If the time slot is available, assign this job to it
            if (slot[j] == false) {
                result[j] = i;  // Add this job to the result
                slot[j] = true; // Mark this time slot as occupied
                break;
            }
        }
    }

    // Print the result, i.e., the sequence of jobs for maximum profit
    for (int i = 0; i < n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
}

// Driver's code
int main() {
    // Array of jobs with their deadlines and profits
    Job arr[] = {{'a', 2, 100},
                 {'b', 1, 50},
                 {'c', 3, 70},
                 {'d', 2, 40},
                 {'e', 4, 30},
                 {'f', 1, 20}};

    int n = sizeof(arr) / sizeof(arr[0]); // Number of jobs
    cout << "Max. profit sequence of jobs\n";

    // Find and print the maximum profit sequence of jobs
    printJobScheduling(arr, n);
    return 0;
}
