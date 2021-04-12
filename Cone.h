#pragma once

#include "Object.h"
#include "consts.h"
#include <vector>

class Cone : public Object {

public:

	Cone(glm::vec4 color) : Object(color), secondColor(color) {
		initialize();
	}

	Cone(glm::vec4 color, glm::vec4 secondColor) : Object(color), secondColor(secondColor) {
		initialize();
	}

private:
	glm::vec4 secondColor;

	void setVertices() override {

		const GLfloat R = 1.0f;
		glm::vec3 centrePos;
		glm::vec3 vertexPos;
		glm::vec3 normal;

		centrePos = glm::vec3(0.0f, 0.0f, 0.0f);
		for (int i = 0; i < CIRCLE_VERTS; ++i) {
			// the x, y, z coordinates of the base
			vertices.push_back(-R * cos(glm::radians(360.0f / CIRCLE_VERTS * i)));
			vertices.push_back(0.0f);
			vertices.push_back(-R * sin(glm::radians(360.0f / CIRCLE_VERTS * i)));
			// color
			for (int i = 0; i < 4; ++i)
				vertices.push_back(color[i]);
			// texture
			vertices.push_back(0.0f);
			vertices.push_back(0.0f);
			// normals
			vertexPos = glm::vec3(-R * cos(glm::radians(360.0f / CIRCLE_VERTS * i)), 0, -R * sin(glm::radians(360.0f / CIRCLE_VERTS * i)));
			normal = normalize(vertexPos - centrePos);
			vertices.push_back(normal[0]);
			vertices.push_back(normal[1]);
			vertices.push_back(normal[2]);
		}

		//tip
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);
		// colors
		for (int i = 0; i < 4; ++i)
			vertices.push_back(secondColor[i]);
		// texture
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		// normals
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);
	}

	void setIndices() override {

		for (int i = 0; i < CIRCLE_VERTS - 2; ++i) {
			// top surface
			indices.push_back(0);
			indices.push_back(i + 1);
			indices.push_back(i + 2);
		}

		for (int i = 0; i < CIRCLE_VERTS; ++i) {
			// lateral surface
			indices.push_back(i % CIRCLE_VERTS);
			indices.push_back((i + 1) % CIRCLE_VERTS);
			indices.push_back(CIRCLE_VERTS);
		}
	}
};
