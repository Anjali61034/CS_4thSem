#include <iostream>
#include <unistd.h>   // fork(), exec()
#include <sys/types.h> // pid_t
#include <sys/wait.h>  // waitpid()
#include <cstdlib>     // exit()

using namespace std;

int main() {
    pid_t pid = fork(); // Create child process

    if (pid < 0) {
        // Fork failed
        cerr << "Fork failed!" << endl;
        exit(1);
    }
    
    // Child process
    if (pid == 0) {
        cout << "Child Process (PID: " << getpid() << ") executing...\n";
        
        // Case ii: Same program, different code (child executes another program)
        // execl("/bin/ls", "ls", "-l", NULL);
        execl("/bin/echo", "echo", "Hello", NULL);
        
        // If exec fails
        perror("exec failed");
        exit(1);
    } 
    else {
        // Parent process
        cout << "Parent Process (PID: " << getpid() << ") waiting for child (PID: " << pid << ") to complete...\n";
        
        // Case iii: Parent waits for child to finish
        waitpid(pid, NULL, 0);
        
        // Case i: Same program, same code (executed after child completes)
        cout << "Parent Process (PID: " << getpid() << ") executing its own code after child exits.\n";
    }
    
    return 0;
}
