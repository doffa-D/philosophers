# philosophers


This is a project specification for a programming assignment involving simulating a dining philosophers problem. The project requires the implementation of two programs, one for the mandatory part and another for the bonus part (if the student decides to attempt it).

The simulation consists of several philosophers sitting at a round table with a bowl of spaghetti in the middle of the table. The philosophers alternate between eating, thinking, and sleeping. While eating, they cannot think or sleep, while thinking, they cannot eat or sleep, and while sleeping, they cannot eat or think. There are as many forks on the table as there are philosophers, and each philosopher requires two forks to eat. When a philosopher finishes eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

The program should take the following command line arguments: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, and (optionally) number_of_times_each_philosopher_must_eat. Each philosopher has a number ranging from 1 to number_of_philosophers, and philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N-1 and philosopher number N+1.

The program should not use global variables, and any state change of a philosopher must be formatted correctly. A message announcing a philosopher's death should be displayed no more than 10ms after the philosopher actually dies. Additionally, the program should comply with several other rules, including the norm, no memory leaks, and not quitting unexpectedly. The Makefile should contain several rules, including $(NAME), all, clean, fclean, and re, and (if the bonus part is attempted) a bonus rule should be included.




#                                here is some additional information that might be helpful:

The program you will be writing simulates the behavior of multiple philosophers sitting at a round table and eating spaghetti with forks.


The program should take several command-line arguments, including the number of philosophers, the time it takes for a philosopher to die if they don't eat, the time it takes for a philosopher to eat, the time it takes for a philosopher to sleep, and an optional argument for the number of times each philosopher must eat before the simulation stops.


The philosophers can only eat if they have both the left and right forks, and they must put the forks back on the table when they are finished eating.


The philosophers can eat, think, or sleep, but they cannot communicate with one another.


The simulation continues until a philosopher dies, at which point the simulation should stop.


You should follow specific formatting requirements for the output of your program, which include indicating when a philosopher takes a fork, when they are eating, when they are sleeping, when they are thinking, and when they die.


Your program must be written in C and follow the Norm, which is a set of rules for writing code in a consistent and readable manner. Additionally, your program must not have any unexpected errors, undefined behaviors, or memory leaks.


You may choose to complete a bonus section for the project, but it will be evaluated separately from the mandatory section. If you choose to use your own libraries, you must provide a Makefile that compiles both your project and the library.
