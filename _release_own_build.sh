#!/bin/bash -eu
pwd

# VIA
if [ "$1" = "-all" ] || [ "$1" = "-via" ] || [ "$1" = "-release" ]; then
    qmk compile -kb marksard/leftover30 -km via
    qmk compile -kb marksard/rhymestone -km via
    qmk compile -kb marksard/treadstone32 -km via
    qmk compile -kb marksard/treadstone32/lite -km via
    qmk compile -kb marksard/treadstone48/rev1 -km via
    qmk compile -kb marksard/treadstone48/rev2 -km via
    qmk compile -kb marksard/treadstone60 -km via
fi
# デフォルト
if [ "$1" = "-all" ] || [ "$1" = "-default" ] || [ "$1" = "-release" ]; then
    qmk compile -kb marksard/leftover30 -km default
    qmk compile -kb marksard/rhymestone -km default
    qmk compile -kb marksard/treadstone32 -km default
    qmk compile -kb marksard/treadstone32/lite -km default
    qmk compile -kb marksard/treadstone48/rev1 -km default
    qmk compile -kb marksard/treadstone48/rev2 -km default
    qmk compile -kb marksard/treadstone60 -km default
    #qmk compile -kb marksard/gogofunk -km default
    #qmk compile -kb marksard/stoneaxe -km default
    #qmk compile -kb marksard/stonehenge30 -km like_jis
    qmk compile -kb marksard/treadstone38 -km default
fi
# 他
if [ "$1" = "-all" ] || [ "$1" = "-like_jis" ]; then
    # qmk compile -kb colosseum44 -km like_jis
    qmk compile -kb numatreus -km like_jis
    qmk compile -kb recompile_keys/nomu30 -km like_jis
    qmk compile -kb thevankeyboards/minivan -km like_jis
fi
# 他
if [ "$1" = "-all" ] || [ "$1" = "-marksard" ]; then
    qmk compile -kb marksard/treadstone48/rev1 -km marksard
    qmk compile -kb marksard/treadstone48/rev2 -km marksard
    qmk compile -kb 40percentclub/gherkin -km marksard
    qmk compile -kb 40percentclub/gherkin -km marksard_midi
    qmk compile -kb ai03/equinox -km marksard
    qmk compile -kb ai03/polaris -km marksard
    qmk compile -kb crkbd/rev1 -km marksard
    qmk compile -kb emptystring/NQG -km marksard
    qmk compile -kb kawaii -km marksard
    qmk compile -kb kprepublic/jj40 -km marksard
    qmk compile -kb recompile_keys/nomu30 -km marksard
    qmk compile -kb reviung/reviung33 -km marksard
    qmk compile -kb satt/vision -km marksard
    qmk compile -kb thevankeyboards/minivan -km marksard
fi
# VIAファイル圧縮
if [ "$1" = "-viapack" ]; then
    cp ./keyboards/marksard/treadstone32/keymaps/via/marksard_treadstone32_rev1_lite_via.json ./marksard_treadstone32_rev1_lite_via.json
    cp ./keyboards/marksard/treadstone48/keymaps/via/marksard_treadstone48_rev1_via.json ./marksard_treadstone48_rev1_via.json
    cp ./keyboards/marksard/treadstone48/keymaps/via/marksard_treadstone48_rev2_via.json ./marksard_treadstone48_rev2_via.json
    cp ./keyboards/marksard/leftover30/keymaps/via/marksard_leftover30_via.json ./marksard_leftover30_via.json
    cp ./keyboards/marksard/rhymestone/keymaps/via/marksard_rhymestone_rev1_via.json ./marksard_rhymestone_rev1_via.json
    cp ./keyboards/marksard/treadstone60/keymaps/via/marksard_treadstone60_via.json ./marksard_treadstone60_via.json
    mkdir _release
    zip -r ./_release/marksard_treadstone32_rev1_via.zip ./marksard_treadstone32_rev1_lite_via.json ./marksard_treadstone32_rev1_via.hex
    zip -r ./_release/marksard_treadstone32_lite_via.zip ./marksard_treadstone32_rev1_lite_via.json ./marksard_treadstone32_lite_via.hex
    zip -r ./_release/marksard_treadstone48_rev1_via.zip ./marksard_treadstone48_rev1_via.json ./marksard_treadstone48_rev1_via.hex
    zip -r ./_release/marksard_treadstone48_rev2_via.zip ./marksard_treadstone48_rev2_via.json ./marksard_treadstone48_rev2_via.hex
    zip -r ./_release/marksard_leftover30_via.zip ./marksard_leftover30_via.json ./marksard_leftover30_via.hex
    zip -r ./_release/marksard_rhymestone_rev1_via.zip ./marksard_rhymestone_rev1_via.json ./marksard_rhymestone_rev1_via.hex
    zip -r ./_release/marksard_treadstone60_via.zip ./marksard_treadstone60_via.json ./marksard_treadstone60_via.hex
fi
# ファイルサイズチェック（qmk compile -kbで生成時エラーが出てたような気もするけどciのログ出し用途も兼ねて）
if [ "$1" = "-hexcheck" ] || [ "$1" = "-via" ] || [ "$1" = "-release" ]; then
    for file in `ls *.hex`; do
        filesize=`avr-size --target=ihex $file | awk 'NR==2 {print $4}'`
        oversize=$(($filesize-28672))
        remining=`printf '%5d' $(($oversize*-1))`
        filesizepf=`printf '%5d' $filesize`
        echo -e 'filesize:[' "$filesizepf" ']\tremaining:[' "$remining" ']\tname:[' $file ']'
        if [ $oversize -gt 0 ]; then
            ESC=$(printf '\033')
            echo "${ESC}[31mERROR: $file file was oversize!!!!!!!!!!${ESC}[m"
            exit 1
        fi
    done
fi
