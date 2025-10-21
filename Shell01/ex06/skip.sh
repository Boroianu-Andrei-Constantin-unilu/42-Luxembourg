#!/bin/sh
ls -l | awk 'NR % 2 == 1'