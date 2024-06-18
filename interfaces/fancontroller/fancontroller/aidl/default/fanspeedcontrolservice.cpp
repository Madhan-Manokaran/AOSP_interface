#define LOG_TAG "FanSpeedControl"

#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include "FanSpeedControl.h"

using aidl::android::hardware::fancontroller::FanSpeedControl;
using std::string_literals::operator""s;

void logd(std::string msg) {
    std::cout << msg << std::endl;
    ALOGD("%s", msg.c_str());
}

void loge(std::string msg) {
    std::cout << msg << std::endl;
    ALOGE("%s", msg.c_str());
}

int main() {
    // Enable vndbinder to allow vendor-to-venfor binder call
    android::ProcessState::initWithDriver("/dev/vndbinder");

    ABinderProcess_setThreadPoolMaxThreadCount(0);
    ABinderProcess_startThreadPool();

    std::shared_ptr<FanSpeedControl> fanspeedcontrol = ndk::SharedRefBase::make<FanSpeedControl>();
    const std::string name = FanSpeedControl::descriptor + "/default"s;

    if (fanspeedcontrol != nullptr) {
        if(AServiceManager_addService(fanspeedcontrol->asBinder().get(), name.c_str()) != STATUS_OK) {
            loge("Failed to register IFanSpeedControl service");
            return -1;
        }
    } else {
        loge("Failed to get IFanSpeedControl instance");
        return -1;
    }

    logd("IFanSpeedControl service starts to join service pool");
    ABinderProcess_joinThreadPool();

    return EXIT_FAILURE;  // should not reached
}