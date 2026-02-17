#include <Arduino.h>
#include <string.h>
#include "motor_drive.h"

const int DRILL_UP = 5;
const int DRILL_DOWN = 6;
const int DRILL_CLOCK = 7;
const int DRILL_ANTI = 8;
const int ACTUATOR_UP = 9;
const int ACTUATOR_DOWN = 10;

void drill_motors_setup()
{
    for (int i = 5; i < 12; i++)
    {
        pinMode(i, OUTPUT);
        digitalWrite(i, HIGH);
    }
}

void drill_down()
{
    digitalWrite(DRILL_UP, HIGH);  // Ensure opposite direction OFF
    digitalWrite(DRILL_DOWN, LOW); // Activate down
}

void drill_up()
{
    digitalWrite(DRILL_DOWN, HIGH); // Ensure opposite direction OFF
    digitalWrite(DRILL_UP, LOW);    // Activate up
}

void drill_up_down_stop()
{
    digitalWrite(DRILL_UP, HIGH);
    digitalWrite(DRILL_DOWN, HIGH);
}

// ---------------- DRILL ROTATION ----------------

void drill_clockwise()
{
    digitalWrite(DRILL_ANTI, HIGH); // Ensure opposite direction OFF
    digitalWrite(DRILL_CLOCK, LOW); // Rotate clockwise
}

void drill_anticlockwise()
{
    digitalWrite(DRILL_CLOCK, HIGH); // Ensure opposite direction OFF
    digitalWrite(DRILL_ANTI, LOW);   // Rotate anti-clockwise
}

void drill_rotation_stop()
{
    digitalWrite(DRILL_CLOCK, HIGH);
    digitalWrite(DRILL_ANTI, HIGH);
}

// ---------------- ACTUATOR CONTROL ----------------

void actuator_up()
{
    digitalWrite(ACTUATOR_DOWN, HIGH); // Ensure opposite OFF
    digitalWrite(ACTUATOR_UP, LOW);    // Move up
}

void actuator_down()
{
    digitalWrite(ACTUATOR_UP, HIGH);  // Ensure opposite OFF
    digitalWrite(ACTUATOR_DOWN, LOW); // Move down
}

void actuator_stop()
{
    digitalWrite(ACTUATOR_UP, HIGH);
    digitalWrite(ACTUATOR_DOWN, HIGH);
}

void execute_command(const String &token)
{
    if (token == "DRILL_UP")
    {
        drill_up();
    }
    else if (token == "DRILL_DOWN")
    {
        drill_down();
    }
    else if (token == "DRILL_UP_DOWN_STOP")
    {
        drill_up_down_stop();
    }
    else if (token == "DRILL_CLOCK")
    {
        drill_clockwise();
    }
    else if (token == "DRILL_ANTI")
    {
        drill_anticlockwise();
    }
    else if (token == "DRILL_ROTATION_STOP")
    {
        drill_rotation_stop();
    }
    else if (token == "ACTUATOR_UP")
    {
        actuator_up();
    }
    else if (token == "ACTUATOR_DOWN")
    {
        actuator_down();
    }
    else if (token == "ACTUATOR_STOP")
    {
        actuator_stop();
    }
    else if (token == "")
    {
        // Empty command → do nothing
    }
}
