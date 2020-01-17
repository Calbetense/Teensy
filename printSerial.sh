#!/bin/bash


if [ -c /dev/ttyUSB0 ]; then
	echo " There is something plugged, let's see if wanna talk..."
	file=/dev/ttyUSB0
elif [ -c /dev/ttyACM0 ]; then 
	echo " There is something plugged, let's see if wanna talk..."
	file=/dev/ttyACM0
else 
	echo " Nothing to do here"
	exit 1
fi


echo " Please, give me permission to force him!"
sudo chmod 660 $file
echo " -Baud rate at 9600-"
stty -F $file 9600 raw
cat < $file
	


