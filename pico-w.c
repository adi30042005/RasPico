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
#include "pico/stdlib.h"


/*** FIBONACCI SRIVATSAN ***/
int fibonacci(int n){ // can also write a function that outputs an array
    // code
}

/*** FACTORIAL JAIADITYA ***/
int factorial(int n){
    // code
}

/*** SATHWIK THE DIVIDER ***/
float divide(float a, float b){ // a / b = q * b + r. give me q and r ie. the quotient and remainder.
    // code
}

/*@
   axiomatic Exponent{
    logic integer exp(integer x, integer m);

    axiom case_m:
        \forall integer x, m;
        m >= 1 ==> exp(x, m) == x * exp(x, m - 1);
    axiom case_0:
        exp(x, 0) == 1;
   }
*/

/*@
   ensures \result == exp(n, a);
   requires INT_MIN < n < INT_MAX;
   requires 0 <= a < INT_MAX;
*/
int exponent(int n, int a){
    int result = 1;
    if (a == 0) return result;
    /*@
       loop invariant 0 <= i <= a + 1;
       loop invariant result == exp(n, i - 1);
       loop assigns i, result;
       loop variant a  + 1 - i;
    */
    for (int i = 1; i <= a; i++) result *= n;
    return result;
}

int main() {
    stdio_init_all();
    while (true) { // sample code
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}

