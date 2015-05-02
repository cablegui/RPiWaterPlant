#include <wiringPi.h>
#include <iostream>

using namespace std;

int main (void)
{
	int freq;
	wiringPiSetup();

	pinMode(1,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(2000);
	pwmSetClock(192);
	cout << "Helo" << endl;
	for(;;)	
	{
		cout << "Enter the frequency" << endl;
		cin >> freq;
		pwmWrite(1, freq);
		delay(100);
	}
return 0;
}
