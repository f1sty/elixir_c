#include <erl_driver.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int dummy_init(void);
void dummy_stop(ErlDrvData), dummy_read(ErlDrvData, char*, ErlDrvSizeT);
ErlDrvData dummy_start(ErlDrvPort, char*);
ErlDrvEntry* driver_init(void);

ErlDrvEntry dummy_drv_entry = {
    dummy_init,
    dummy_start,
    dummy_stop,
    dummy_read,
    NULL,
    NULL,
    "dummy_drv",
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    ERL_DRV_EXTENDED_MARKER,
    ERL_DRV_EXTENDED_MAJOR_VERSION,
    ERL_DRV_EXTENDED_MINOR_VERSION
};

ErlDrvPort this_port;
time_t raw_time;
struct tm* time_info;

DRIVER_INIT(dummy_drv) {
    return &dummy_drv_entry;
}

int dummy_init(void) {
    return 0;
}

ErlDrvData dummy_start(ErlDrvPort port, char* command) {
    this_port = port;
    return (ErlDrvData)port;
}

void dummy_stop(ErlDrvData drv_data) {
    fprintf(stderr, "bye-bye!\n");
}

void dummy_read(ErlDrvData drv_data, char* buf, ErlDrvSizeT len) {
    if (strncmp(buf, "now", len) == 0) {
        time(&raw_time);
        time_info = localtime(&raw_time);
        char* t = asctime(time_info);
        int l = strlen(t);
        driver_output(this_port, t, l);
    }
    else driver_output(this_port, buf, len);
}
