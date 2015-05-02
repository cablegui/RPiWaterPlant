#include <iostream>
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

using namespace std;

#define SERVER "localhost"
#define USER "root"
#define PASSWORD "ga01r4956"
#define DATABASE "pi"

int main()
{
	MYSQL *connect;
	connect=mysql_init(NULL);
	if(!connect)
	{
		cout << "MySQL Initilisation failed";
		return 1;
	}

	connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);
	if(connect)
	{
		cout << "Connection succeeded\n";
	}
	else
	{
		cout << "Connection failed\n";
	}

	MYSQL_RES *res_set;
	MYSQL_ROW row;
	mysql_query(connect, "select pinstatus from gpio where pinnumber = 18");
	unsigned int i = 0;
	unsigned int mypin18status = 0;;
	res_set = mysql_store_result(connect);
	unsigned int numrows = mysql_num_rows(res_set);
	while(((row = mysql_fetch_row(res_set)) != NULL))
	{
		mypin18status = atoi(row[i]);
	}

	cout << "pin 18 status " << mypin18status << endl;

	int centrefreq = 150;
	wiringPiSetup();
	pinMode(1,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetRange(2000);
	pwmSetClock(192);

	if(mypin18status > 210 || mypin18status < 90)
	{

		pwmWrite(1, centrefreq);
	}
	else
	{
		pwmWrite(1, mypin18status);
	}

	mysql_close(connect);
	return 0;
}
