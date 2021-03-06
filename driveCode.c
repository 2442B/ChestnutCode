#pragma config(Motor,  port2,           rightDriveFront, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightDriveBack, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftDriveFront, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftDriveBack, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           claw2,         tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void setClawPower(int power)
{
	motor[claw] = power;
	motor[claw2] = power;
}

void setLeftMotors(int power)
{
	motor[leftDriveFront] = power;
	motor[leftDriveBack] = power;
}
void setRightMotors(int power)
{
	motor[rightDriveFront] = power;
	motor[rightDriveBack] = power;
}

task main()
{

	while(true)
	{

	int rightJoy = vexRT[Ch2];
	int leftJoy  = vexRT[Ch3];
	word rightTriggerUp = vexRT[Btn6U];
	word rightTriggerDown = vexRT[Btn6D];
		if(fabs(rightJoy) >= 15)
			setRightMotors(rightJoy);
		else
			setRightMotors(0);

		if(fabs(leftJoy) >= 15)
			setLeftMotors(leftJoy);
		else
			setLeftMotors(0);

		if(rightTriggerUp == 1)
		{
			setClawPower(63);
		}
		else if(rightTriggerDown == 1)
		{
			setClawPower(-63);
		}
		else
			setClawPower(0);
	}


}
