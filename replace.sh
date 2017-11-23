#!/bin/sh

MAP=$(cat map | sed 's/#/\\x1b[36m\\x1b[46m##\\x1b[37m\\x1b[40m/g' | sed 's/\./\\x1b[30m..\\x1b[37m/g')
echo "${MAP}"
