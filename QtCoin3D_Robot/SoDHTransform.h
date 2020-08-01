#ifndef SODHTRANSFORM_H
#define SODHTRANSFORM_H

#include <QString>

#include <Inventor/nodes/SoMatrixTransform.h>
#include <qmath.h>

class SoDHTransform : public SoMatrixTransform
{
public:
	enum DHTransformType
	{
		FIXED, 
		ROTATION, 
		MOVEMENT
	};

	SoDHTransform();
	~SoDHTransform();
	void init(double itheta, double id, double ialpha, double ia, DHTransformType type = ROTATION);
	void rotateTheta(double itheta);
	SoMatrixTransform * inverseMatrix();
	double getValue();
	QString getTpye();

	QString name;
	QString description;
	double max_ang;
	double min_ang;

private:
	DHTransformType type;
	double theta;
	double d;
	double a;
	double alpha;
	void calculate();
};

#endif // SODHTRANSFORM_H
