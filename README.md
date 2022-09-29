# v5gterm

This is a library for VEX V5 using PROS, to provide a printf-like terminal display on the graphical screen.

Usage:

`gterm_init(page)` - Initialize the library on screen, provide an lv_obj_t * parent. If NULL the entire screen will be used.

`gterm_clean()` - Uninitialize the library so you can use the screen for something else

`gterm_print(...)` - printf-like function to print a line of text to the screen. \n or newlines are not required.


Example program can be found below, including text coloring. By compiling this project for the v5 brain, main.cpp will demonstrate these features as well.


```c
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

/* Clean up library when the screen is needed for something else */
gterm_clean();

/* You must call gterm_init before using it again */
```

## Installation with PROS
To add this library to your PROS project:

Download the latest release zip file (i.e. `v5gterm@1.0.0.zip`) from Github's release page into your project folder

Add the zip file to pros's local template archive (using the filename of the version you downloaded):
```bash
pros conduct fetch v5gterm@1.0.0.zip
```

Apply the library to your PROS project
```bash
pros conduct apply v5gterm
```

You should now delete the zip file.