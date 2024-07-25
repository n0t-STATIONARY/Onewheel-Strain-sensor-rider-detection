#include <HX711.h>
#include <Adafruit_TinyUSB.h>

#define DOUT1 10
#define CLK1 9
#define OUT 8

HX711 scale1; //(DOUT1, CLK1);
Adafruit_USBD_CDC usb_serial; //this is for the specific arduino I am using the xiao nrf52480



int outputState = 0; //whether the board is on or off
bool startup = true;
bool calibrated = false;

int startAvg = 0;
int riderAvg = 0;
int i;

int higher;
int lower;

int upperThresh =0;
int lowerThresh =0;

int upperOut = HIGH;
int lowerOut = LOW;



void setup() {
  Serial.begin(115200);
  usb_serial.begin(115200);
  scale1.begin(DOUT1, CLK1, OUT);
  scale1.set_gain(128);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(OUT, OUTPUT);

  startup = true;
  calibrated = false;
  
  
}

void loop() {
  float val = scale1.get_value();
  
  // when the board is first turned on an average sensor reading is taken
  if (startup == true) {
    for(i = 0; i < 30; i++){
        startAvg += val;
        Serial.println(val);
        
    }
    startAvg /= 30;
    Serial.println(startAvg);

    startup = false;


  }
  

  
  // when someone stands on the board the another average sensor reading is taken
  if (calibrated == false){
    if ((val/startAvg) > 1.1 || (val/startAvg) < 0.9){
        delay(500);
        if ((val/startAvg) > 1.1 || (val/startAvg) < 0.9){
          for(i = 0; i < 30; i++){
          riderAvg += val;
          
          }
          riderAvg /=30;

          // based on the sensor readings some thresholds are set
          if (startAvg > riderAvg){

            startBiggerThanCali = true;
            higher = startAvg;
            lower = riderAvg;

            upperOut = HIGH;
            lowerOut = LOW;
          }
          else {
            higher = riderAvg;
            lower = startAvg;
            upperOut = LOW;
            lowerOut = HIGH;
          }

          // working out thresholds

          upperThresh = (lower - higher)*0.45 + higher;
          lowerThresh = (lower - higher)*0.55 + higher;
          calibrated = true;
          

        }

    }
    else{

      Serial.println("rider not detected"); // for testing
    }

  }
  

  // telling the board if it needs to be on or off 
  // IMPORTANT vesc is reversed this is for regular XR
  
  if (outputState==1 && val > upperThresh) {
    outputState = 0;
    digitalWrite(OUT, upperOut);

    
  } else if (outputState==0 && val < lowerThresh) {
    outputState = 1;
    digitalWrite(OUT, lowerOut);
    
  }
  Serial.println(outputState);

  
  

  
  

  
  
  
  delay(1);
  
}