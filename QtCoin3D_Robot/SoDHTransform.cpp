#include "sodhtransform.h"

SoDHTransform::SoDHTransform()
	:theta(0.0), d(0.0), a(0.0), alpha(0.0), type(ROTATION), name(""), description(""), max_ang(180), min_ang(-180)
{

}

SoDHTransform::~SoDHTransform()
{

}

void SoDHTransform::init(double itheta, double id, double ialpha, double ia, DHTransformType type)
{
	this->theta = itheta / 180 * 3.141592653;
	this->d = id;
	this->a = ia;
	this->alpha = ialpha / 180 * 3.141592653;
	calculate();
}

void SoDHTransform::rotateTheta(double itheta)
{
	this->theta = itheta / 180 * 3.141592653;
	calculate();
}

void SoDHTransform::calculate()
{
	this->matrix.setValue(
		 qCos(theta), qSin(theta)*qCos(alpha),  qSin(theta)*qSin(alpha),  0.0,
		-qSin(theta), qCos(theta)*qCos(alpha),  qCos(theta)*qSin(alpha),  0.0,
		         0.0,            -qSin(alpha),              qCos(alpha),  0.0,
		           a,        -d * qSin(alpha),            d*qCos(alpha),  1.0);
}

SoMatrixTransform * SoDHTransform::inverseMatrix()
{
	SoMatrixTransform *inMatrix = new SoMatrixTransform;
	inMatrix->matrix.setValue(this->matrix.getValue().inverse());
	return inMatrix;
}

double SoDHTransform::getValue()
{
	if (type == FIXED)
	{
		return 0.0;
	}
	else if (type == MOVEMENT)
	{
		return d;
	}
	else if (type == ROTATION)
	{
		return theta * 180.0 / 3.141592653;
	}
	else
		return -1;////
}

QString SoDHTransform::getTpye()
{
	if (type == FIXED)
	{
		return "FIXED";
	}
	else if (type == MOVEMENT)
	{
		return "MOVEMENT";
	}
	else if (type == ROTATION)
	{
		return "ROTATION";
	}
	else
		return "";
}
