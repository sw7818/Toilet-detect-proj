#include <Nextion.h>  // Include the nextion library (the official one) https://github.com/itead/ITEADLIB_Arduino_Nextion

int variable1 =0;

NexText t1 = NexText(0, 5, "t1");  // Text box added, so we can read it


NexTouch *nex_listen_list[] = 
{
  
  NULL  // String terminated
};  // End of touch event list
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Start serial comunication at baud=9600


  // I am going to change the Serial baud to a faster rate.
  // The reason is that the slider have a glitch when we try to read it's value.
  // One way to solve it was to increase the speed of the serial port.
  delay(500);  // This dalay is just in case the nextion display didn't start yet, to be sure it will receive the following command.
  Serial.print("baud=115200");  // Set new baud rate of nextion to 115200, but it's temporal. Next time nextion is power on,
                                // it will retore to default baud of 9600.
                                // To take effect, make sure to reboot the arduino (reseting arduino is not enough).
                                // If you want to change the default baud, send the command as "bauds=115200", instead of "baud=115200".
                                // If you change the default baud, everytime the nextion is power ON is going to have that baud rate, and
                                // would not be necessery to set the baud on the setup anymore.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to nextion.
  Serial.write(0xff);
  Serial.write(0xff);

  Serial.end();  // End the serial comunication of baud=9600

  Serial.begin(115200);  // Start serial comunication at baud=115200

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(30);  // This is the only delay on this loop.
              // I put this delay because without it, the timer on the display would stop running.
              // The timer I am talking about is the one called tm0 on page 0 (of my example nextion project).
              // Aparently we shouldn't send data to the display too often.



  // I created the following variable to have a dynamic number to send to the display:
  variable1++;  // Add 1 to the variable1
  if(variable1 > 10000){  // If the variable is above 240
    variable1 = 0;  // Set variable to 0 to start over


  if (variable1 = 69){
    Serial.print("t1.txt=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
    Serial.print("LOL");  // This is the value you want to send to that object and atribute mentioned before.
    Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
    Serial.write(0xff);
    Serial.write(0xff);
    
  }
  }









  Serial.print("n0.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(variable1);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);

  Serial.print("n1.val=");  // This is sent to the nextion display to set what object name (before the dot) and what atribute (after the dot) are you going to change.
  Serial.print(variable1/5);  // This is the value you want to send to that object and atribute mentioned before.
  Serial.write(0xff);  // We always have to send this three lines after each command sent to the nextion display.
  Serial.write(0xff);
  Serial.write(0xff);

    nexLoop(nex_listen_list);  // Check for any touch event


}
