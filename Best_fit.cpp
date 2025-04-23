#include <iostream>
using namespace std;

int main() {
    int n, m;

    // Take input for number of processes (n) and number of blocks (m)
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the number of memory blocks: ";
    cin >> m;

    int processSize[n], blockSize[m], allocation[n];

    // Take input for the sizes of the processes
    cout << "Enter the sizes of the processes: ";
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    // Take input for the sizes of the memory blocks
    cout << "Enter the sizes of the memory blocks: ";
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }

    // Initialize allocation array to -1 (indicating no allocation)
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Best Fit algorithm
    for (int i = 0; i < n; i++) { // Loop through each process
        int bestIdx = -1; // Index for the best block
        for (int j = 0; j < m; j++) { // Loop through each block
            if (blockSize[j] >= processSize[i]) { // If block can fit the process
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) { // Check if it's the smallest block that can accommodate the process
                    bestIdx = j; // Update the best block index
                }
            }
        }
        if (bestIdx != -1) { // If a block is found
            allocation[i] = bestIdx; // Allocate process to the best block
            blockSize[bestIdx] -= processSize[i]; // Decrease block size
        }
    }

    // Print allocation results
    cout << "\nBest Fit Allocation:\n";
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to Block " << allocation[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " not allocated\n";
    }

    return 0;
}

