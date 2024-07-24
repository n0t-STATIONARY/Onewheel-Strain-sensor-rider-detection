# Onewheel-Strain-sensor-rider-detection
This is an opensource project to showcase an alternative method for rider detection on a Onewheel this method uses the strain of the aluminium rails to determine whether your weight is distributed between the foot sensors.

I have created a simple code base that determins a threshold then use the threshold to turn the Onewheel on and off currently the code is in a very simple form with a simple calibration sequence I encourage people to update the code with more safety oriented features and complex forms of rider detection.

I have also created a board that I will be selling for those who are unable to DIY their own solution these will be aviailable in kits from my store along with the connectors and sensor required to set up the board. 

How Does It Work:
the strain sensor is mounted to the inside top edge of the rail this allows for the sensor to stretch as the board is stood apon. An aplifier called HX711 is used to aplify the signal and digitise the analog output, these values are read by an arduino of any variety which has the code on board to determin whether to switch the board on or off. Finally there is a connector that plugs into the standard Onewheel footpad connection point.

Benifits:
this system will allow you to modify the sensitivity of the board aswell as adding additional features such as a trolly handle button system or a blutooth on and off button for long ghost rides ect. 
the user is also able to use any footpad that is designed for the back of the board on the front without any change to the functionality of the sensor eg. Kush wide.

Drawbacks: 
tricks requiring a foot to be on the front of the board while the tyre spins out are no longer possible.
there is an additonal point of failier with the arduino in place however this can be mitagated through carefull additions to the code.
