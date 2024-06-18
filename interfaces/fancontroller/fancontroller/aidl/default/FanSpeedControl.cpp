#define LOG_TAG "FanSpeedControl"

#include <utils/Log.h>
#include <iostream>
#include <fstream>
#include "FanSpeedControl.h"

namespace aidl {
    namespace android {
        namespace hardware {
            namespace fancontroller {
                ndk::ScopedAStatus FanSpeedControl::turnFanOnHAL() {
                    if(!isFanOn){
                        isFanOn = true;
                        ALOGD("Fan turned ON");
                        return ndk::ScopedAStatus::ok();
                    }
                    ALOGE("Fan is already ON");
                    return ndk::ScopedAStatus::fromServiceSpecificError(1,"Failed: Fan is already ON");
                }
                ndk::ScopedAStatus FanSpeedControl::turnFanOffHal() {
                    if(isFanOn){
                        isFanOn = false;
                        ALOGD("Fan turned OFF");
                        return ndk::ScopedAStatus::ok();
                    }
                    ALOGE("Fan is already OFF");
                    return ndk::ScopedAStatus::fromServiceSpecificError(2,"Failed: Fan is already OFF");
                }
                ndk::ScopedAStatus FanSpeedControl::isFanOnHal() {
                    if (isFanOn){
                        ALOGD("Fan is ON");
                        return ndk::ScopedAStatus::ok();
                    }
                    ALOGE("Fan is OFF");
                    return ndk::ScopedAStatus::fromServiceSpecificError(3,"Fan is OFF");
                }
                ndk::ScopedAStatus FanSpeedControl::increaseFanSpeedHAL() {
                    if(fanSpeed <5){
                        fanSpeed++;
                        ALOGD("Increased Fan Speed");
                        return ndk::ScopedAStatus::ok();
                    }
                    ALOGE("Fan Speed is already at maximum");
                    return ndk::ScopedAStatus::fromServiceSpecificError(4,"Failed to Increase: Fan Speed is already at maximum");
                }
                ndk::ScopedAStatus FanSpeedControl::decreaseFanSpeedHAL() {
                    if(fanSpeed >= 0){
                        fanSpeed--;
                        ALOGD("Decreased Fan Speed");
                        return ndk::ScopedAStatus::ok();
                    }
                    ALOGE("Fan Speed is already at minimum");
                    return ndk::ScopedAStatus::fromServiceSpecificError(5,"Failed to Decrease: Fan Speed is already at minimum");
                }
                int FanSpeedControl::getFanSpeedHal() {
                    if(isFanOn){
                        return fanSpeed;
                    }
                    return -1;
                }
            }
        }
    }
}