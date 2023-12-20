#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/*** 
 * THIS IS A SAMPLE PROJECT THAT MANAGES A SMART DESKTOP. THE DESKTOP HAS A LIGHT CONTROL MODULE
 * THAT AUTOMATICALLY OPERATES THE TABLE LAMP BASED ON THE AMBIENT LIGHT CONDITIONS, A TEMPERATURE'
 * CONTROL MODULE THAT MAINTAINS THE TEMPERATURE BETWEEN 20*C AND 25*C, AND A MODULE TO CONTROL AN 
 * LED THAT IS PERIODICALLY ACTIVATED TO REMIND THE USER TO DRINK WATER. IN ADDITION, THERE IS A 
 * MODULE TO ADJUST THE HEIGHT OF THE DESKTOP BASED ON USER INPUT (UP/DOWN BUTTONS).
 * ***/

 /*** PRESENTED BY 
  * CB.EN.U4CSE22206 - ANANTHAKRISHNAN BALAJEE
  * CB.EN.U4CSE22223 - JAIADITYA V
  * CB.EN.U4CSE22231 - K SATHVIK
  * CB.EN.U4CSE22249 - SRIVATSAN S
  * ***/

/*** DRINKWATER SRIVATSAN ***/

void drinkWater(){
    return;
}

/*** HEATER JAIADITYA ***/

/*@ requires \valid_read(tempReading);
    requires \valid(heaterState);
    assigns *heaterState;
    
    behavior below_20:
        assumes *tempReading < 20;
        assigns *heaterState;
        ensures *heaterState == 1;
    
    behavior above_25:
        assumes *tempReading > 25;
        assigns *heaterState;
        ensures *heaterState == 0;
    
    behavior between_20_and_25:
        assumes 20 <= *tempReading <= 25;
        ensures \old(*heaterState) == *heaterState;
    
    complete behaviors below_20, above_25, between_20_and_25;
    disjoint behaviors below_20, above_25, between_20_and_25;
*/
void control_heater(const int* tempReading, int* heaterState) {
    if (*tempReading < 20) {
        *heaterState = 1;
    } else if (*tempReading > 25) {
        *heaterState = 0;
    }
    // If temp is between 20°C and 25°C, heater state remains unchanged
}


/*** SATHWIK LIGHT ***/

/*@
    requires \valid_read(sensor_reading);
    requires \valid(device_state);
    requires 0 <= *sensor_reading < 256;
    assigns *device_state;
    behavior dark_room:
        assumes *sensor_reading <= 128;
        ensures *device_state == \true;
    behavior lit_roon:
        assumes *sensor_reading > 128;
        ensures *device_state == \false;
    complete behaviors;
    disjoint behaviors;
*/

void light_control(int *sensor_reading, bool *device_state) {
    if (*sensor_reading <= 128) {
        *device_state = true; 
    } else {
        *device_state = false; 
    }
}


/*** MOVE TABLE ***/

/*@
   requires \valid_read(upButton);
   requires \valid_read(downButton);
   requires \valid(activateServo);
   assigns *activateServo;
   ensures *activateServo \in({1, -1, 0});
   behavior up:
    assumes *upButton == \true && *downButton == \false;
    ensures *activateServo == 1;
   behavior down:
    assumes *downButton == \true && *upButton == \false;
    ensures *activateServo == -1;
   behavior nothing:
    assumes *downButton == \false && *upButton == \false;
    ensures *activateServo == 0; 
   behavior everything:
    assumes *downButton == \true && *upButton == \true;
    ensures *activateServo == 0;  
   complete behaviors;
   disjoint behaviors; 
*/

// we have an automatic height adjustable standing table

void moveTable(bool* upButton, bool* downButton, int* activateServo){ // 1 is move up, -1 is move down, 0 is idle
    if (!(*upButton && *downButton)){ // when you press one button only
    if (*upButton) *activateServo = 1;
    else if (*downButton) *activateServo = -1;
    else *activateServo = 0; 
    }
    else *activateServo = 0;
}

// sample main; doesn't work without required libraries;

// int main() {
//     stdio_init_all();
//     while (true) { // sample code
//         // all those funcs
//         // sleep_ms(1000);
//     }
// }