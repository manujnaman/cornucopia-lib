/*--
    Line.h  

    This file is part of the Cornucopia curve sketching library.
    Copyright (C) 2010 Ilya Baran (ibaran@mit.edu)

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED

#include "defs.h"
#include "CurvePrimitive.h"

NAMESPACE_Cornu

SMART_FORW_DECL(Line);

class Line : public CurvePrimitive
{
public:
    Line() {} //uninitialized
    Line(const Vec &p1, const Vec &p2);

    //overrides
    void eval(double s, Vec *pos, Vec *der = NULL, Vec *der2 = NULL) const;

    double project(const Vec &point) const;

    Vec pos(double s) const { return _startPos() + s * _der; }
    Vec der(double s) const { return _der; }
    Vec der2(double s) const { return Vec::Zero(); }

    double angle(double s) const { return _startAngle(); }
    double evalCurvature(double s) const { return 0; }

    double endAngle() const { return _startAngle(); }
    double startCurvature() const { return 0; }
    double endCurvature() const { return 0; }

    PrimitiveType getType() const { return LINE; }

    void trim(double sFrom, double sTo);
    void flip();
    CurvePrimitivePtr clone() const { LinePtr out = new Line(); out->setParams(_params); return out; }
    void derivativeAt(double s, ParamDer &out);

    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
protected:
    //override
    void paramsChanged() { _der = Vec(cos(_startAngle()), sin(_startAngle())); }

private:
    Vec _der;
};

END_NAMESPACE_Cornu

#endif //LINE_H_INCLUDED