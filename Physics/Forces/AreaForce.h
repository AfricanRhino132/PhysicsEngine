#pragma once
#include "ForceGenerator.h"

class AreaForce : public ForceGenerator
{
public:
	AreaForce(class Body* body, float forceMagniude, float forceAngle) :
		ForceGenerator(body),
		m_forceMagnitude{ forceMagniude },
		m_angle{ forceAngle }
	{}
	void Apply(std::vector<class Body*> bodies) override;
private:
	float m_forceMagnitude{ 1 };
	float m_angle{ 0 };
};