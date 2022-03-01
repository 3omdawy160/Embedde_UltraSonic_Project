# Embedde_UltraSonic_Project

This is an Embedded field related project, which is done by the Layered model and drivers,

This is a FAN Controller which is made by a DC-Motor(FAN), L293D(for serving the required voltage need for the dc-motor), LCD, LM35(Temperature Sensor), Oscilloscope(to show the input signal to the motor and coming out from the microcontroller) and controlled by an AVR ATMEGA16 microcontroller,

This Project is consisted of the following drivers: ADC , LCD , DC-Motor , GPIO , LM35 , PWM and (std_types and common macros) libraries,

The idea is that, the temperature read by the temp.sensor and it's an input to the microcontroller (through the an ADC pin), then it's displayed on the LCD, and also according to this temperature and action is taken to the motor (FAN) to turn it off or on and giving it a certain speed (through the pwm) and this signal (given by the pwm is displayed by the osciloscope),

And for the simulation on proteus, follow this link: https://drive.google.com/drive/folders/1u6G0P6PbwFsblB0fmJ0j99kfTsYpbDUc?usp=sharing
