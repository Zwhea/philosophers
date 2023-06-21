# Philosophers

This project, called "Philosophers," is a classic exercise in introductory concurrent programming. It involves solving the dining philosophers problem by using threads or processes to represent the philosophers and forks.

The goal of the project is to apply the basic concepts of concurrent programming, such as thread/process synchronization, shared resource management, and deadlock prevention.

## Problem Description

The dining philosophers problem is a classic illustration of the challenges faced in concurrent programming. It involves a group of philosophers sitting around a table, where each philosopher alternates between thinking and eating. The philosophers share a limited number of forks placed between them.

The problem arises when each philosopher requires two forks to eat, one on their left and one on their right. If all the philosophers simultaneously pick up the fork on their left, they will be stuck waiting for the fork on their right, causing a deadlock.

The task is to implement a solution that ensures all philosophers can continue to eat without causing deadlocks or starvation. This requires careful management of the forks and synchronization between the philosophers.

## Project Requirements

The project must be implemented in the C programming language and should follow the specified requirements provided by 42 School. These requirements may include:

- Implementing the dining philosophers problem using either threads or processes.
- Ensuring that the philosophers alternate between thinking and eating.
- Preventing deadlocks and starvation by carefully managing the forks.
- Handling any necessary synchronization mechanisms, such as mutexes or semaphores.
- Implementing a solution that scales well with a variable number of philosophers and forks.

## Usage

To compile the project, run the following command:
``` shell
make
```

To run the program, use the following command:
``` shell
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: The number of philosophers sitting at the table.
- `time_to_die`: The maximum time in milliseconds a philosopher can go without eating before dying.
- `time_to_eat`: The time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: The time in milliseconds a philosopher spends sleeping.
- `number_of_times_each_philosopher_must_eat`: (Optional) The number of times each philosopher must eat before the program ends. If not provided, the program should not terminate unless there is an error or a philosopher dies.

## Example

Here's an example command to run the program with 5 philosophers, a time to die of 800 milliseconds, a time to eat of 200 milliseconds, a time to sleep of 300 milliseconds, and each philosopher must eat at least 7 times:
``` shell
./philo 5 800 200 300 7
```

## Acknowledgments

This project is part of the curriculum at 42 School, where students learn various programming concepts and skills through practical projects. The "Philosophers" project helps students gain a better understanding of concurrent programming and problem-solving in a multi-threaded/process environment.

## Resources

- [Introduction to Thread](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

- [Optimisations in C -fr](http://tuan.kuranes.free.fr/ecrits/optimisation.html)

- [Philo visualizer](http://tuan.kuranes.free.fr/ecrits/optimisation.html)
