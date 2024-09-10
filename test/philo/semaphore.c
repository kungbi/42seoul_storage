#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/mman.h>

#define PHILOSOPHERS 5

// Semaphore for each fork
sem_t *forks[PHILOSOPHERS];

void philosopher(int id, int time_to_eat, int time_to_sleep) {
    int left_fork = id;  // Left fork index
    int right_fork = (id + 1) % PHILOSOPHERS;  // Right fork index (wrap around)

	if (id % 2 == 0) 
		usleep(time_to_eat / 2 * 1000);

    while (1) {
        // Even philosophers pick up left fork first
        sem_wait(forks[left_fork]);
        printf("Philosopher %d took left fork.\n", id);
        sem_wait(forks[right_fork]);
        printf("Philosopher %d took right fork.\n", id);
    
        // Eating
        printf("Philosopher %d is eating.\n", id);
        usleep(time_to_eat * 1000);  // Simulate eating time

        // Put down forks
        sem_post(forks[left_fork]);
        sem_post(forks[right_fork]);
        printf("Philosopher %d put down both forks.\n", id);

        // Sleeping
        printf("Philosopher %d is sleeping.\n", id);
        usleep(time_to_sleep * 1000);  // Simulate sleeping time
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s time_to_eat time_to_sleep\n", argv[0]);
        return 1;
    }

    int time_to_eat = atoi(argv[1]);
    int time_to_sleep = atoi(argv[2]);

    // Initialize each fork semaphore
    for (int i = 0; i < PHILOSOPHERS; i++) {
        char sem_name[10];
        sprintf(sem_name, "/fork%d", i);  // Unique name for each fork
        forks[i] = sem_open(sem_name, O_CREAT, 0644, 1);  // Initialize each semaphore to 1
        if (forks[i] == SEM_FAILED) {
            perror("sem_open failed");
            return 1;
        }
    }

    // Fork processes for each philosopher
    for (int i = 0; i < PHILOSOPHERS; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            philosopher(i, time_to_eat, time_to_sleep);
            exit(0); // Child process exits after finishing
        }
    }

    // Parent waits for all philosopher processes to finish
    for (int i = 0; i < PHILOSOPHERS; i++) {
        waitpid(-1, NULL, 0);  // Wait for any child process to finish
    }

    // Close and unlink the semaphores
    for (int i = 0; i < PHILOSOPHERS; i++) {
        sem_close(forks[i]);
        char sem_name[10];
        sprintf(sem_name, "/fork%d", i);  // Unique name for each fork
        sem_unlink(sem_name);  // Remove semaphore
    }

    return 0;
}
