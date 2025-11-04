#!/bin/sh
ip -brief link | awk '{print $1,$3}'