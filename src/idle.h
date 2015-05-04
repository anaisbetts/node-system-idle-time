#define MAC 1
#define WIN 2
#define LIN 3

#if OS == WIN
#include <stdint.h>
#endif

uint32_t SystemIdleTime(void);
