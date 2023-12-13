/*#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/gpio.h"
#include "hardware/divider.h"
#include "pico/cyw43_arch.h"

// UART defines
// By default the stdout UART is `uart0`, so we will use the second one
#define UART_ID uart1
#define BAUD_RATE 9600

// Use pins 4 and 5 for UART1
// Pins can be changed, see the GPIO function select table in the datasheet for information on GPIO assignments
#define UART_TX_PIN 4
#define UART_RX_PIN 5

// GPIO defines
// Example uses GPIO 2
#define GPIO 2




int main()
{
    stdio_init_all();

    // Set up our UART
    uart_init(UART_ID, BAUD_RATE);
    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    

    // GPIO initialisation.
    // We will make this GPIO an input, and pull it up by default
    gpio_init(GPIO);
    gpio_set_dir(GPIO, GPIO_IN);
    gpio_pull_up(GPIO);
    

    // Example of using the HW divider. The pico_divider library provides a more user friendly set of APIs 
    // over the divider (and support for 64 bit divides), and of course by default regular C language integer
    // divisions are redirected thru that library, meaning you can just use C level `/` and `%` operators and
    // gain the benefits of the fast hardware divider.
    int32_t dividend = 123456;
    int32_t divisor = -321;
    // This is the recommended signed fast divider for general use.
    divmod_result_t result = hw_divider_divmod_s32(dividend, divisor);
    printf("%d/%d = %d remainder %d\n", dividend, divisor, to_quotient_s32(result), to_remainder_s32(result));
    // This is the recommended unsigned fast divider for general use.
    int32_t udividend = 123456;
    int32_t udivisor = 321;
    divmod_result_t uresult = hw_divider_divmod_u32(udividend, udivisor);
    printf("%d/%d = %d remainder %d\n", udividend, udivisor, to_quotient_u32(uresult), to_remainder_u32(uresult));


    puts("Hello, world!");

    return 0;
}
*/
/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
// copied part of this from hello_usb.c from pico-examples

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
// #include "~/Documents/collegeStuff/sem3/pr/frama-c/project/pico-sdk/src/common/pico_stdlib/include/pico/stdlib.h"


/*** DRINKWATER SRIVATSAN ***/
// initialize the time at the beginning.

bool drinkWater(){
    // check current time - init time 
    // if it is greater than some small value 
    // then printf DRINKWATER
}

/*** HEATER JAIADITYA ***/
/*@ requires \valid_read(tempReading);
    requires \valid(heaterState);
    assigns *heaterState;
    ensures *heaterState == 0 || *heaterState == 1;
    
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
        assigns \nothing;
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

void sensor_process(int* rawInput, int* processed){ // LDR reading, analog read, example range is 0 to 255, depends on device
    if (*rawInput > 128) *processed = 1;
    else processed = 0; // this shall be sensor_reading
}

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

// we have a automatic height adjustable standing table

void moveTable(bool* upButton, bool* downButton, int* activateServo){ // 1 is move up, -1 is move down, 0 is idle
    if (!(*upButton && *downButton)){ // when you press one button only
    if (*upButton) *activateServo = 1;
    else if (*downButton) *activateServo = -1;
    else *activateServo = 0; 
    }
    else *activateServo = 0;
}

// /*@
//    axiomatic Exponent{
//     logic integer exp(integer n, integer a);

//     axiom case_m:
//         \forall integer n;
//         \forall integer a;
//         a >= 1 ==> exp(n, a) == n * exp(n, a - 1);
//     axiom case_0:
//         \forall integer n;
//         exp(n, 0) == 1;
//    }
// */

// /*@
//    requires INT_MIN < n < INT_MAX;
//    requires 0 <= a < INT_MAX;
//    assigns \nothing;
//    ensures \result == exp(n, a);
// */
// int exponent(int n, int a){
//     int result = 1;
//     if (a == 0) return result;

//     // loop invariant result == exp(n, i - 1);
//     // check this again
//     /*@
//        loop invariant 0 <= i <= a + 1;
       
//        loop assigns i, result;
//        loop variant a + 1 - i;
//     */
//     for (int i = 1; i <= a; i++) result *= n;
//     return result;
// }

int main() {
    stdio_init_all();
    while (true) { // sample code
        drinkWater();
        // all those funcs
        sleep_ms(1000);
    }
}

