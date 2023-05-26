#include "World.h"
#include "Body.h"
#include "ForceGenerator.h"
#include "Joint.h"

#include "Collision.h"

#include <vector>

//negative 
glm::vec2 World::gravity{ 0, -9.81f };

World::~World()
{
	// <delete all the objects>
	for (auto body : m_bodies)
	{
		delete body;
	}
	// <clear the objects form the list clear()>
	m_bodies.clear();
}
void World::Step(float dt)
{

	for (auto joint : m_joints)
	{
		joint->Step(dt);
	}

	std::vector<Body*> bodies(m_bodies.begin(), m_bodies.end());

	if (!m_bodies.empty() && !m_forceGenerators.empty())
	{
		for (auto forceGenerator : m_forceGenerators)
		{
			forceGenerator->Apply(bodies);
		}
	}

	for (auto body : m_bodies)
	{
		body->Step(dt);
	}

	std::vector<Contact> contacts;

	if (!bodies.empty())
	{
		Collision::CreateContacts(bodies, contacts);
		Collision::SeparateContacts(contacts);
		Collision::ResolveContacts(contacts);
	}
}
void World::Draw(Graphics* graphics)
{
	for (auto body : m_bodies)
	{
		body->Draw(graphics);
	}

	for (auto forceGenerator : m_forceGenerators)
	{
		forceGenerator->Draw(graphics);
	}

	for (auto joint : m_joints)
	{
		joint->Draw(graphics);
	}
}
void World::AddBody(Body* body)
{
	m_bodies.push_back(body);
}
void World::RemoveBody(Body* body)
{
	m_bodies.remove(body);
}

void World::AddJoint(Joint* joint)
{
	m_joints.push_back(joint);
}

void World::RemoveJoint(Joint* joint)
{
	m_joints.remove(joint);
}

void World::AddForceGenerator(ForceGenerator* forceGenerator)
{
	m_forceGenerators.push_back(forceGenerator);
}
