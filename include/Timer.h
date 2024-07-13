#ifndef TIMER_8234089176_H
#define TIMER_8234089176_H



#include "Arduino.h"

namespace M3 {

    class Timer {
    public:
        // Enums.

        /**
         * @brief  Enum for defining if this is a count up or down timer.
         * @note   
         * @retval None
         */
        enum TimerType { COUNT_UP, COUNT_DOWN };



        // Getters and setters.

        /**
         * @brief  Gets the time at the moment the timer started.
         * @note   
         * @retval Time at the moment the timer started.
         */
        unsigned long getStartTime() const;

        /**
         * @brief  Sets the start time for when the timer started.
         * @note   
         * @param  startTime: millis() value to use as the start time
         * @retval this Timer object
         */
        Timer& setStartTime(unsigned long startTime);

        /**
         * @brief  Get the duration of the timer.
         * @note   
         * @retval Duration of the timer.
         */
        unsigned long getDuration() const;

        /**
         * @brief  Sets the duration of the timer.
         * @note   
         * @param  duration: Duration of the timer in millis.
         * @retval this Timer object
         */
        Timer& setDuration(unsigned long duration);




        // Constructors.

        /**
         * @brief  Constructor
         * @note   
         * @param  timerType: Count up or down timer
         * @retval None
         */
        Timer(TimerType timerType);




        // Methods.

        /**
         * @brief  Starts the timer. Used for counting up only.
         * @note   
         * @retval true or false if the timer was started.
         */
        bool start();

        /**
         * @brief  Starts the timer. Used for counting down only.
         * @note   
         * @param  duration: Duration of the timer in millis.
         * @retval true or false if the timer was started.
         */
        bool start(unsigned long duration);

        /**
         * @brief  Restarts the timer in the same fashion that it was started last time.
         * @note   Works for count up or down timers. If count down was never started with a duration then it uses the default duration.
         * @retval None
         */
        void reset();

        /**
         * @brief  How long in millis is remaing on a count down timer.
         * @note   
         * @retval Count down time remaining in millis.
         */
        unsigned long timeRemaining() const;

        /**
         * @brief  How long in millis has a count up timer been running.
         * @note   
         * @retval Count up run time in millis.
         */
        unsigned long elapsedTime() const;

        /**
         * @brief  Has the count down timer reached a time of 0.
         * @note   
         * @retval Has the count down timer completed.
         */
        bool isTimerExpired() const;



    private:
        // Private members.
        TimerType m_timerType { COUNT_DOWN };   ///< Is this a count up or down timer.
        unsigned long m_duration { 0ul };       ///< Duration of a count down timer.
        unsigned long m_startTime { 0ul };      ///< Start time of a count up timer.

    };

}

#endif