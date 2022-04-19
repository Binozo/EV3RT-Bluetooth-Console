# EV3RT-Bluetooth-Console
A EV3RT Bluetooth library which handles all the communication with the Mobile App.

# Setup
- Place btconsole.cpp and btconsole.h in your [EV3RT](https://ev3rt-git.github.io/about/) project
- Add `btconsole.o` to `Makefile.inc`
  Example:
  ```
  APPL_COBJS +=
  APPL_CXXOBJS += btconsole.o
  
  SRCLANG := c++
  
  ifdef CONFIG_EV3RT_APPLICATION
  
  # Include libraries
  include $(EV3RT_SDK_LIB_DIR)/libcpp-test/Makefile
  include $(EV3RT_SDK_LIB_DIR)/lib2/Makefile
  
  endif
  ```
  
# Methods

## `ev3_bt_connected()`
- Returns true if the brick is connected with a device via bluetooth

## `ev3_bt_console_connected()`
- Returns true if the brick is connected to the EV3RT Mobile App

## `ev3_bt_console_send_message(const char *message)`
- Sends a message to the Mobile App
- Example: `ev3_bt_console_send_message("Hello World")`
- Caution: Sending a message containing "!" results in a disconnect from the mobile app
- Returns true if successful

## `ev3_bt_console_receive_message(char *buffer)`
- Reads a message from the Mobile App
- Example: 
  ```
  char strbuf;
  ev3_bt_console_receive_message(&strbuf);
  const char message = strbuf;
  ev3_bt_console_send_message(&message);
  ```
