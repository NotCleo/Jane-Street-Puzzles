#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DELTA 0.001 // Step size (smaller is more accurate but slower)
#define NUM_TRIALS 1000000

int main() {
    int count_valid = 0;
    srand(time(0));

    for(int i = 0; i < NUM_TRIALS; i++){
        double blue_x = ((double)rand()) / RAND_MAX;
        double blue_y = ((double)rand()) / RAND_MAX;
        double red_x = ((double)rand()) / RAND_MAX;
        double red_y = ((double)rand()) / RAND_MAX;
        
        double distances[4] = {
            blue_y,          // 0: y=0
            1.0 - blue_x,    // 1: x=1
            blue_x,          // 2: x=0
            1.0 - blue_y     // 3: y=1
        };

        int min_flag = 1; 
        double min_val = distances[0]; 
        
        for(int k = 1; k < 4; k++){
            if(distances[k] < min_val){
                min_val = distances[k]; 
                min_flag = k + 1;       
            }
        }
        
        // diff = (Distance to Blue) - (Distance to Red)
        // If 'diff' changes sign (pos to neg), we found the point.
        
        double current_x = 0;
        double current_y = 0;
        double prev_diff = 0;
        int first_step = 1; 
        int found = 0;      

        double start_val = 0.0;
        
        switch(min_flag) {
            case 1 : // close to y = 0. Iterate x from 0 to 1
                current_y = 0;
                for(double x = 0; x <= 1.0; x += DELTA) {
                    double d_blue = sqrt(pow(blue_x - x, 2) + pow(blue_y - current_y, 2));
                    double d_red  = sqrt(pow(red_x - x, 2)  + pow(red_y - current_y, 2));
                    double curr_diff = d_blue - d_red;

                    if(!first_step) {
                            if (curr_diff * prev_diff <= 0) {
                            found = 1;
                            break; 
                        }
                    }
                    prev_diff = curr_diff;
                    first_step = 0;
                }
                break;

            case 2 : // close to x = 1. Iterate y from 0 to 1
                current_x = 1;
                for(double y = 0; y <= 1.0; y += DELTA) {
                    double d_blue = sqrt(pow(blue_x - current_x, 2) + pow(blue_y - y, 2));
                    double d_red  = sqrt(pow(red_x - current_x, 2)  + pow(red_y - y, 2));
                    double curr_diff = d_blue - d_red;

                    if(!first_step) {
                        if (curr_diff * prev_diff <= 0) {
                            found = 1;
                            break; 
                        }
                    }
                    prev_diff = curr_diff;
                    first_step = 0;
                }
                break;

            case 3 : // close to x = 0. Iterate y from 0 to 1
                current_x = 0;
                for(double y = 0; y <= 1.0; y += DELTA) {
                    double d_blue = sqrt(pow(blue_x - current_x, 2) + pow(blue_y - y, 2));
                    double d_red  = sqrt(pow(red_x - current_x, 2)  + pow(red_y - y, 2));
                    double curr_diff = d_blue - d_red;

                    if(!first_step) {
                        if (curr_diff * prev_diff <= 0) {
                            found = 1;
                            break; 
                        }
                    }
                    prev_diff = curr_diff;
                    first_step = 0;
                }
                break;

            case 4 : // close to y = 1. Iterate x from 0 to 1
                current_y = 1;
                for(double x = 0; x <= 1.0; x += DELTA) {
                    double d_blue = sqrt(pow(blue_x - x, 2) + pow(blue_y - current_y, 2));
                    double d_red  = sqrt(pow(red_x - x, 2)  + pow(red_y - current_y, 2));
                    double curr_diff = d_blue - d_red;

                    if(!first_step) {
                        if (curr_diff * prev_diff <= 0) {
                            found = 1;
                            break; 
                        }
                    }
                    prev_diff = curr_diff;
                    first_step = 0;
                }
                break;
        }

        if(found) {
            count_valid++;
        }
    }
    
    printf("Prob is : %.10f\n", (double)count_valid / NUM_TRIALS);
    return 0;
}
