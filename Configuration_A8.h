/*
* Heat extruder and bed up 
M851 Z0
G28
M211 S0
* Move the nozzle down so it is just gripping a piece of standard printer paper
M114
M851 Z-0.70
M500
M211 S1
*/

 

#ifndef CONFIGURATION_H
#define CONFIGURATION_H
#define CONFIGURATION_H_VERSION 010100

#define MOTHERBOARD BOARD_ANET_10 
 
#define SERIAL_PORT 0
#define BAUDRATE 115200
#define EXTRUDERS 1
#define POWER_SUPPLY 0
#define TEMP_SENSOR_0 5
#define TEMP_SENSOR_1 0
#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_BED 5
#define DUMMY_THERMISTOR_998_VALUE 25
#define DUMMY_THERMISTOR_999_VALUE 100

#define MAX_REDUNDANT_TEMP_SENSOR_DIFF 10

#define TEMP_RESIDENCY_TIME 6  // (seconds)
#define TEMP_HYSTERESIS 3       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_WINDOW     1       // (degC) Window around target to start the residency timer x degC early.

#define TEMP_BED_RESIDENCY_TIME 6  // (seconds)
#define TEMP_BED_HYSTERESIS 3       // (degC) range of +/- temperatures considered "close" to the target one
#define TEMP_BED_WINDOW     1       // (degC) Window around target to start the residency timer x degC early.

#define HEATER_0_MINTEMP 5
#define HEATER_1_MINTEMP 5
#define HEATER_2_MINTEMP 5
#define HEATER_3_MINTEMP 5
#define HEATER_4_MINTEMP 5
#define BED_MINTEMP 5

#define HEATER_0_MAXTEMP 275
#define HEATER_1_MAXTEMP 275
#define HEATER_2_MAXTEMP 275
#define HEATER_3_MAXTEMP 275
#define HEATER_4_MAXTEMP 275
#define BED_MAXTEMP 130

#define PIDTEMP
#define BANG_MAX 255 // limits current to nozzle while in bang-bang mode; 255=full current
#define PID_MAX BANG_MAX // limits current to nozzle while PID is active (see PID_FUNCTIONAL_RANGE below); 255=full current
#if ENABLED(PIDTEMP)
  #define PID_FUNCTIONAL_RANGE 15 // If the temperature difference between the target temperature and the actual temperature
  #define K1 0.95 //smoothing factor within the PID
  // ANET A8 Standard Extruder at 210 Degree Celsius and 100% Fan
  //(measured after M106 S255 with M303 E0 S210 C8)
  #define  DEFAULT_Kp 21.0
  #define  DEFAULT_Ki 1.25
  #define  DEFAULT_Kd 86.0
#endif // PIDTEMP
#define BED_LIMIT_SWITCHING

#define MAX_BED_POWER 255 // limits duty cycle to bed; 255=full current

#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170

#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 200
#define THERMAL_PROTECTION_HOTENDS // Enable thermal protection for all extruders
#define THERMAL_PROTECTION_BED     // Enable thermal protection for the heated bed

#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG

//#define ENDSTOPPULLUPS // Comment this out (using // at the start of the line) to disable the endstop pullup resistors
//
//#if DISABLED(ENDSTOPPULLUPS)
//  // fine endstop settings: Individual pullups. will be ignored if ENDSTOPPULLUPS is defined
//  //#define ENDSTOPPULLUP_XMAX
//  //#define ENDSTOPPULLUP_YMAX
//  //#define ENDSTOPPULLUP_ZMAX
//  //#define ENDSTOPPULLUP_XMIN
//  //#define ENDSTOPPULLUP_YMIN
//  //#define ENDSTOPPULLUP_ZMIN
//  //#define ENDSTOPPULLUP_ZMIN_PROBE
//#endif


// Mechanical endstop with COM to ground and NC to Signal uses "false" here (most common setup).
#define X_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Y_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define Z_MIN_ENDSTOP_INVERTING true // set to true to invert the logic of the endstop.
#define X_MAX_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Y_MAX_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Z_MAX_ENDSTOP_INVERTING false // set to true to invert the logic of the endstop.
#define Z_MIN_PROBE_ENDSTOP_INVERTING true // set to true to invert the logic of the probe.

#define ENDSTOP_INTERRUPTS_FEATURE
#define DEFAULT_AXIS_STEPS_PER_UNIT   {100,  100, 400, 95}
#define DEFAULT_MAX_FEEDRATE          {400, 400, 8, 50}
#define DEFAULT_MAX_ACCELERATION      { 1000, 1000, 100, 5000 }
#define DEFAULT_ACCELERATION          400    // X, Y, Z and E acceleration for printing moves
#define DEFAULT_RETRACT_ACCELERATION  1000    // E acceleration for retracts
#define DEFAULT_TRAVEL_ACCELERATION   400    // X, Y, Z acceleration for travel (non printing) moves
#define DEFAULT_XJERK                 20.0
#define DEFAULT_YJERK                 20.0
#define DEFAULT_ZJERK                  0.3
#define DEFAULT_EJERK                  5.0

