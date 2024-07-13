#include "Timer.h"

namespace M3 {

    // Start time getters and setters.
    unsigned long Timer::getStartTime() const {
        return m_startTime;
    }
    Timer& Timer::setStartTime(unsigned long startTime) {
        m_startTime = startTime;
        return *this;
    }

    // Duration getters and setters.
    unsigned long Timer::getDuration() const {
        return m_duration;
    }
    Timer& Timer::setDuration(unsigned long duration) {
        m_duration = duration;
        return *this;
    }


    // Constructor. Sets count up or down.
    Timer::Timer(TimerType timerType) {
        m_timerType = timerType;
    }


    // Methods.

    // start() with no arguments is used for counting up only.
    bool Timer::start() {
        // If the timer is set for counting up then do so.
        if (m_timerType == Timer::TimerType::COUNT_UP) {
            m_startTime = millis();
            return true;

        // Otherwise return false as this is invalid.
        } else {
            return false;
        }
    }

    // start() with a duration is used for counting down only.
    bool Timer::start(unsigned long duration) {
        // If the timer is set for couting down then do so.
        if (m_timerType == Timer::TimerType::COUNT_DOWN) {
            m_startTime = millis();
            m_duration = duration;
            return true;

        // Otherwise return false as this is invalid.
        } else {
            return false;
        }
    }


    // reset() can be used to restart while counting up or down.
    void Timer::reset() {
        // If counting up, call start().
        if (m_timerType == Timer::TimerType::COUNT_UP) {
            Timer::start();
        
        // Else call start(duration).
        } else {
            Timer::start(m_duration);
        }
    }


    // Function used to return the time remaining while counting down.
    unsigned long Timer::timeRemaining() const{
        // If counting down, the return the remaining time.
        if (m_timerType == Timer::TimerType::COUNT_DOWN) {
            return m_startTime + m_duration - millis();
        
        // Otherwise return 0 as an indication of error.
        } else {
            return 0;
        }
    }

    // Function used to return the elapsed time while counting up.
    unsigned long Timer::elapsedTime() const{
        // If counting up, return the elapsed time.
        if (m_timerType == Timer::TimerType::COUNT_UP) {
            return millis() - m_startTime;

        // Otherwise return 0 as an indication of error.
        } else {
            return 0;
        }
    }

    // Function used, while counting down, to determine if the timer has expired or not.
    bool Timer::isTimerExpired() const {
        // If counting down, return if the timer has expired.
        if (m_timerType == Timer::TimerType::COUNT_DOWN) {
            if (millis() - m_startTime >= m_duration) {
                return true;
            } else {
                return false;
            }

        // Else return false to indicate an error situation.    
        } else {
            return false;
        }
    }


}