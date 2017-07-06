/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include <cutils/properties.h>
#include "vendor_init.h"
#include "log.h"
#include "util.h"

#include "init_msm8974.h"

void gsm_properties()
{
    property_set("ro.telephony.default_network", "9");
    property_set("telephony.lteOnGsmDevice", "1");
}

#define ISMATCH(a, b) (!strncmp((a), (b), PROP_VALUE_MAX))

void init_target_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform, NULL);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader, NULL);

    if (strstr(bootloader, "N900S")) {
        /* hlteskt */
        property_override("ro.build.fingerprint", "samsung/hlteskt/hlte:4.4.2/KOT49H/N900SKSUFNH4:user/release-keys");
        property_override("ro.build.description", "hlteskt-user 4.4.2 KOT49H N900SKSUFNH4 release-keys");
        property_override("ro.product.model", "SM-N900S");
        property_override("ro.product.device", "hlteskt");
        gsm_properties();
    } else if (strstr(bootloader, "N900K")) {
        /* hltektt */
        property_override("ro.build.fingerprint", "samsung/hltektt/hlte:4.4.2/KOT49H/N900KKKUFNI1:user/release-keys");
        property_override("ro.build.description", "hltektt-user 4.4.2 KOT49H N900KKKUFNI1 release-keys");
        property_override("ro.product.model", "SM-N900K");
        property_override("ro.product.device", "hltektt");
        gsm_properties();
    } else {
        /* hltexx */
        property_override("ro.build.fingerprint", "samsung/hltexx/hlte:4.4.2/KOT49H/N9005XXUENC2:user/release-keys");
        property_override("ro.build.description", "hltexx-user 4.4.2 KOT49H N9005XXUENC2 release-keys");
        property_override("ro.product.model", "SM-N9005");
        property_override("ro.product.device", "hltexx");
        gsm_properties();
    }

    property_get("ro.product.device", device, NULL);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}
