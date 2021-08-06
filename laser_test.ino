
// Defined variables 

int pinReceiver1 = 6; 
int pinReceiver2 = 5; 
int x = 0;
int cap = 3;


#include "Nextion.h"

// Here we're defining each of the elements on the screen 


NexText tEnter = NexText(0, 5, "tEnter"); 
NexButton bcapacity = NexButton(0, 3, "bcapacity");
NexButton b2 = NexButton(1, 7, "b2");
NexButton bplus = NexButton(1, 4, "bplus");
NexButton bminus = NexButton(1, 5, "bminus");

// these are the pages 

NexPage page0 = NexPage(0, 0, "page0");  // Page added as a touch event
NexPage page1 = NexPage(1, 0, "page1");  // Page added as a touch event


NexTouch *nex_listen_list[] = {
  &bcapacity,
  &b2,
  &bplus,
  &bminus,
  NULL
};


void bplusPushCallback(void *ptr) // press event for plush button
{
  
  cap = cap +1;
  Serial.print("n2.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(cap);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);
  
  }


void bminusPushCallback(void *ptr) // press event for plush button
{
  
  cap = cap -1;
  Serial.print("n2.val=");  
  Serial.print(cap);  
  Serial.write(0xff);  
  Serial.write(0xff);
  Serial.write(0xff);
  
  }




// update the wait time ___________________________________________________________________________

void setup() {
  Serial.begin(9600);

  Serial.print("baud=115200");  // Set new baud rate of nextion to 115200, but it's temporal. Next time nextion is power on,
                                // it will retore to default baud of 9600.
                                // To take effect, make sure to reboot the arduino (reseting arduino is not enough).
                                // If you want to change the default baud, send the command as "bauds=115200", instead of "baud=115200".
                                // If you change the default baud, everytime the nextion is power ON is going to have that baud rate, and
                                // would not be necessery to set the baud on the setup anymore.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to nextion.
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.begin(115200);  // Start serial comunication at baud=115200


  pinMode(pinReceiver1, INPUT);
  pinMode(pinReceiver2, INPUT);
  nexInit();

  bplus.attachPush(bplusPushCallback);
  bminus.attachPush(bplusPushCallback);

}

void loop() {

  delay(30);
  int value_1 = digitalRead(pinReceiver1); 
  int value_2 = digitalRead(pinReceiver2);
  
  

  if (value_1 == 0){
    if (value_2 ==1){
    Serial.println("Oi someones coming in");
    x++;
    //tOcc.setText(x);
    Serial.print("n0.val="); 
    Serial.print(x) ;
    Serial.write(0xff);  
    Serial.write(0xff);
    Serial.write(0xff);

    
    
    while((value_1 == 0) || (value_2 ==0)){
    value_1 = digitalRead(pinReceiver1); 
    value_2 = digitalRead(pinReceiver2);
    }
    }
    }
    

  
  if (value_2 == 0){
    if (value_1 ==1){
    Serial.println("Oi someones coming out");
    x--;
    //tOcc.setText(x);

    Serial.print("n0.val=");
    Serial.print(x);   
    Serial.write(0xff);  
    Serial.write(0xff);
    Serial.write(0xff);
    while((value_1 == 0) || (value_2 ==0)){
      value_1 = digitalRead(pinReceiver1); 
      value_2 = digitalRead(pinReceiver2);
      
    }
    }
  nexLoop(nex_listen_list); // checks for any touch action on the screen 



}
  




  
  
}
