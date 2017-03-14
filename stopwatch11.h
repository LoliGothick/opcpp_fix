# ifndef STOPWATCH11_H
#   define STOPWATCH11_H
#   include <chrono>

using namespace std::chrono;
class TimerBaseChrono {
public:
    // tick type
    typedef std::chrono::system_clock::time_point tick_t;

    //  clears the timer
    TimerBaseChrono() : m_start(system_clock::time_point::min()) { }

    //  clears the timer
    void Clear() {
        m_start = system_clock::time_point::min();
    }

    //  returns true if the timer is running
    bool IsStarted() const {
        return (m_start != system_clock::time_point::min());
    }

    //  start the timer
    void Start()            { m_start = std::chrono::system_clock::now(); }

    // get lap time in ticks
    tick_t GetTicks() {
        return IsStarted() ? std::chrono::system_clock::now() : tick_t{};
    }

    //  get the number of milliseconds since the timer was started
    unsigned long GetMs() {
        if (IsStarted()) {
            system_clock::duration diff;
            diff = system_clock::now() - m_start;
            return (unsigned)(duration_cast<milliseconds>(diff).count());
        }
        return 0;
    }

    unsigned long GetMs(const tick_t& lap) {
        if (IsStarted()) {
            system_clock::duration diff;
            diff = lap - m_start;
            return (unsigned)(duration_cast<milliseconds>(diff).count());
        }
        return 0;
    }

private:
    tick_t m_start;
};
#   include "stopwatch.h"
typedef basic_stopwatch<TimerBaseChrono> Stopwatch;
# endif