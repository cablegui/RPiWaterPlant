#!/bin/bash

mysqlusername=root
mysqlpassword=ga01r4956


waittime=5
#echo "How long you want the led to blackout to default off?"
blackouttime=$(expr $waittime \* 2)

echo "17" > /sys/class/gpio/export

#start loop
while :
do

status17=$(mysql -B --disable-column-names --user=$mysqlusername --password=$mysqlpassword pi -e "select pinstatus from gpio where pinnumber = 17";)

if [ "$status17" == 1 ]; then
	echo "out" > /sys/class/gpio/gpio17/direction
	echo "1" > /sys/class/gpio/gpio17/value
	bash ~/create30secvid.sh &#record the video and save as /var/www/my30secvideo.mp4  and let the script continue
	bash ~/filename.sh
	~/motorcontrol2 & #run the servo
	sleep $blackouttime
	mysql -B --disable-column-names --user=$mysqlusername --password=$mysqlpassword pi -e "update gpio set pinstatus = 0 where pinnumber = 17";
else
	if [ "$status17" == 0 ]; then
		echo "0" > /sys/class/gpio/gpio17/value
		echo "17" /sys/class/gpio/unexport
		~/motorcontrol2 &
	fi
fi

sleep $waittime
done
