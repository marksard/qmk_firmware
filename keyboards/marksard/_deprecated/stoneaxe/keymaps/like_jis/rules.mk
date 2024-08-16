
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
TAP_DANCE_ENABLE = yes

# Other selectable option
IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)

ifeq ($(strip $(IOS_DEVICE_ENABLE)), yes)
    OPT_DEFS += -DIOS_DEVICE_ENABLE
endif

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend
