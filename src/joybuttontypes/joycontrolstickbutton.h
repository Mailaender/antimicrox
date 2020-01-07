/* antimicroX Gamepad to KB+M event mapper
 * Copyright (C) 2015 Travis Nickles <nickles.travis@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#ifndef JOYCONTROLSTICKBUTTON_H
#define JOYCONTROLSTICKBUTTON_H

#include "joybuttontypes/joygradientbutton.h"
#include "joycontrolstickdirectionstype.h"

class JoyControlStick;
class SetJoystick;


class JoyControlStickButton : public JoyGradientButton
{
    Q_OBJECT

public:
    explicit JoyControlStickButton(JoyControlStick *stick, int index, int originset, SetJoystick *parentSet, QObject *parent = nullptr);
    explicit JoyControlStickButton(JoyControlStick *stick, JoyStickDirectionsType::JoyStickDirections index, int originset, SetJoystick *parentSet, QObject *parent = nullptr);

    virtual int getRealJoyNumber() const;
    virtual QString getPartialName(bool forceFullFormat=false, bool displayNames=false) const;
    virtual QString getXmlName();
    virtual double getDistanceFromDeadZone();

    virtual double getMouseDistanceFromDeadZone();
    virtual double getLastMouseDistanceFromDeadZone();

    virtual void setChangeSetCondition(SetChangeCondition condition, bool passive=false, bool updateActiveString=true);
    virtual void setTurboMode(TurboMode mode);
    virtual bool isPartRealAxis();
    virtual QString getActiveZoneSummary();
    virtual QString getCalculatedActiveZoneSummary();

    virtual double getAccelerationDistance();
    virtual double getLastAccelerationDistance();

    JoyControlStick* getStick() const;
    QString getDirectionName() const;
    JoyStickDirectionsType::JoyStickDirections getDirection() const;

protected:
    virtual double getCurrentSpringDeadCircle();

signals:
    void setAssignmentChanged(int current_button, int axis_index, int associated_set, int mode);

private:
    JoyControlStick *stick;

};

#endif // JOYCONTROLSTICKBUTTON_H
