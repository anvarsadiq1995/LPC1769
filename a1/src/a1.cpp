/*
 ===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
 ===============================================================================
 */

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif
# define RED 0
# define BLUE 1
# define GREEN 2

#include <cr_section_macros.h>
#include<vector>

typedef struct led_seq {
	unsigned int color;
	unsigned long int delay;
	bool state;

} a1;

// TODO: insert other include files here

// TODO: insert other definitions and declarations here

int main(void) {
	unsigned int color[] = { RED, BLUE, GREEN, RED, BLUE, GREEN, RED, BLUE,
			GREEN, RED, BLUE, GREEN };
	unsigned long int delay[] = { 10000, 15000, 125000, 10000, 15000, 125000,
			10000, 15000, 125000, 10000, 15000, 125000 };
	bool state = { true, false, true, true, false, true, true, false, true,
			true, false, true };
	vector<a1> sequence_led;
	a1 temp;
	for (int i = 0; i < 11; i++) {
		temp.color = color[i];
		temp.delay = delay[i];
		temp.state = state[i];
		sequence_led.push_back(temp);

	}

#if defined (__USE_LPCOPEN)
	// Read clock settings and update SystemCoreClock variable
	SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
	// Set up and initialize all required blocks and
	// functions related to the board hardware
	Board_Init();
	// Set the LED to the state of "On"
	Board_LED_Set(0, true);
#endif
#endif

	// TODO: insert code here

	// Force the counter to be placed into memory
	volatile static int i = 0;
	// Enter an infinite loop, just incrementing a counter
	while (1) {
		i++;
	}
	return 0;
}
