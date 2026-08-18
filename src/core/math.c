#include "wet/math.h"

double dcos(double angle)
{
    return cos(angle * (PI / 180.0));
}

double dsin(double angle)
{
    return sin(angle * (PI / 180.0));
}

double dtan(double angle)
{
    return tan(angle * (PI / 180.0));
}

float format_angle(float angle)
{
    angle = fmodf(angle, 360.0);

    if (angle < 0.0) { angle += 360.0; }

    return angle;
}

float rotate_towards(float angle, float target, float amount)
{
    angle = format_angle(angle);
    target = format_angle(target);

    float diff = target - angle;

    if (diff > 180.0) {
        diff -= 360.0;
    } else if (diff < -180.0) {
        diff += 360.0;
    }

    if (fabsf(diff) <= amount)
    {
        return target;
    }

    if (diff < 0.0) {
        amount = -amount;
    }

    return format_angle(angle + amount);
}