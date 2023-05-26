#include "ForceTest.h"
#include "CircleShape.h"
#include "Body.h"
#include "GravitationalForce.h"
#include "PointForce.h"
#include "AreaForce.h"
#include "DragForce.h"

#define POINT_FORCE
//#define AREA_FORCE
//#define DRAG_FORCE

void ForceTest::Initialize()
{
	Test::Initialize();

#if defined(POINT_FORCE)
	auto body = new Body(new CircleShape(5, { 1, 1, 1, 0.2f }), m_graphics->ScreenToWorld({ 400, 300 }), { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new PointForce(body, 2);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(AREA_FORCE)
	auto body = new Body(new CircleShape(5, { 1, 1, 1, 0.2f }), m_graphics->ScreenToWorld({ 400, 300 }), { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new AreaForce(body, 2, 90);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(DRAG_FORCE)
	auto body = new Body(new CircleShape(5, { 1, 1, 1, 0.2f }), m_graphics->ScreenToWorld({ 400, 300 }), { 0, 0 }, 0, Body::STATIC)
		;
	ForceGenerator* forceGenerator = new DragForce(body, 0.5f);
	m_world->AddForceGenerator(forceGenerator);
#endif
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(1, 3);

		float size = randomf(0.1f, 0.2f);

		auto body = new Body(new CircleShape(size, { randomf(), randomf(), randomf(), 1 }), m_graphics->ScreenToWorld(m_input->GetMousePosition()), velocity, size);

		body->gravityScale = 1;
		
		m_world->AddBody(body);
	}
}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Render()
{
	m_world->Draw(m_graphics);
}
