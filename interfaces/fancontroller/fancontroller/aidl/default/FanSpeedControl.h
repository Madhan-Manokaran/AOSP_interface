#pragma once
#include "aidl/android/hardware/fancontroller/BnFanSpeedControl.h"
namespace aidl{
    namespace android{
        namespace hardware {
            namespace fanspeedcontrol{
                class FanSpeedControl : public BnFanSpeedControl{
                public:
                    int fanSpeed=0;
                    bool isFanOn = false;

                    ndk::ScopedAStatus increaseFanSpeedHAL();
                    ndk::ScopedAStatus decreaseFanSpeedHAL();
                    ndk::ScopedAStatus turnFanOnHAL();
                    ndk::ScopedAStatus turnFanOffHal();
                    ndk::ScopedAStatus isFanOnHal();
                    int getFanSpeedHal();
                };
            }
        }
    }
}