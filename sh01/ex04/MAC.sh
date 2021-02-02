#!/bin/sh
ifconfig -a | grep ether | grep -ioE '([a-z0-9]{2}:){5}..'
