# Other selectable option
IOS_DEVICE_ENABLE = no      # connect to IOS device (iPad,iPhone)

ifeq ($(strip $(IOS_DEVICE_ENABLE)), yes)
    OPT_DEFS += -DIOS_DEVICE_ENABLE
endif
