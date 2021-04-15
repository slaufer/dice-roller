#!/bin/bash
BOARD_FQBN="Seeeduino:samd:seeed_XIAO_m0"
COM_PORT="$(arduino-cli board list | grep "$BOARD_FQBN" | cut -f1 -d' ')"

arduino-cli compile -v -b "$BOARD_FQBN" || exit $?
arduino-cli upload -v -b "$BOARD_FQBN" -p "$COM_PORT" || exit $?
