# TimeHandler Library
The TimeHandler library provides functionality to work with time-related operations, timers, and clocks in C++. It includes classes for getting the current time, measuring elapsed time, and setting up clocks to trigger events based on time intervals.

## Features
1. getCurrentTime(): This function returns the current date and time in the format "YYYY-MM-DD HH:MM:SS". It uses the standard library's time and localtime functions to get the local time.

2. Clock class:

- Constructor: The Clock class can be constructed without any parameters, or you can provide a clock mode and a time interval to start with. The clock mode can be "none," "single," or "multi," and the time interval is a double value representing the duration in seconds.
- start(): This function starts the clock. If the clock was constructed without any parameters, it will start with the mode "none" and a time interval of 0.0.
- start(mode, time): This function starts the clock with a specified mode and time interval.
- stop(): This function stops the clock and sets the mode to "none" with a time interval of 0.0.
- check(): This function checks if the time interval specified for the clock has elapsed. If the elapsed time is greater than or equal to the specified time, it returns true, otherwise false. For "multi" mode, the clock is reset to start again.
- getDeltaTime(): This function returns the elapsed time in seconds since the clock was last started.
3. Timer class:

- Constructor: The Timer class can be constructed without any parameters.
- start(): This function starts the timer by capturing the current time.
- stop(): This function stops the timer and returns the elapsed time in seconds since it was started.
## Usage
To use the TimeHandler library in your C++ project, follow these steps:

1. Copy the TimeHandler.hpp header file into your project directory.

2. Include the header file in your source code:

```cpp
#include "TimeHandler.hpp"
```
3. Use the functions and classes provided by the library as needed. Here are some examples:
```cpp
#include <iostream>
#include "TimeHandler.hpp"

int main() {
    // Example of getting the current time
    std::string currentTime = TimeHandler::getCurrentTime();
    std::cout << "Current Time: " << currentTime << std::endl;

    // Example of using the Clock class
    TimeHandler::Clock clock;
    clock.start(TimeHandler::ClockMode::single, 5.0); // Start a single-mode clock with a 5-second interval

    while (!clock.check()) {
        // Do some work until the specified time interval has elapsed
    }

    // Example of using the Timer class
    TimeHandler::Timer timer;
    timer.start();

    // Some time-consuming operation
    for (int i = 0; i < 1000000; ++i) {
        // Perform the operation
    }

    double elapsedTime = timer.stop();
    std::cout << "Elapsed Time: " << elapsedTime << " seconds" << std::endl;

    return 0;
}
```
## Contributions
Contributions to the TimeHandler library are welcome. If you encounter any issues or have suggestions for improvements, please feel free to create an issue or submit a pull request on the GitHub repository.

## License
The TimeHandler library is open-source and distributed under the MIT License. See the LICENSE file for more details.
