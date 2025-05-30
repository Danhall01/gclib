#ifndef _WECL_REALTIME_CLOCK_H_
#define _WECL_REALTIME_CLOCK_H_

#include <stdint.h>

#if defined(_WIN32) || defined(__CYGWIN__)
#include <windows.h>
#elif defined(__unix__)
#include <time.h>
#else
#error OS is not supported by timer.h
#endif

typedef struct
{
    double limitHigh;
    double limitLow;

#if defined(_WIN32) || defined(__CYGWIN__)
    LARGE_INTEGER frequency;
    LARGE_INTEGER tick;

#elif defined(__unix__)
    struct timespec tick;

#endif
} we_clock_t;

// Sets the inital time for the realtime counter
void weClockSetTime(we_clock_t timer[static 1]);

// Gets the time since gc_settime was called
// @ If you want the current time, use gc_now instead.
double weClockGetTime(we_clock_t timer[static 1]);

// Returns the current time since epoch in seconds
double weClockNow(void);

#endif  // _WECL_REALTIME_CLOCK_H_
