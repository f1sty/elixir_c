#include <time.h>
#include "nof.h"

char* nof() {
    time_t raw_time;
    struct tm* time_info;
    time(&raw_time);
    time_info = localtime(&raw_time);
    return(asctime(time_info));
}