#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
#define FIX_MOUNTED_PROBE

#define X_PROBE_OFFSET_FROM_EXTRUDER 18  // X offset: -left  +right  [of the nozzle]
#define Y_PROBE_OFFSET_FROM_EXTRUDER 55  // Y offset: -front +behind [the nozzle]
#define Z_PROBE_OFFSET_FROM_EXTRUDER 0   // Z offset: -below +above  [the nozzle]

#define XY_PROBE_SPEED 6000
#define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z
#define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 2)


#define Z_CLEARANCE_DEPLOY_PROBE   10 // Z Clearance for Deploy/Stow
#define Z_CLEARANCE_BETWEEN_PROBES  5 // Z Clearance between probe points

// For M851 give a range for adjusting the Z probe offset
#define Z_PROBE_OFFSET_RANGE_MIN -20
#define Z_PROBE_OFFSET_RANGE_MAX 20

#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0 // For all extruders

#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

#define DISABLE_E false // For all extruders
#define DISABLE_INACTIVE_EXTRUDER true // Keep only the active extruder enabled.

// Invert the stepper direction. Change (or reverse the motor connector) if an axis goes the wrong way.
#define INVERT_X_DIR false
#define INVERT_Y_DIR false
#define INVERT_Z_DIR true
#define INVERT_E0_DIR false
#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false

#define Z_HOMING_HEIGHT 4  // (in mm) Minimal z height before homing (G28) for Z clearance above the bed, clamps, ...
#define X_HOME_DIR -1
#define Y_HOME_DIR -1
#define Z_HOME_DIR -1

#define X_MAX_POS     220
#define X_MIN_POS     -33
#define Y_MAX_POS     220
#define Y_MIN_POS     -10
#define Z_MAX_POS     230
#define Z_MIN_POS   0
  

#define MIN_SOFTWARE_ENDSTOPS   // NEXT: TRY IT WITH ENABLED
#define MAX_SOFTWARE_ENDSTOPS

#define AUTO_BED_LEVELING_3POINT

#if ENABLED(AUTO_BED_LEVELING_3POINT)
 #define ABL_PROBE_PT_1_X 10
  #define ABL_PROBE_PT_1_Y 180
  #define ABL_PROBE_PT_2_X 10
  #define ABL_PROBE_PT_2_Y 50
  #define ABL_PROBE_PT_3_X 200
  #define ABL_PROBE_PT_3_Y 110
#endif // BED_LEVELING


#define Z_SAFE_HOMING
#if ENABLED(Z_SAFE_HOMING)
  #define Z_SAFE_HOMING_X_POINT (X_MAX_POS / 2)    // X point for Z homing when homing all axis (G28).
  #define Z_SAFE_HOMING_Y_POINT (Y_MAX_POS / 2)    // Y point for Z homing when homing all axis (G28).
#endif

#define HOMING_FEEDRATE_XY (100*60)
#define HOMING_FEEDRATE_Z  (4*60)

#define EEPROM_SETTINGS
#if ENABLED(EEPROM_SETTINGS)
  // To disable EEPROM Serial responses and decrease program space by ~1700 byte: comment this out:
  #define EEPROM_CHITCHAT // Please keep turned on if you can.
#endif

#define HOST_KEEPALIVE_FEATURE        // Disable this if your host doesn't like keepalive messages
#define DEFAULT_KEEPALIVE_INTERVAL 2  // Number of seconds between "busy" messages. Set with M113.
#define BUSY_WHILE_HEATING            // Some hosts require "busy" messages even during heating

#define PREHEAT_1_TEMP_HOTEND 200
#define PREHEAT_1_TEMP_BED     60
#define PREHEAT_1_FAN_SPEED     0 // Value from 0 to 255

#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    95
#define PREHEAT_2_FAN_SPEED     0 // Value from 0 to 255

#define PRINTJOB_TIMER_AUTOSTART
#define LCD_LANGUAGE en
#define DISPLAY_CHARSET_HD44780 JAPANESE
#define SDSUPPORT

// ANET_10 Controller supported displays.
#define ANET_KEYPAD_LCD         // Requires ADC_KEYPAD_PIN to be assigned to an analog pin.
                                  // This LCD is known to be susceptible to electrical interference
                                  // which scrambles the display.  Pressing any button clears it up.
//#define ANET_FULL_GRAPHICS_LCD  // Anet 128x64 full graphics lcd with rotary encoder as used on Anet A6
                                  // A clone of the RepRapDiscount full graphics display but with
                                  // different pins/wiring (see pins_ANET_10.h).

#define SOFT_PWM_SCALE 0
#define SERVO_DELAY { 300 }
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75   // (mm) Diameter of the filament generally used (3.0 or 1.75mm), also used in the slicer. Used to validate sensor reading.
#endif // CONFIGURATION_H
