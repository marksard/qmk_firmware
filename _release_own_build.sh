#!/bin/bash -eu

# VIA
if [ "$1" = "-all" ] || [ "$1" = "-via" ] || [ "$1" = "-release" ]; then
    make treadstone32:via
    make treadstone32/lite:via
    make treadstone48/rev1:via
    make treadstone48/rev2:via
    make marksard/leftover30:via
    make marksard/rhymestone:via
    make marksard/treadstone60:via
fi
# デフォルト
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
# 他
if [ "$1" = "-all" ] || [ "$1" = "-like_jis" ]; then
    make numatreus:like_jis
    make colosseum44:like_jis
    make jj40:like_jis
fi
# 他
if [ "$1" = "-all" ] || [ "$1" = "-marksard" ]; then
    make ai03/equinox:marksard
    make ai03/polaris:marksard
    make crkbd/rev1:marksard
    make emptystring/NQG:marksard
    make nomu30:marksard
    make reviung33:marksard
    make thevankeyboards/minivan:marksard
    make treadstone48/rev1:marksard
    make treadstone48/rev2:marksard
fi
# VIAファイル圧縮
if [ "$1" = "-viapack" ]; then
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
# ファイルサイズチェック（makeで生成時エラーが出てたような気もするけどciのログ出し用途も兼ねて）
if [ "$1" = "-hexcheck" ] || [ "$1" = "-via" ] || [ "$1" = "-release" ]; then
    for file in `ls *.hex`; do
        filesize=`avr-size --target=ihex $file | awk 'NR==2 {print $4}'`
        oversize=$(($filesize-28672))
        echo -e 'size:[' $filesize ']\tover:[' $oversize ']\tname:[' $file ']'
        if [ $oversize -gt 0 ]; then
            ESC=$(printf '\033')
            echo "${ESC}[31mERROR: $file file was oversize!!!!!!!!!!${ESC}[m"
            exit 1
        fi
    done
fi
