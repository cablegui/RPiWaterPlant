#include <wiringPi.h>
#include <iostream>

using namespace std;

int main (void)
{
	int centrefreq = 150;
	wiringPiSetup();

	pinMode(1,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(2000);
	pwmSetClock(192);

	for(int j = 100;j<=200;j+=5)	
	{
		pwmWrite(1, j);
		delay(1000);
	}
	pwmWrite(1,centrefreq);
return 0;
}
