#include "Model.h"
#include "../Core/File.h"

#include <iostream>
#include <sstream>
#include "../Math/Transform.h"


void neu::Model::Draw(Renderer& renderer, const Vector2& position, float angle, const Vector2& scale)
{
	for (int i = 0; i < m_points.size() - 1; i++) {
		neu::Vector2 p1 = Vector2::Rotate((m_points[i] * scale), angle) + position;
		neu::Vector2 p2 = Vector2::Rotate((m_points[i+1] * scale), angle) + position;

		renderer.DrawLine(p1, p2, m_color);
	}
}


void neu::Model::Load(const std::string& filename)
{
	std::string buffer;

	neu::ReadFile(filename, buffer);

	// read color 
	std::istringstream stream(buffer);
	stream >> m_color;

	// read number of points 
	std::string line;
	std::getline(stream, line);
	size_t numPoints = std::stoi(line);

	// read model points 
	for (size_t i = 0; i < numPoints; i++)
	{
		Vector2 point;

		stream >> point;
		m_points.push_back(point);
	}
}

float neu::Model::CalculateRadius()
{
	float radius = 0;

	for (auto point : m_points)
	{
	if(point.Length() > radius) radius = point.Length();
	}

	return radius;
}