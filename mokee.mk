$(call inherit-product, device/samsung/hlte/full_hlte.mk)

# Inherit some common MK stuff.
$(call inherit-product, vendor/mk/config/common_full_phone.mk)

PRODUCT_DEVICE := hlte
PRODUCT_NAME := mk_hlte
