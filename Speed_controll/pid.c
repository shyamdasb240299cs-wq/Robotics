#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float kp = 1.2, ki = 0.02, kd = 0.5;

float target, current;
float prev_error = 0;
float i_error = 0;

int main() {
    printf("Enter target speed: ");
    scanf("%f", &target);

    printf("Enter initial speed: ");
    scanf("%f", &current);

    printf("=== PID SPEED CONTROL ===\n");

    for(int i=0; i<20; i++) {

        float p_error = target - current;  

        i_error += p_error;                
        float d_error = p_error - prev_error; 

        float output = kp*p_error + ki*i_error + kd*d_error;

        current += output * 0.1;

        current += (rand()%5 - 2);

        printf("Target: %.0f | Current: %.2f | P: %.2f | I: %.2f | D: %.2f | Output: %.2f\n",
               target, current, p_error, i_error, d_error, output);

        prev_error = p_error;

        usleep(500000);  
    }

    return 0;
}