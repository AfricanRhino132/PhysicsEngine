#include "CircleShape.h"
#include "Graphics.h"

void CircleShape::Draw(Graphics* graphics, const glm::vec2& position)
{
	//convert that shiz
	int r = graphics->WorldToPixels(radius);
	//							convert more of that shiz 
	graphics->DrawFilledCircle(graphics->WorldToScreen(position), r, color);
}
