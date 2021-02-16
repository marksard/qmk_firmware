#!/bin/bash

if [ "$1" = "-all" ] || [ "$1" = "-via" ] || [ "$1" = "-release" ]; then
    make treadstone32:via
    make treadstone32/lite:via
    make treadstone48/rev1:via
    make treadstone48/rev2:via
    make marksard/leftover30:via
    make marksard/rhymestone:via
    make marksard/treadstone60:via
fi
if [ "$1" = "-all" ] || [ "$1" = "-default" ] || [ "$1" = "-release" ]; then
    #make marksard/gogofunk:default
    make marksard/leftover30:default
    make marksard/rhymestone:default
    #make marksard/stoneaxe:default
    #make marksard/stonehenge30:like_jis
    make marksard/treadstone38:default
    make marksard/treadstone60:default
    make treadstone32:default
    make treadstone32/lite:default
    make treadstone48/rev1:default
    make treadstone48/rev2:default
fi
if [ "$1" = "-all" ] || [ "$1" = "-like_jis" ]; then
    make numatreus:like_jis
    make colosseum44:like_jis
    make jj40:like_jis
fi
if [ "$1" = "-all" ] || [ "$1" = "-marksard" ]; then
    make ai03/equinox:marksard
    make ai03/polaris:marksard
    make crkbd/rev1:marksard
    make emptystring/NQG:marksard
    make nomu30:marksard
    make reviung33/NQG:marksard
    make thevankeyboards/minivan:marksard
    make treadstone48/rev1:marksard
    make treadstone48/rev2:marksard
fi
if [ "$1" = "-relzip" ] ||  [ "$1" = "-release" ]; then
    cp ./keyboards/treadstone32/keymaps/via/treadstone32_rev1_lite_via.json ./treadstone32_rev1_lite_via.json
    cp ./keyboards/treadstone48/keymaps/via/treadstone48_rev1_via.json ./treadstone48_rev1_via.json
    cp ./keyboards/treadstone48/keymaps/via/treadstone48_rev2_via.json ./treadstone48_rev2_via.json
    cp ./keyboards/marksard/leftover30/keymaps/via/marksard_leftover30_via.json ./marksard_leftover30_via.json
    cp ./keyboards/marksard/rhymestone/keymaps/via/marksard_rhymestone_rev1_via.json ./marksard_rhymestone_rev1_via.json
    cp ./keyboards/marksard/treadstone60/keymaps/via/marksard_treadstone60_via.json ./marksard_treadstone60_via.json
    mkdir _release
    zip -r ./_release/treadstone32_rev1_via.zip ./treadstone32_rev1_lite_via.json ./treadstone32_rev1_via.hex
    zip -r ./_release/treadstone32_lite_via.zip ./treadstone32_rev1_lite_via.json ./treadstone32_lite_via.hex
    zip -r ./_release/treadstone48_rev1_via.zip ./treadstone48_rev1_via.json ./treadstone48_rev1_via.hex
    zip -r ./_release/treadstone48_rev2_via.zip ./treadstone48_rev2_via.json ./treadstone48_rev2_via.hex
    zip -r ./_release/marksard_leftover30_via.zip ./marksard_leftover30_via.json ./marksard_leftover30_via.hex
    zip -r ./_release/marksard_rhymestone_rev1_via.zip ./marksard_rhymestone_rev1_via.json ./marksard_rhymestone_rev1_via.hex
    zip -r ./_release/marksard_treadstone60_via.zip ./marksard_treadstone60_via.json ./marksard_treadstone60_via.hex
fi
