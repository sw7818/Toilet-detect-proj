int pinReceiver1 = 6; 
int pinReceiver2 = 5; 
int x = 0;
int capacity = 5;

int cap = 3;
char buffer[100] = {0};


#include "Nextion.h"

// Here we're defining each of the elements on the screen 


NexText tEnter = NexText(0, 5, "tEnter"); 
NexText tOcc = NexText(0, 8, "tOcc"); 
NexText tEwait = NexText(0, 9, "tEwait");
NexText tCap = NexText(0, 10, "tCap");
NexText tCap2 = NexText(1, 4, "tCap2");
NexButton bcapacity = NexButton(0, 3, "bcapacity");
NexButton b2 = NexButton(1, 7, "b2");
NexButton bplus = NexButton(1, 5, "bplus");
NexButton bminus = NexButton(1, 6, "bminus");


NexTouch *nex_listen_list[] = {
  &bcapacity,
  &b2,
  &bplus,
  &bminus,
  NULL
};





// so we need to keep on :
//    1. updating the occupancy of the toilet
//    2. update the wait time 
//    3. Room capacity page0 
//    4. Room capacity page1 
void setup() {
  Serial.begin(9600);

  pinMode(pinReceiver1, INPUT);
  pinMode(pinReceiver2, INPUT);

  nexInit();

  bplus.attachPop(btnPlusPopCallback, &bplus); 
  bminus.attachPop(btnMinusPopCallback, &bminus);

  
  

}



void loop() {

  int value_1 = digitalRead(pinReceiver1); 
  int value_2 = digitalRead(pinReceiver2);
  
  

  if (value_1 == 0){
    if (value_2 ==1){
    Serial.println("Oi someones coming in");
    x++;
    tOcc.setText(x);
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
    tOcc.setText(x);
    while((value_1 == 0) || (value_2 ==0)){
      value_1 = digitalRead(pinReceiver1); 
      value_2 = digitalRead(pinReceiver2);
      
    }
    }
  

Serial.println("The number of people in the toilet is:   ");
Serial.print(x);

if (x==5){
  tEnter.setText("Unavailable");
}



  
  
}
}
