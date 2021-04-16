#!/bin/bash
source ./build.sh
arduino-cli upload -v -b "$BOARD_FQBN" -p "$COM_PORT" || exit $?
