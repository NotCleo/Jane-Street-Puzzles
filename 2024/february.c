#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int check_x_0(float y1, float y2, float x1, float x2){
    float delta_x = pow((y1+y2),2)-4.0*(x1*x2+y1*y2);

    float root = (y1+y2 + sqrt(delta_x)) / 2.0; 
    return isfinite(root);
}

int check_y_0(float y1, float y2, float x1, float x2){
    float delta_y = pow((x1+x2),2)-4.0*(x1*x2+y1*y2);
    float root = (x1+x2 + sqrt(delta_y)) / 2.0; 
    return isfinite(root);
}

int check_x_1(float y1, float y2, float x1, float x2){
    float delta_x = pow((y1+y2),2)-4.0*(x1*x2+y1*y2+1-(x1+x2));
    float root = (y1+y2 + sqrt(delta_x)) / 2.0; 
    return isfinite(root);
}

int check_y_1(float y1, float y2, float x1, float x2){
    float delta_y = pow((x1+x2),2)-4.0*(x1*x2+y1*y2+1-(y1+y2));
    float root = (x1+x2 + sqrt(delta_y)) / 2.0; 
    return isfinite(root);
}

int main() {
    int precision;
    printf("precision: ");
    scanf("%d", &precision);

    srand(time(NULL));

    int total_circles_off_square = 0;

    for(int i=0; i<precision; i++)
    {
        float x1 = (float)rand() / (float)RAND_MAX;
        float x2 = (float)rand() / (float)RAND_MAX;
        float y1 = (float)rand() / (float)RAND_MAX;
        float y2 = (float)rand() / (float)RAND_MAX;

        if (check_x_0(y1, y2, x1, x2) || 
            check_y_0(y1, y2, x1, x2) || 
            check_x_1(y1, y2, x1, x2) || 
            check_y_1(y1, y2, x1, x2)) 
        {
            total_circles_off_square++;
        }
    }

    printf("Result: %.4f\n", (float)total_circles_off_square / (float)precision);
    printf("Exact:  %.4f\n", 1.0 - (3.14159265 / 6.0)); //as seen in the analytical solution

    return 0;
}
