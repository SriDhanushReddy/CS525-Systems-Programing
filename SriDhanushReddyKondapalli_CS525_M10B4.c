#include <stdio.h> // for printf and scanf
#include <unistd.h> // for fork and sleep
#include <signal.h> // for kill and signal
#include <stdlib.h> // for exit

// Function to be called when the alarm sounds
void ding() {
    printf("Ding!\n");
    exit(0);
}

int main() {
    int seconds;
    
    // Prompt the user to enter the number of seconds to wait
    printf("Enter the number of seconds to wait: ");
    scanf("%d", &seconds);
    
    // Create a child process
    pid_t pid = fork();
    
    // If this is the child process
    if (pid == 0) {
        // Wait for the specified number of seconds
        sleep(seconds);
        // Send a SIGALRM signal to the parent process
        kill(getppid(), SIGALRM);
    } 
    // If this is the parent process
    else {
        // Catch the SIGALRM signal and call the ding() function when it is received
        signal(SIGALRM, ding);
        // Pause the parent process until it receives a signal
        pause();
    }
    return 0;
}