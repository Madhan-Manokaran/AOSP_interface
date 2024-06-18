//IFanSpeedControlService.aidl
package android.hardware.fancontroller;

// Declare any non-default types here with import statements


@VintfStability
interface IFanSpeedControlService {

    // Method to increase fan speed
    boolean increaseFanSpeed();

    // Method to decrease fan speed
    boolean decreaseFanSpeed();

    // Method to turn the fan on
    boolean turnFanOn();

    // Method to turn the fan off
    boolean turnFanOff();

    // Method to get the current fan speed
    int getFanSpeed();

    // Method to get the current fan on/off status
    boolean isFanOn();
}
