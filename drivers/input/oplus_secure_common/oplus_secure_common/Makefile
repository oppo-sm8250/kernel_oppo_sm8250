DEFS_PLATFORM = -DCONFIG_OPLUS_BSP_SECCOM_PLATFORM=8250

ifneq ($(TARGET_PRODUCT),qssi)
ccflags-y += $(DEFS_PLATFORM)
obj-y     +=  oplus_secure_common.o
endif

