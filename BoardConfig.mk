# Copyright (C) 2014-2016 The CyanogenMod Project
# Copyright (C) 2017-2018 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common hlte
include device/samsung/hlte-common/BoardConfigCommon.mk

TARGET_OTA_ASSERT_DEVICE := hlte,hltespr,hltexx

# Init
TARGET_INIT_VENDOR_LIB := libinit_msm8974
TARGET_LIBINIT_MSM8974_DEFINES_FILE := device/samsung/hlte/init/init_hlte.cpp

# Kernel
TARGET_KERNEL_CONFIG := mokee_hlte_bcm2079x_defconfig

# NFC
include $(COMMON_PATH)/nfc/bcm2079x/board.mk

# Radio/RIL
include $(COMMON_PATH)/radio/single/board.mk

# Shims
TARGET_LD_SHIM_LIBS += \
    /system/vendor/lib/libsec-ril.gsm.so|libshim_cutils_atomic.so \
    /system/vendor/lib/libsec-ril.spr.so|libshim_cutils_atomic.so

# inherit from the proprietary version
-include vendor/samsung/hlte/BoardConfigVendor.mk
