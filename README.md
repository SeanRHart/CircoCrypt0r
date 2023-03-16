# CircoCrypt0r
Encryption generator device made with Arduino!!

Pseudo-random number generators or PRNGs have applications in various fields of mathematics and technology from statistics to even video game design. Cryptography also finds a purpose for PRNGs as the starting point for certain stream ciphers. In this project I demonstrated how to create an encryption device that creates a unique cipher based on a formula seed = ϴ3, where theta is the angle of a servo motors position. The servo motor is manipulated using a joystick which allows the easiest setting of the motor’s position. Once the user determines the desired angle they press and hold down a button on the remote which will send a 0xFFFFFFFF to the IR receiver, and the servo motor will be set in place. The seed is then calculated and used in three PRNGs to give a three digit substitute for a character. From there, the full cipher is then displayed to the screen.

If two people wanted to send a message using this device, all they would need to do is set their servo motors to the same angle, and they would both have the correct cipher. One possible application for this machine is of course the need to send messages securely with very little chance of being cracked. As far as general purpose ciphers go, I think this one definitely holds up. For instance, let’s say a user wanted to privately check in with someone.
Pqxubiyyfdsaoiiulcoiixlmpqxsa = “areyouokay”, the motor is in its default state.
Not perfect, but stronger than the basic.
