#ifndef MOTOR_DRIVE_H
#define MOTOR_DRIVE_H

void drill_motors_setup();
void drill_up();
void drill_down();
void drill_up_down_stop();

void drill_clockwise();
void drill_anticlockwise();
void drill_rotation_stop();

void actuator_up();
void actuator_down();
void actuator_stop();

void execute_command(const String& token);

#endif