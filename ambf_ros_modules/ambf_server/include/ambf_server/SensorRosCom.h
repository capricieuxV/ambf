//==============================================================================
/*
    Software License Agreement (BSD License)
    Copyright (c) 2019-2021, AMBF
    (https://github.com/WPI-AIM/ambf)

    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    * Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

    * Redistributions in binary form must reproduce the above
    copyright notice, this list of conditions and the following
    disclaimer in the documentation and/or other materials provided
    with the distribution.

    * Neither the name of authors nor the names of its contributors may
    be used to endorse or promote products derived from this software
    without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
    COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
    POSSIBILITY OF SUCH DAMAGE.

    \author    <amunawar@wpi.edu>
    \author    Adnan Munawar
*/
//==============================================================================

#ifndef SENSORROSCOM_H
#define SENSORROSCOM_H

#include "ambf_server/RosComBase.h"
#include "ambf_msgs/SensorState.h"
#include "ambf_msgs/SensorCmd.h"
#include "ambf_msgs/ContactSensorState.h"
#include "ambf_msgs/ContactSensorCmd.h"
#include "ambf_msgs/ContactEvent.h"
#include "ambf_msgs/ContactData.h"


template<class T_state, class T_cmd>
class SensorRosComBase: public RosComBase<T_state, T_cmd>{
public:
    SensorRosComBase(std::string a_name, std::string a_namespace, int a_freq_min, int a_freq_max, double time_out);
    virtual void init(){}

protected:
    virtual void reset_cmd(){}
};

class SensorRosCom: public SensorRosComBase<ambf_msgs::SensorState, ambf_msgs::SensorCmd>{
public:
    SensorRosCom(std::string a_name, std::string a_namespace, int a_freq_min, int a_freq_max, double time_out);
    virtual void init();

protected:
    virtual void reset_cmd();
    void sub_cb(ambf_msgs::SensorCmdConstPtr msg);
};

class ContactSensorRosCom: public SensorRosComBase<ambf_msgs::ContactSensorState, ambf_msgs::ContactSensorCmd>{
public:
    ContactSensorRosCom(std::string a_name, std::string a_namespace, int a_freq_min, int a_freq_max, double time_out);
    virtual void init();

protected:
    virtual void reset_cmd();
    void sub_cb(ambf_msgs::ContactSensorCmdConstPtr msg);
};


#endif
