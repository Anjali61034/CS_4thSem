#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of blocks: ";
    cin >> m;

    int processSize[n], blockSize[m], allocation[n];

    cout << "Enter process sizes:\n";
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    cout << "Enter block sizes:\n";
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }

    for (int i = 0; i < n; i++) {
        allocation[i] = -1; // Initialize all allocations to -1 (not allocated)
    }

    // Worst Fit Allocation
    for (int i = 0; i < n; i++) { // Loop through each process
        int worstIdx = -1; // Index for worst block
        for (int j = 0; j < m; j++) { // Loop through each block
            if (blockSize[j] >= processSize[i]) { // If block can fit the process
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) { // Find the largest available block
                    worstIdx = j; // Update worst block index
                }
            }
        }
        if (worstIdx != -1) { // If a block is found
            allocation[i] = worstIdx; // Allocate process to the worst block
            blockSize[worstIdx] -= processSize[i]; // Decrease block size
        }
    }

    // Print allocation results
    cout << "\nWorst Fit Allocation:\n";
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            cout << "Process " << i + 1 << " allocated to Block " << allocation[i] + 1 << endl;
        else
            cout << "Process " << i + 1 << " not allocated\n";
    }

    return 0;
}
