#include <wiringPi.h>
#include <stdio.h>

int main (void)
{
	wiringPiSetup();
	pinMode(1,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(2000);
	pwmSetClock(192);
	pwmWrite(1, 100);
	printf("Helo");
	for(;;)	
	{
		delay(100);
		printf("hello");
	}
return 0;
}
