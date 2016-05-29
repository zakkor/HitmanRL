//
// Created by Edward on 07-Apr-15.
//

#include "Time.h"

Time::Time()
{
    hours = 0;
    minutes = 0;
    seconds = 0;
}

void Time::updateTime(unsigned int secondsElapsed)
{
    if (seconds + secondsElapsed > 59)
    {
        seconds = secondsElapsed - (59 - seconds);
        if (minutes + 1 > 59)
        {
            minutes = 0;
            if (hours + 1 > 23)
            {
                hours = 0;
            }
            else
            {
                hours++;
            }
        }
        else
        {
            minutes++;
        }
    }
    else
    {
        seconds += secondsElapsed;
    }
}
