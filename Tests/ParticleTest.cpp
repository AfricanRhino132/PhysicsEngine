#include "ParticleTest.h"
#include "CircleShape.h"
#include "Body.h"

void ParticleTest::Initialize()
{
	Test::Initialize();
}

void ParticleTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(1, 3);
		auto body = new Body(new CircleShape(randomf(0.1f, 0.2f), { randomf(), randomf(), randomf(), 1 }), m_graphics->ScreenToWorld(m_input->GetMousePosition()), velocity);
		m_world->AddBody(body);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ParticleTest::Render()
{
	m_world->Draw(m_graphics);
}
