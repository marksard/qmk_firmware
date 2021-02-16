
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#

MOUSEKEY_ENABLE = no        # Mouse keys(+4700)
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = WS2812
OLED_DRIVER_ENABLE = yes
LTO_ENABLE = yes

# If you want to change the display of OLED, you need to change here
SRC += oled_helper.c \
