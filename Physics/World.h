#pragma once
#include <glm/glm.hpp>
#include <list>
#include <vector>

class Body;
class Joint;

class World
{
public:
	~World();
	void Step(float dt);
	void Draw(class Graphics* graphics);
	void AddBody(Body* body);
	void RemoveBody(Body* body);

	void AddJoint(Joint* joint);
	void RemoveJoint(Joint* joint);

	void AddForceGenerator(class ForceGenerator* forceGenerator);

public:
	static glm::vec2 gravity;

private:
	std::list<Body*> m_bodies;
	std::list<Joint*> m_joints;
	std::vector<class ForceGenerator*> m_forceGenerators;
};