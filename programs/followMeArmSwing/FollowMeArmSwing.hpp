// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __FOLLOW_ME_ARM_SWING_HPP__
#define __FOLLOW_ME_ARM_SWING_HPP__

#include <yarp/os/all.h>
#include <yarp/dev/all.h>

#define DEFAULT_ROBOT "/teo"

#define VOCAB_FOLLOW_ME VOCAB4('f','o','l','l')

#define VOCAB_STATE_SALUTE VOCAB4('s','a','l','u')
#define VOCAB_STATE_ARM_SWINGING VOCAB4('s','w','i','n')

namespace teo
{

class FollowMeArmSwing : public yarp::os::RFModule, public yarp::os::PortReader
{
public:
     virtual bool configure(yarp::os::ResourceFinder &rf);
private:
     /** RFModule interruptModule. */
     virtual bool interruptModule();
     /** RFModule getPeriod. */
     virtual double getPeriod();
     /** RFModule updateModule. */
     virtual bool updateModule();

     /** Left Arm Device */
     yarp::dev::PolyDriver leftArmDevice;
     /** Left Arm Position Interface */
     yarp::dev::IPositionControl *leftArmPos;

     /** Right Arm Device */
     yarp::dev::PolyDriver rightArmDevice;
     /** Right Arm Position Interface */
     yarp::dev::IPositionControl *rightArmPos;

     /** Phase of arm swing movement */
     bool phase;

     /** State */
     int state;

     /** Input port from speech recognition */
     yarp::os::Port inSrPort;
     /** Treats data received from input port from speech recognition */
     virtual bool read(yarp::os::ConnectionReader& connection);

};

}  // namespace teo

#endif  // __FOLLOW_ME_ARM_SWING_HPP__