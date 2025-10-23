#!/bin/sh
ip link | grep -oE '([[:xdigit:]]{2}:){5}[[:xdigit:]]{2}'