/* 
* LSM9DS0.h
*
* Created: 2/21/2016 10:46:37 AM
* Author: Brandon
*/


#ifndef __LSM9DS0_H__
#define __LSM9DS0_H__

#include "../libraries.h"

#define LSM9DS0_ADDRESS_ACCELMAG    (0x1D)         // 3B >> 1 = 7bit default
#define LSM9DS0_ADDRESS_GYRO        (0x6B)         // D6 >> 1 = 7bit default
#define LSM9DS0_XM_ID               (0x49)
#define LSM9DS0_G_ID                (0xD4)

// Linear Acceleration: mg per LSB
#define LSM9DS0_ACCEL_MG_LSB_2G		(0.061F)
#define LSM9DS0_ACCEL_MG_LSB_4G		(0.122F)
#define LSM9DS0_ACCEL_MG_LSB_6G		(0.183F)
#define LSM9DS0_ACCEL_MG_LSB_8G		(0.244F)
#define LSM9DS0_ACCEL_MG_LSB_16G	(0.732F) // Is this right? Was expecting 0.488F

// Magnetic Field Strength: gauss range
#define LSM9DS0_MAG_MGAUSS_2GAUSS   (0.08F)
#define LSM9DS0_MAG_MGAUSS_4GAUSS   (0.16F)
#define LSM9DS0_MAG_MGAUSS_8GAUSS   (0.32F)
#define LSM9DS0_MAG_MGAUSS_12GAUSS  (0.48F)

// Angular Rate: dps per LSB
#define LSM9DS0_GYRO_DPS_DIGIT_245DPS      (0.00875F)
#define LSM9DS0_GYRO_DPS_DIGIT_500DPS      (0.01750F)
#define LSM9DS0_GYRO_DPS_DIGIT_2000DPS     (0.07000F)

// Temperature: LSB per degree celsius
#define LSM9DS0_TEMP_LSB_DEGREE_CELSIUS    (8)  // 1�C = 8, 25� = 200, etc.

#define GYROTYPE                           (true)
#define XMTYPE                             (false)

class LSM9DS0
{
public:
	LSM9DS0(int32_t sensorID = 0);
	LSM9DS0(TwoWireClass *wireBus, int32_t sensorID = 0);
	
