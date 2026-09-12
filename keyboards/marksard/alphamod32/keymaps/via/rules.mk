# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#

# Other selectable option
IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)
VIA_ENABLE = yes

ifeq ($(strip $(IOS_DEVICE_ENABLE)), yes)
    OPT_DEFS += -DIOS_DEVICE_ENABLE
endif
