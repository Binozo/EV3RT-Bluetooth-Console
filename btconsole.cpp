//
// Created by binozoworks on 19.04.22.
//

#include "btconsole.h"
#include "../../common/ev3api/include/ev3api.h" // (Debug)
#include "ev3api.h"
#include "syssvc/serial.h"
#include <string.h>
bool ev3_bt_connected() {
    return ev3_bluetooth_is_connected();
}

bool ev3_bt_console_connected() {
    FILE *bt = ev3_serial_open_file(EV3_SERIAL_BT);
    fprintf(bt, "connected?\n");
    ER_UINT erlen;
    char strbuf[2048];
    while(true) {
        char buf;
        erlen = serial_rea_dat(SIO_PORT_BT, &buf, 1);
        if(buf == '\r') {
            break;
        }
        if(erlen != 1) {
            assert(!ev3_bt_connected());
            return false;
        }
        strcat(strbuf, &buf);
    }
    return strcmp(strbuf, "yes") == 0;
}

bool ev3_bt_console_send_message(const char *message) {
    FILE *bt = ev3_serial_open_file(EV3_SERIAL_BT);
    fprintf(bt, "%s", message);
}

void ev3_bt_console_receive_message(char *buffer) {
    ER_UINT erlen;
    char strbuf[2048];
    while(true) {
        char buf;
        erlen = serial_rea_dat(SIO_PORT_BT, &buf, 1);
        if(buf == '\r') {
            break;
        }
        if(erlen != 1) {
            assert(!ev3_bt_connected());
        }
        strcat(strbuf, &buf);
    }
    strcpy(buffer, strbuf);
}