	void initI2C(TwoWireClass *wireBus, int32_t sensorID);

/** Gyroscope Registers*/
	typedef enum
	{
		LSM9DS0_REGISTER_WHO_AM_I_G          = 0x0F,
		LSM9DS0_REGISTER_CTRL_REG1_G         = 0x20,
		LSM9DS0_REGISTER_CTRL_REG3_G         = 0x22,
		LSM9DS0_REGISTER_CTRL_REG4_G         = 0x23,
		LSM9DS0_REGISTER_OUT_X_L_G           = 0x28,
		LSM9DS0_REGISTER_OUT_X_H_G           = 0x29,
		LSM9DS0_REGISTER_OUT_Y_L_G           = 0x2A,
		LSM9DS0_REGISTER_OUT_Y_H_G           = 0x2B,
		LSM9DS0_REGISTER_OUT_Z_L_G           = 0x2C,
		LSM9DS0_REGISTER_OUT_Z_H_G           = 0x2D,
	} lsm9ds0GyroRegisters;

/** Magnetometer and Accelerometer Registers*/
	typedef enum
	{
		LSM9DS0_REGISTER_TEMP_OUT_L_XM       = 0x05,
		LSM9DS0_REGISTER_TEMP_OUT_H_XM       = 0x06,
		LSM9DS0_REGISTER_STATUS_REG_M        = 0x07,
		LSM9DS0_REGISTER_OUT_X_L_M           = 0x08,
		LSM9DS0_REGISTER_OUT_X_H_M           = 0x09,
		LSM9DS0_REGISTER_OUT_Y_L_M           = 0x0A,
		LSM9DS0_REGISTER_OUT_Y_H_M           = 0x0B,
		LSM9DS0_REGISTER_OUT_Z_L_M           = 0x0C,
		LSM9DS0_REGISTER_OUT_Z_H_M           = 0x0D,
		LSM9DS0_REGISTER_WHO_AM_I_XM         = 0x0F,
		LSM9DS0_REGISTER_INT_CTRL_REG_M      = 0x12,
		LSM9DS0_REGISTER_INT_SRC_REG_M       = 0x13,
		LSM9DS0_REGISTER_CTRL_REG1_XM        = 0x20,
		LSM9DS0_REGISTER_CTRL_REG2_XM        = 0x21,
		LSM9DS0_REGISTER_CTRL_REG5_XM        = 0x24,
		LSM9DS0_REGISTER_CTRL_REG6_XM        = 0x25,
		LSM9DS0_REGISTER_CTRL_REG7_XM        = 0x26,
		LSM9DS0_REGISTER_OUT_X_L_A           = 0x28,
		LSM9DS0_REGISTER_OUT_X_H_A           = 0x29,
		LSM9DS0_REGISTER_OUT_Y_L_A           = 0x2A,
		LSM9DS0_REGISTER_OUT_Y_H_A           = 0x2B,
		LSM9DS0_REGISTER_OUT_Z_L_A           = 0x2C,
		LSM9DS0_REGISTER_OUT_Z_H_A           = 0x2D,
	} lsm9ds0MagAccelRegisters;

/** Accelerometer Range*/
	typedef enum
	{
		LSM9DS0_ACCELRANGE_2G                = (0b000 << 3),
		LSM9DS0_ACCELRANGE_4G                = (0b001 << 3),
		LSM9DS0_ACCELRANGE_6G                = (0b010 << 3),
		LSM9DS0_ACCELRANGE_8G                = (0b011 << 3),
		LSM9DS0_ACCELRANGE_16G               = (0b100 << 3)
	} lsm9ds0AccelRange;
	
/** Accelerometer Data Rate*/
	typedef enum
	{
		LSM9DS0_ACCELDATARATE_POWERDOWN      = (0b0000 << 4),
		LSM9DS0_ACCELDATARATE_3_125HZ        = (0b0001 << 4),
		LSM9DS0_ACCELDATARATE_6_25HZ         = (0b0010 << 4),
		LSM9DS0_ACCELDATARATE_12_5HZ         = (0b0011 << 4),
		LSM9DS0_ACCELDATARATE_25HZ           = (0b0100 << 4),
		LSM9DS0_ACCELDATARATE_50HZ           = (0b0101 << 4),
		LSM9DS0_ACCELDATARATE_100HZ          = (0b0110 << 4),
		LSM9DS0_ACCELDATARATE_200HZ          = (0b0111 << 4),
		LSM9DS0_ACCELDATARATE_400HZ          = (0b1000 << 4),
		LSM9DS0_ACCELDATARATE_800HZ          = (0b1001 << 4),
		LSM9DS0_ACCELDATARATE_1600HZ         = (0b1010 << 4)
	} lm9ds0AccelDataRate;

/** Magnetometer Gain*/
	typedef enum
	{
		LSM9DS0_MAGGAIN_2GAUSS               = (0b00 << 5),  // +/- 2 gauss
		LSM9DS0_MAGGAIN_4GAUSS               = (0b01 << 5),  // +/- 4 gauss
		LSM9DS0_MAGGAIN_8GAUSS               = (0b10 << 5),  // +/- 8 gauss
		LSM9DS0_MAGGAIN_12GAUSS              = (0b11 << 5)   // +/- 12 gauss
	} lsm9ds0MagGain;

/** Magnetometer Data Rate*/
	typedef enum
	{
		LSM9DS0_MAGDATARATE_3_125HZ          = (0b000 << 2),
		LSM9DS0_MAGDATARATE_6_25HZ           = (0b001 << 2),
		LSM9DS0_MAGDATARATE_12_5HZ           = (0b010 << 2),
		LSM9DS0_MAGDATARATE_25HZ             = (0b011 << 2),
		LSM9DS0_MAGDATARATE_50HZ             = (0b100 << 2),
		LSM9DS0_MAGDATARATE_100HZ            = (0b101 << 2)
	} lsm9ds0MagDataRate;

/** Gyroscope Scale*/
	typedef enum
	{
		LSM9DS0_GYROSCALE_245DPS             = (0b00 << 4),  // +/- 245 degrees per second rotation
		LSM9DS0_GYROSCALE_500DPS             = (0b01 << 4),  // +/- 500 degrees per second rotation
		LSM9DS0_GYROSCALE_2000DPS            = (0b10 << 4)   // +/- 2000 degrees per second rotation
	} lsm9ds0GyroScale;

/** 4D Vector Container*/
	typedef struct vector_s
	{
		float x;
		float y;
		float z;
		float t;
	} vector;
	
	vector accelData;
	vector magData;
	vector gyroData;
	int16_t temperatureData;
	
	bool	begin		(void);
	void	read		(void);
	void	readAccel	(void);
	void	readMag		(void);
	void	readGyro	(void);
	void	readTemp	(void);
	void	setupAccel	(lsm9ds0AccelRange range);
	void	setupMag	(lsm9ds0MagGain gain);
	void	setupGyro	(lsm9ds0GyroScale scale);
	
	
//private:

/** Saved Variables*/
	TwoWireClass *_wireBus;
	int32_t sensorID_Accel;
	int32_t sensorID_Mag;
	int32_t sensorID_Gyro;
	int32_t sensorID_Temp;

	void	write8			(bool type, uint8_t reg, uint8_t value);
	uint8_t read8			(bool type, uint8_t reg);
	uint8_t readIntoBuffer	(bool type, uint8_t reg, uint8_t len);
	
	RingBufferClass rxBuffer;
	
}; //LSM9DS0

#endif //__LSM9DS0_H__
