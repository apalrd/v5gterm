/* Graphical Terminal library for PROS V5
 * Copyright (c) 2022 Andrew Palardy
 * This code is subject to the BSD 2-clause 'Simplified' license
 * See the LICENSE file for complete terms
 */
#ifndef _GTERM_H_
#define _GTERM_H_

#pragma GCC diagnostic ignored "-Wwrite-strings"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "display/lvgl.h"

/* Function to initialize gterm */
void gterm_init(lv_obj_t * page);

/* Function to destroy gterm */
void gterm_clean();

/* Function to print to the gterm */
void gterm_print_int(const char * str);

/* Macro to print to gterm using printf-like syntax */
#define gterm_print(...) do{char temp[256];snprintf(temp,256,__VA_ARGS__);gterm_print_int(temp);}while(0)

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _GTERM_H_ */