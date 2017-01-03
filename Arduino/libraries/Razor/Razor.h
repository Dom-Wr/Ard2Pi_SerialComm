#include "Arduino.h"
//#include "Navigator.h"
#include "Wire.h"

#define HW__VERSION_CODE 10724 // SparkFun "9DOF Sensor Stick" version "SEN-10724" (HMC5883L magnetometer)

// Sensor data output interval in milliseconds
// This may not work, if faster than 20ms (=50Hz)
// Code is tuned for 20ms, so better leave it like that
#define OUTPUT__DATA_INTERVAL 20  // in milliseconds

#define OUTPUT__FORMAT_TEXT 0 // Outputs data as text
#define OUTPUT__MODE_ANGLES 1 // Outputs yaw/pitch/roll in degrees
#define CALIBRATION__MAGN_USE_EXTENDED true

#ifndef RAZOR_HH
#define RAZOR_HH

const float magn_ellipsoid_center[3] = {168.647, 210.785, 108.989};
const float magn_ellipsoid_transform[3][3] = {{0.806619, -0.0115270, -0.0105417},
                                              {-0.0115270, 0.845341, 0.00713515},
                                              {-0.0105417, 0.00713515, 0.999034}};


class Razor
{
  public:
    Razor();
    void Razor_Init();
    double getHeading();
    void I2C_Init();
    void Magn_Init();
    void Read_Magn();
    void compensate_sensor_errors();
    void Compass_Heading();
  private:
    double heading;
    //Navigator& navigator;
    int num_magn_errors = 0;
    float magnetom[3];
    float magnetom_tmp[3];
    float MAG_Heading;
    float yaw;
    float pitch;
    float roll;

    // DCM timing in the main loop
    unsigned long timestamp;
    unsigned long timestamp_old;
    float G_Dt; // Integration time for DCM algorithm
    
    // Select your startup output mode and format here!   
    int output_mode = OUTPUT__MODE_ANGLES;
    int output_format = OUTPUT__FORMAT_TEXT;
    
    // If set true, an error message will be output if we fail to read sensor data.
    // Message format: "!ERR: reading <sensor>", followed by "\r\n".
    boolean output_errors = false;  // true or false
    
    boolean output_single_on;
};

#endif RAZOR_HH
