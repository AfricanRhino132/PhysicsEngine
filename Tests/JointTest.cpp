#include "JointTest.h"
#include "CircleShape.h"
#include "World.h"
#include "Body.h"
#include "Joint.h"

#define SPRING_STIFFNESS 100
#define SPRING_LENGTH 1
#define BODY_DAMPING 10
#define CHAIN_SIZE 3

void JointTest::Initialize()
{
	Test::Initialize();
	//								   smol					zero this
	m_anchor = new Body(new CircleShape(1, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBody(m_anchor);

	auto prevBody = m_anchor;
	//									smol				   more zero
	auto body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { 0, 0 }, {0, 0}, 1, Body::DYNAMIC);
	//man fetch that gravity scale
	body->damping = BODY_DAMPING;
	m_world->AddBody(body);

	auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
	m_world->AddJoint(joint);

	prevBody = body;

	std::vector<Body*> chain1;
	chain1.push_back(body);


	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { 0, 0}, { 0, 0 }, 1, Body::DYNAMIC);
		//no more gravity scale
		body->damping = BODY_DAMPING;
		m_world->AddBody(body);

		joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);
		
		prevBody = body;
		chain1.push_back(body);
	}

	//std::vector<Body*> chain2;

	//body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { 0, 0}, { 0, 0 }, 1, Body::DYNAMIC);
	//body->damping = BODY_DAMPING;
	//m_world->AddBody(body);

	//joint = new Joint(m_anchor, body, SPRING_STIFFNESS, SPRING_LENGTH);
	//m_world->AddJoint(joint);

	//chain2.push_back(body);

	//prevBody = body;

	//for (int i = 0; i < CHAIN_SIZE; i++)
	//{
	//	body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::DYNAMIC);
	//	body->damping = BODY_DAMPING;
	//	m_world->AddBody(body);

	//	joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
	//	m_world->AddJoint(joint);

	//	chain2.push_back(body);

	//	prevBody = body;
	//}

	//for (int i = 0; i < chain1.size(); i++)
	//{
	//	joint = new Joint(chain1[i], chain2[i], SPRING_STIFFNESS, SPRING_LENGTH);
	//	m_world->AddJoint(joint);

	//	if (i > 0)
	//	{
	//		joint = new Joint(chain1[i], chain2[i - 1], SPRING_STIFFNESS, SPRING_LENGTH);
	//		m_world->AddJoint(joint);
	//	}

	//	if (i + 1 < chain1.size())
	//	{
	//		joint = new Joint(chain1[i], chain2[i + 1], SPRING_STIFFNESS, SPRING_LENGTH);
	//		m_world->AddJoint(joint);
	//	}
	//}

}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
}