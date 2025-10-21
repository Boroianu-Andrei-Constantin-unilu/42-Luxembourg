#!/bin/sh
ifconfig | grep -oE '([[:xdigit:]]{2}:){5}[[:xdigit:]]{2}'