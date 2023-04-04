This is a description of the planned data format for sending and storing the sensor data

### Packet Format
read_serial.py outputs packets for the lora to send as byte arrays

The format is text in the following format
> *Time*,*SensorReadout1*,*SensorReadout2*,...,*SensorReadoutN*

> Time = timestamp in unix epoch time in plaintext\
SensorReadout = sensor readings in plaintext

The sensor readouts are not labelled or have the units attached to save bytes.\
The values are labelled when they are added to the appropriate column in the google spreadsheet.

Example:
> 1675135222,2.49165,90.05391,81.62162

In this example, there are 3 sensor readings

### Errors
Error messages are sent the same using the same path as normal packets

Error messages have the following format to identify them
> !*Time*,*ErrorMessage*

> Time = timestamp in unix epoch time in plaintext\
Error Message = error message in plaintext

Only error messages can start with a '!' character and this can be used for identification.

Example:
> !1675920128,Sensor measurement timed out for Arduino on port /dev/tty1. Check connection to Arduino.

### File system
read_serial.py also continuously saves packets to file system as a backup.\
The format in the file system is identical to the packets with each line being a packet.\
Errors are not logged in the file system.