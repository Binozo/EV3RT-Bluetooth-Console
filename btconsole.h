#ifndef BTCONSOLE_H
#define BTCONSOLE_H

#endif

/**
 * \brief 	     Checks if the brick is connected via bluetooth
 * \returns      true if connected via bluetooth
 */
bool ev3_bt_connected();

/**
 * \brief 	     Checks if the brick is connected to the ev3rt console mobile app
 * \returns      true if connected
 */
bool ev3_bt_console_connected();

/**
 * \brief 	     Sends a message to the ev3 console mobile app
 * \returns      true if sending successful
 */
bool ev3_bt_console_send_message(const char *message);