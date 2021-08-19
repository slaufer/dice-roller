#!/bin/bash
BOARD_FQBN="Seeeduino:samd:seeed_XIAO_m0"
COM_PORT="$(arduino-cli board list | grep "$BOARD_FQBN" | cut -f1 -d' ')"

buildno=$(($(cat buildno) + 1))

cd src
cat > buildno.h <<EOF
#ifndef _BUILDNO_H
#define _BUILDNO_H

#define BUILDNO $buildno

#endif
EOF

cd -

arduino-cli compile -v -b "$BOARD_FQBN" || exit $?

# don't update buildno if the build or upload failed
echo $buildno > buildno
