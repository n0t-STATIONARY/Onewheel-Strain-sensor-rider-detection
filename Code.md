The first itteration of the code is designed as a test it runs a calibration sequence every time the board it turned on and if a user is unaware that this proccess is taking place they can mess it up leading to ghosting so if you use the first itteration of the code be sure to read the code through and be comfortable with how it works before attempting to use the board.

How It Works:

This only applys so early itterations of the code. When the board is switched on an average sensor value is recorded. If the value then changes by more than 10% of this origonal average the board assumes someone has stood on it and as a result it will take another average which takes around 0.5 seconds after steping on the board. It is IMPORTANT to remain with your weight on the board for atleast 0.7 seconds after standing on it to avoid bad readings.

Finally these two averages are compared to form thresholds that are used to determine if the rider is present.
