/*Alcance BCS32 Problem 1: Mathematical Foundations*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Create a function that  computes the distance between two points 
double get_distance(double x1, double y1, double x2, double y2) {
    // Calculate the formula given : d = √[(x2 - x1)^2 + (y2 - y1)^2]
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Create a function that computes the sum of the first N natural numbers
int calculate_sum(int N) {
    return (N * (N + 1)) / 2; // In order to calculate the sum create a formula that returns the sum
}

int main() {
    int N;

    // Enter the number of delivery points 
    cout << "Number of delivery points: \nEnter Value: ";
    cin >> N;

    // Validate the number of delivery points
    if (N <= 0) {
        cout << "The number of delivery points must be greater than zero.\n Invalid Input!!!\n" ;
        return 1; // Exit if the input is invalid
    }

    // Store the coordinates of the delivery points
    vector<pair<double, double>> dp(N);

    // Enter the coordinates of each delivery point (x and y)
    for (int i = 0; i < N; ++i) {
        cout << "Coordinates for point " << i + 1 << " (x y): \nEnter Value x: ";
        cin >> dp[i].first;
        cout << "Enter Value y: ";
        cin >> dp[i].second;
    }

    // Calculate the total distance
    double total_distance = 0.0;
int i = 1; // initialize the loop 
while (i < N) {
    total_distance += get_distance(dp[i - 1].first, dp[i - 1].second, dp[i].first, dp[i].second);
    ++i; // increment the loop 
}


    // Calculate the sum of the first N natural numbers
    int sum = calculate_sum(N);

    // Output of the results of total disdance an the sum of the first natural numberss
    cout << "\nTotal distance traveled: " << total_distance ;
    cout << "\nSum of the first " << N << " natural numbers: " << sum;

    return 0;
}
