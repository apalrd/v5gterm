#include "main.h"
#include "pal/gterm.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	/* Initialize with NULL to use the default screen
	 * Using pages should be supported but is untested
	 */
	gterm_init(NULL);

	/* Basic print */
	gterm_print("Hello, World!");

	/* Recolor a line of text as RED:
	 * Use # as an escape character
	 * followed by 6 hex digits (the color)
	 * then a space (it will be removed)
	 * End the recoloring with a # (no space required)
	 * 
	 * Note that due to recoloring, you cannot use '#' in your text!
	 */
	gterm_print("Motor 1 has #ff0000 failed!#");

	/* Long text example - the line is truncated to fit on the screen */
	gterm_print("According to all known laws of aviation, there is no way that a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway because bees don't care what humans think is impossible.");

	/* Another line after the long one, this time in green */
	gterm_print("#00ff00 This is fun#");

	/* Include some numbers here, using printf syntax */
	double distance = 6.06;
	int state = 3;
	gterm_print("The distance was %03.3f, state is %2d",distance,state);

	for(int i = 0; i < 10; i++)
	{
		gterm_print("Line %d",i);
	}
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {

}
