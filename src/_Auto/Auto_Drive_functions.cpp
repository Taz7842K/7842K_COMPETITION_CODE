#include "main.h"
#include "7842K_Main.h"
#include "_Auto/driveArc.h"

double smallVelocity;
double bigCircDistance;
double smallCircDistance;

int maxVelocity = 200;

void calcArc(double bigCircRadius, double degMove)                                    //bigCircRadius input in inches
{
  double bigCircCircumference = ((bigCircRadius * 2) * pi);                           //360 motor encoder units in one rotation
  double smallCircCircumference = (((bigCircRadius - chassisWidth) * 2)  * pi);

  double bigCircDistance = bigCircCircumference * (degMove/360) /4 * 360;
  double smallCircDistance = smallCircCircumference * (degMove/360) /4 * 360;

  double smallVelocity = (smallCircCircumference/bigCircCircumference) * 200;
}

void driveArcLeft(double bigCircRadius1, double degMove1)
{
  calcArc(bigCircRadius1,degMove1);
  m_frontLeft.moveRelative(smallCircDistance, smallVelocity);
  m_rearLeft.moveRelative(smallCircDistance, smallVelocity);
  m_frontRight.moveRelative(bigCircDistance, 200);
  m_rearRight.moveRelative(bigCircDistance, 200);
}
void driveArcRight(double bigCircRadius2, double degMove2)
{
  calcArc(bigCircRadius2, degMove2);
  m_frontLeft.moveRelative(bigCircDistance, 200);
  m_rearLeft.moveRelative(bigCircDistance, 200);
  m_frontRight.moveRelative(smallCircDistance,smallVelocity);
  m_rearRight.moveRelative(smallCircDistance,smallVelocity);
}

// void threeInchStop()
// {
//   skidBase.setMaxVelocity(75);
//   skidBase.moveDistance(3_in);
//   pros::delay(100);
//   skidBase.setMaxVelocity(maxVelocity);
// }

// void driveDistance(QLength distance)
// {
//   std::valarray<std::int32_t> lastEnc = skidBase.getSensorVals();
//   skidBase.forward(1);
//
//   while(true) {
//     QLength leftDistance = lastEnc[0] - skidBase.getSensorVals()[0] *
//   }
//   double wantedTicks = distance.
// }

void autoNothing(lib7842::autonSides){};
