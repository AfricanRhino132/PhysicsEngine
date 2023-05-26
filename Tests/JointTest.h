#pragma once
#include "Test.h"

class JointTest : public Test
{
public:
	void Initialize() override;

	void Update() override;
	virtual void FixedUpdate() override;

	virtual void Render() override;

private:
	Body* m_anchor{ nullptr };
};