#!/bin/bash
#
#
# chkconfig: 35 90 12
# description: Status Shooter daemon
#
. /etc/init.d/functions
start()
{
	touch /var/lock/statusShooter
	echo "starting status shooter daemon"
	(sudo /media/daemonTest/RaspiBot/statusShooter/main.o && echo "daemon started") || echo "daemon can't start" #change this if finished working on daemon
	
}
stop()
{
    echo "stopping status shooter daemon"
    sudo killall main.o -v
    rm -f /var/lock/subsys/statusShooter
}
case "$1" in
	start )
		start
		;;
	stop )
		stop
		;;
	restart)
		stop
		start
		;;
	*)
		echo $"Usage: $0 {start|stop|restart}"
		exit 1
esac
exit 0 