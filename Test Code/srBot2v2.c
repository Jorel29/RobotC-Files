#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    liftPot,        sensorNone)
#pragma config(Sensor, in2,    goalPot,        sensorPotentiometer)
#pragma config(Sensor, dgtl1,  lDriveEnc,      sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  rDriveEnc,      sensorQuadEncoder)
#pragma config(Motor,  port1,           roller,        tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           rLift,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           lLift,         tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           frDrive,       tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           brDrive,       tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port6,           ylDrive,       tmotorVex393TurboSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port7,           mrDrive,       tmotorVex393TurboSpeed_MC29, openLoop, driveRight)
#pragma config(Motor,  port8,           mlDrive,       tmotorVex393TurboSpeed_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port9,           lGoal,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          rGoal,         tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main() {

	while(true) {
		motor[ylDrive] =
			motor[mlDrive] =
			vexRT[Ch3] + vexRT[Ch1];

		motor[frDrive] =
			motor[mrDrive] =
			motor[brDrive] =
			vexRT[Ch3] - vexRT[Ch1];
			
		if(vexRT[Btn5U] ^ vexRT[Btn5D]) {
			if(vexRT[Btn5U])
				motor[lLift] =
					motor[rLift] =
					127;
			else
				motor[lLift] = 
					motor[rLift] =
					-127;
		}
		else
			motor[lLift] = 
				motor[rLift] =
				0;

		if(vexRT[Btn6U] ^ vexRT[Btn6D]) {
			if(vexRT[Btn6U])
				motor[lGoal] =
					motor[rGoal] =
					127;
			else
				motor[lGoal] = 
					motor[rGoal] =
					-127;
		}
		else
			motor[lGoal] = 
				motor[rGoal] =
				: 0;

				if(vexRT[Btn8U] ^ vexRT[Btn8D]) {
			if(vexRT[Btn8U])
				motor[roller] =
					127;
			else
				motor[roller] =
					-127;
		}
		else
			motor[roller] =
					0;


		wait1Msec(20);
	}

}
