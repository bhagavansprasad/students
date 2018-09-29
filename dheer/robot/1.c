#define SENSOR_BASE_VALUE 200
#define LEFT_SENSOR  A0
#define RIGHT_SENSOR A1
#define ENABLE_R_MOTOR 3
#define ENABLE_L_MOTOR 9
#define R_MOTOR_1 7
#define R_MOTOR_2 8
#define L_MOTOR_1 10
#define L_MOTOR_2 11

#define FORWARD		1
#define BACKWARD 	2
#define LEFT		3
#define RIGHT		4
#define STOP		5

typedef struct pin_modes_t
{
	int type;
	int in_or_out;
}pin_mode_values;

pin_mode_values pm_values[] = {
	{ENABLE_R_MOTOR, OUTPUT},
	{R_MOTOR_1,      OUTPUT},
	{R_MOTOR_2,      OUTPUT},
	{RIGHT_SENSOR,   INPUT },

	{ENABLE_L_MOTOR, OUTPUT},
	{L_MOTOR_1,      OUTPUT},
	{L_MOTOR_2,      OUTPUT},
	{LEFT_SENSOR,    INPUT}
};

void setup() 
{
	for (i = 0; i < sizeof(pm_values)/sizeof(pin_mode_values); i++)
	{
		pinMode(pm_values[i].type, pm_values[i].in_or_out);
	}
	Serial.begin(9600);
}

int get_analog_sensor_data(int sensor)
{
	return analogRead(sensor);
}

int set_analog_sensor_data(int sensor, int value)
{
	return analogWrite(sensor, value);
}


void dump_data(char *str, int data)
{
	Serial.println(str, data)
}

int set_digital_motor(int motor, int value)
{
	digitalWrite(motor, value);
}

typedef struct dev_movement_directions
{
	int direction;
	int lm1;
	int lm2;
	int rm1;
	int rm2;
	int lspeed;
	int rspeed;
}dev_movement;

/*
			lm1	lm2	rm1	rm2	lmt	rmt
forward		H	L	H	L	255	255
backward	L	H	L	H	255	255
left		L	L	H	L	0	255
right		H	L	L	L	255	0
stop		L	L	L	L	0	0
*/


dev_movement directions[] = 
{
	{FORWARD,	HIGH,	LOW,	HIGH,	LOW,	255,	255},
	{BACKWARD,	LOW,	HIGH,	LOW,	HIGH,	255,	255},
	{LEFT,		LOW,	LOW,	HIGH,	LOW,	0,		255},
	{RIGHT,		HIGH,	LOW,	LOW,	LOW,	255,	0},  
	{STOP,		LOW,	LOW,	LOW,	LOW,	0,		0}   
};

int set_motor_movement(device_movement dire)
{
	set_digital_motor(L_MOTOR_1, dire.lm1);
	set_digital_motor(L_MOTOR_2, dire.lm2);
	set_analog_sensor_data(ENABLE_L_MOTOR, dire.lspeed);

	set_digital_motor(R_MOTOR_1, dire.rm1);
	set_digital_motor(R_MOTOR_2, dire.rm2);
	set_analog_sensor_data(ENABLE_R_MOTOR, dire.rspeed);
}

int set_device_direction(direction)
{
	for (i = 0; i < sizeof(directions)/sizeof(dev_movement); i++)
		if (directions[i].direction == direction)
			set_motor_movement(directions[i]);

}

#if 0
int set_device_forward()
{
	//Forward or Backward
	set_digital_motor(L_MOTOR_1, HIGH);
	set_digital_motor(L_MOTOR_2, LOW);
	set_analog_sensor_data(ENABLE_L_MOTOR, 255);

	set_digital_motor(R_MOTOR_1, HIGH);
	set_digital_motor(R_MOTOR_2, LOW);
	set_analog_sensor_data(ENABLE_R_MOTOR, 255);
}

int set_device_backward()
{
	set_digital_motor(L_MOTOR_1, LOW);
	set_digital_motor(L_MOTOR_2, HIGH);
	set_analog_sensor_data(ENABLE_L_MOTOR, 255);

	set_digital_motor(R_MOTOR_1, LOW);
	set_digital_motor(R_MOTOR_2, HIGH);
	set_analog_sensor_data(ENABLE_R_MOTOR, 255);
}

int set_device_turn_right()
{
	//right
	digitalWrite(L_MOTOR_1,HIGH);
	set_digital_motor(L_MOTOR_2,LOW);
	set_analog_sensor_data(ENABLE_L_MOTOR,255);
	set_digital_motor(R_MOTOR_1,LOW);
	set_digital_motor(R_MOTOR_2,LOW);
	set_analog_sensor_data(ENABLE_R_MOTOR,255);
}

int set_device_turn_left()
{
	//left
	set_digital_motor(R_MOTOR_1,HIGH);
	set_digital_motor(R_MOTOR_2,LOW);
	set_analog_sensor_data(ENABLE_R_MOTOR, 255);
	set_digital_motor(L_MOTOR_1,LOW);
	set_digital_motor(L_MOTOR_2,LOW);
	set_analog_sensor_data(ENABLE_L_MOTOR, 255);
}

int set_device_stop()
{
	//stop
	set_digital_motor(L_MOTOR_1,HIGH);
	set_digital_motor(R_MOTOR_1,LOW);
	set_digital_motor(R_MOTOR_2,LOW);
	set_analog_sensor_data(ENABLE_R_MOTOR,0);
	set_digital_motor(L_MOTOR_1,LOW);
	set_digital_motor(L_MOTOR_2,LOW);
	set_analog_sensor_data(ENABLE_L_MOTOR,0);
}
#endif

int process_sensor_data(int l_snr, int r_snr)
{
	if(l_snr > SENSOR_BASE_VALUE && r_snr > SENSOR_BASE_VALUE)
		set_device_forward();
		set_device_direction(FORWARD);

	if(l_snr < SENSOR_BASE_VALUE && r_snr < SENSOR_BASE_VALUE)
		set_device_backward();
		set_device_direction(BACKWARD);

	if (l_snr > SENSOR_BASE_VALUE)
		set_device_trun_left();
		set_device_direction(LEFT);

	if(r_snr >SENSOR_BASE_VALUE)
		set_device_trun_right();
		set_device_direction(RIGHT);

	if (l_snr<SENSOR_BASE_VALUE && r_snr <SENSOR_BASE_VALUE)
		set_device_direction(STOP);
		set_device_stop();
}

void loop() 
{
	int lsensor = LEFT_SENSOR;
	int rsensor = RIGHT_SENSOR;

	lsensor=get_analog_sensor_data(LEFT_SENSOR); 
	rsensor=get_analog_sensor_data(RIGHT_SENSOR); 

	dump_data("Left  sensor", lsensor);
	dump_data("Right sensor", rsensor);

	process_sensor_data(lsensor, rsensor);
}

