#include <iostream>
#include <chrono>
#include <format>

namespace TimeHandler
{
    std::string getCurrentTime()
    {
        time_t now = time(nullptr);
        tm* currentTime = localtime(&now);
        return std::format("{:04d}-{:02d}-{:02d} {:02d}:{:02d}:{:02d}",
                           currentTime->tm_year + 1900, currentTime->tm_mon + 1,
                           currentTime->tm_mday, currentTime->tm_hour,
                           currentTime->tm_min, currentTime->tm_sec);
    }

    enum class ClockMode
            {
        none,
        single,
        multi
            };

    class Clock
            {
            private:
                std::chrono::time_point<std::chrono::system_clock> mBegin;
                ClockMode mMode;
                double mCheckTime;

            public:
                Clock()
                : mBegin(), mMode(ClockMode::none), mCheckTime(0.0)
                {}

                Clock(const ClockMode& mode, const double& time)
                : mBegin(), mMode(mode), mCheckTime(time)
                {}

                void start()
                {
                    mBegin = std::chrono::high_resolution_clock::now();
                }

                void start(const ClockMode& mode, const double& time)
                {
                    mBegin = std::chrono::high_resolution_clock::now();
                    mMode = mode;
                    mCheckTime = time;
                }

                void stop()
                {
                    mMode = ClockMode::none;
                    mCheckTime = 0.0;
                }

                bool check()
                {
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsedTime = end - mBegin;
                    double elapsedSeconds = elapsedTime.count();

                    if(elapsedSeconds >= mCheckTime)
                    {
                        switch (mMode) {
                            case ClockMode::none:
                                return false;
                                case ClockMode::single:
                                    return true;
                                    case ClockMode::multi:
                                        mBegin = std::chrono::high_resolution_clock::now();
                                        return true;
                        }
                    }

                    return false;
                }

                double getDeltaTime()
                {
                    auto end = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsedTime = end - mBegin;
                    return elapsedTime.count();
                }
            };

    class Timer
            {
            private:
                std::chrono::time_point<std::chrono::system_clock> mBegin;
                std::chrono::time_point<std::chrono::system_clock> mEnd;

            public:
                Timer()
                : mBegin(), mEnd()
                {}

                void start()
                {
                    mBegin = std::chrono::high_resolution_clock::now();
                }

                double stop()
                {
                    mEnd = std::chrono::high_resolution_clock::now();
                    std::chrono::duration<double> elapsedTime = mEnd - mBegin;
                    return elapsedTime.count();
                }
            };
}
