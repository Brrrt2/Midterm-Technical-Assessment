#include <iostream>

using namespace std;

// The tower of hanoi logic is performed by a recursive function.
void hanoi(int packages, char from_peg, char to_peg, char temp_peg, int& counter) {
    //When there is only one package to move, handle the base case.
    if (packages == 1) {
        cout << "Transfer package 1 from: \n " << from_peg << " to " << to_peg << endl;
        ++counter;  
        return;
    }

    // Move the top n-1 packages to the temporary peg recursively
    hanoi(packages - 1, from_peg, temp_peg, to_peg, counter);

    // Proceed straight from source to destination peg with the nth package.
    cout << "Transfer package:\n " << packages << " from " << from_peg << " to " << to_peg << endl;
    ++counter;

    // The n-1 packages are moved recursively from the temporary peg to the target peg.
    hanoi(packages - 1, temp_peg, to_peg, from_peg, counter);
}

int main() {
    int total_packages;   
    int counter = 0; // Tracks number of moves made

    // Ask the user how many packages there are in total.
    cout << "Enter the number of packages: ";
    cin >> total_packages;
    cout << " \n";

    // Solve the Tower of Hanoi problem
    hanoi(total_packages, 'A', 'B', 'C', counter);

    // Display the total number of moves
    cout << "\nTotal moves made: " << counter << "\n ";

    return 0;
}
/* Explanation:
        The Tower of Hanoi method solves a problem by splitting it up into smaller subproblems in a recursive manner.
         The function moves the nth package straight to the destination peg, transfers the top n-1 packages from the source peg to the auxiliary peg, 
         and then moves the n-1 packages from the auxiliary peg to the destination peg for n packages. Recursively, this process is repeated until the base case
         is achieved, at which point there is just one package remaining to shift. The recurrence relation T(n) = 2T(n-1) + 1 describes
         the exponential time complexity of this method; it increases to T(n) = 2^n - 1. As a result, the total time complexity is O(2^n),
         which indicates that as the number of packages rises, so does the number of moves.*/
