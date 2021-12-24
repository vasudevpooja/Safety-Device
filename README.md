# Materials Used:
• Arduino Nano

• SIM900 Modem

• NEO6M GPS module

• 433 MHZ RF Transmitter and Receiver

• Button

• Battery

• Breadboard

• Jumpers

[Connections made](https://github.com/vasudevpooja/Safety-Device/blob/main/Project/Project.png)

# Working of the Project (there are two parts): 

**The purpose of making two individual parts here is, to minimize the size of the transmitting module so that it can be worn as a wrist band.**

1. **The Transmitter Section**

A wrist band that can be worn by the person.
It consists of an SOS button which when pressed calls the person whose number is registered in the code and sends an SMS along with the current location.

2. **The Receiver Section**

This part of the project is to be carried by the user. 
Here an Arduino Nano can be used which is interfaced with a NEO6M GSM which is used for sending an alert and a SIM900A GPS module which is used to track the location coordinates.
The RF Transmitter (the band) and the RF Receiver (which is carried by the user) is used for wireless communication between the Band and Receiving device with GPS/GSM.

# Explanation of the Code:

[Arduino Nano Code for the Safety Device](https://github.com/vasudevpooja/Safety-Device/blob/main/src/Safety_Device/Safety%20Device%20Arduino%20Nano-Code.ino)

• **TinyGPS++.h** library is used to get the GPS coordinates using the GPS receiver module.

• Declare the connection pins of the GPS module and its default baud rate, which is 9600 over here.

• Declare the objects for the **TinyGPSPlus** class. 

• Define the object for **SoftwareSerial** class with the pins as arguments declared earlier.

• Inside **setup ()**, declare all the input pins and output pins. 

• Initialize the hardware serial and Software serial functionality, providing the default baud rate.

• Inside **loop ()**, the digital input status for pin 12 is read and stored in a variable. When this status is HIGH, which indicates that, the switch is pressed in the transmitter side, hence the Arduino turns the Buzzer ON.

• Which then calls a function **sendsms()**, that sends a SMS consisting the Location data.

• When valid data is found having GPS coordinates, the data is stored in two separate variables as Latitude and Longitude.

• Finally, a function written is to send the SMS to the registered number. 

• Here the **SIM900 GSM** modem is set to SMS text mode using **AT + CMGF** command. 

• The recipient’s number is defined in the code. 

• The message with location variables appended within is sent via the serial terminal
