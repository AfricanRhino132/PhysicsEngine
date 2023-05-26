#include "GravitationalForce.h"
#include "Body.h"

void GravitationalForce::Apply(std::vector<class Body*> bodies)
{
	for (size_t i = 0; i < bodies.size() - 1; i++)
	{
		for (size_t j = i + 1; j < bodies.size(); j++)
		{
			Body* bodyA = bodies[i];
			Body* bodyB = bodies[j];

			// apply gravitational force
			glm::vec2 dir = bodyA->position - bodyB->position;
			float distance = glm::length(dir);
			if (distance == 0)
			{
				continue;
			}

			distance = glm::max(1.0f, distance);

			float force = m_strength * ((bodyA->mass * bodyB->mass) / distance);

			glm::vec2 ndir = glm::normalize(dir);

			bodyA->ApplyForce(-ndir * force);
			bodyB->ApplyForce(ndir * force);
		}
	}
}