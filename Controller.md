The controller of this system is the combination of an arduino and an Hx711 amplifier these read the sensor values and decide whether the board should be switched on or off aswell as then communicating that decision to the board.
connecting the Hx711 to the arduino is very simple just using digital pins for DT and SCK as shown in this diagram however these pins are set in the code so you can edit these values as needed.


![691061a469d331747a1019e72d52ae08400071a5](https://github.com/user-attachments/assets/f7d3f430-3a0d-43b8-9185-9bd51f824357)



it is important to connect the P+ and P- wires of the sensor to the E+ and E- and the S+ and S- to the A+ and A- these can be flipped but not interchanged!!!
