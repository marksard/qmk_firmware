# JISっぽいキーマップ

## 概要

　記号類がなんとなく日本語JISベースの配置になったキーマップです。  

![img](https://github.com/marksard/Keyboards/raw/master/stonehenge30/documents/_image/like_jis.png)  

## キーマップの見かた

qmk_firmware\tmk_core\common\keycode.h  
に基本的なキーコードがあります。また、Keymap.cの上部にカスタムしたKC_で始まるものを登録しています。  
キーマップに書くときは「KC_」を省略して書いています。
例：KC_A → A  

Leyer Tap、Mod Tap、Tap DanceというQMKの機能を使っています。  

Layer Tapはタップで指定したキー、長押しで指定したレイヤーに移動します。  
例：LT(RAISE, KC_V) → タップでV、長押しでRAISEレイヤー移動

Mod Tapはタップで視程したキー、長押しで視程したレイヤーに移動します。  
例：LSFT_T(KC_Z) → タップでZ、長押しで左シフト

Tap Danceは指定した二つのキーをシングルタップ、ダブルタップで切り替えられます。  
例：[TD_CODO] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_DOT) → シングルタップでCOMM、ダブルタップでDOT

もう少し詳しい内容についてはQMK Documentをお読みいただくかネットを検索すれば情報が載っていますので別途検索してみてください。  

## 単押し、長押しのタイミングを調整したい

config.hの以下のTAPPING_TERMを調整してください。またPREVENT_STUCK_MODIFIERSやIGNORE_MOD_TAP_INTERRUPTについてはググってよく吟味してみてください。  

```h
#define TAPPING_TERM 200
#define PREVENT_STUCK_MODIFIERS

```
