@@ -1 +1,28 @@
# PID-Tunning
WARNING WARNING WARNING WARNING WARNING WARNING WARNING 
None of the files in this repo has been tested. I have only put them here to gain access to them on a different location.
If I make it work I will add a video link to this file


Once released it will be:

Hardware requirements:
Arduino based self-balancing robot with bluetooth module
Android device with bluetooth (not sure if there are devices without one, but just in case)


Files:

bt.ino - Arduino code inteneded to be added to existing self-balancing code
PIDTunning.aia - MIT App Inventor 2 project for the android device app
PIDTunning.apk - Pre-built app for android device if you don't want to use MIT App Inventor 2 yourself (I recomend you build it yourself for three reasons: 1. MIT App Inventor 2 is a really great project, 2. You can make sure there is no malicious parts of the app, 3. You can change it to better suit your needs)

Usage:

1. Run your self-balancing robot with some default PID values
2. Run app on your android device
3. Connect to robot via bluetooth
4. Note that android device will not show current PID values until at least one value is changed
5. Change the PID values by pressing the buttons
6. Once happy with values, reprogram your robot to use them

This project will not include ways to build or code self-balancing robot, or use arduino bluetooth module, as there is many tutorials to help you with that.
