//
// Created by Edward on 07-Apr-15.
//

#ifndef _HITMANRL_TIME_H_
#define _HITMANRL_TIME_H_


class Time
{
public:
    Time();

    void updateTime(unsigned int secondsElapsed);

    int hours; // 0 - 23
    int minutes; // 0 - 59
    int seconds; // 0 - 59
};


#endif //_HITMANRL_TIME_H_
