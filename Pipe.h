#pragma once

#include "Object.h"
#include "consts.h"
#include <vector>

class Pipe : public Object {

public:

	Pipe(glm::vec4 color, GLfloat minorRadiusRatio = 1.0f) : Object(color) {
		if (minorRadiusRatio <= 0.0f || minorRadiusRatio > 1.0f)
			this->minorRadiusRatio = 1.0f;
		else
			this->minorRadiusRatio = minorRadiusRatio;
		initialize();
	}

private:
	GLfloat minorRadiusRatio;

	void setVertices() override {

		const GLfloat R = 1.0f;
		glm::vec3 centrePos;
		glm::vec3 vertexPos;
		glm::vec3 normal;

		centrePos = glm::vec3(R, 0.0f, 0.0f);
		for (int i = 0; i < CIRCLE_VERTS; ++i) {
			// coordinates x, y, from the top base
			vertices.push_back(R);
			vertices.push_back(R * cos(glm::radians(360.0f / CIRCLE_VERTS * i)));			
			vertices.push_back(R * sin(glm::radians(360.0f / CIRCLE_VERTS * i)));
			// color
			for (int i = 0; i < 4; ++i)
				vertices.push_back(color[i]);
			// texture
			vertices.push_back(0.0f);
			vertices.push_back(0.0f);
			// normal
			vertexPos = glm::vec3(R, R * cos(glm::radians(360.0f / CIRCLE_VERTS * i)), R * sin(glm::radians(360.0f / CIRCLE_VERTS * i)));
			normal = normalize(vertexPos - centrePos);
			vertices.push_back(normal[0]);
			vertices.push_back(normal[1]);
			vertices.push_back(normal[2]);
		}

		centrePos = glm::vec3(R, 0.0f, 0.0f);
		for (int i = 0; i < CIRCLE_VERTS; ++i) {
			// the x, y, z coordinates of the upper base
			vertices.push_back(R);
			vertices.push_back(R * minorRadiusRatio * cos(glm::radians(360.0f / CIRCLE_VERTS * i)));
			vertices.push_back(R * minorRadiusRatio * sin(glm::radians(360.0f / CIRCLE_VERTS * i)));
			// color
			for (int i = 0; i < 4; ++i)
				vertices.push_back(color[i]);
			// texture
			vertices.push_back(0.0f);
			vertices.push_back(0.0f);
			// normal
			vertexPos = glm::vec3(R, R * minorRadiusRatio * cos(glm::radians(360.0f / CIRCLE_VERTS * i)), R * minorRadiusRatio * sin(glm::radians(360.0f / CIRCLE_VERTS * i)));
			normal = normalize(-vertexPos + centrePos);
			vertices.push_back(normal[0]);
			vertices.push_back(normal[1]);
			vertices.push_back(normal[2]);
		}

		centrePos = glm::vec3(-R, 0.0f, 0.0f);
		for (int i = 0; i < CIRCLE_VERTS; ++i) {
			// the x, y, z coordinates of the upper base
			vertices.push_back(-R);
			vertices.push_back(R * cos(glm::radians(360.0f / CIRCLE_VERTS * i)));
			vertices.push_back(R * sin(glm::radians(360.0f / CIRCLE_VERTS * i)));
			// color
			for (int i = 0; i < 4; ++i)
				vertices.push_back(color[i]);
			// texture
			vertices.push_back(0.0f);
			vertices.push_back(0.0f);
			// normal
			vertexPos = glm::vec3(-R, R * cos(glm::radians(360.0f / CIRCLE_VERTS * i)), R * sin(glm::radians(360.0f / CIRCLE_VERTS * i)));
			normal = normalize(vertexPos - centrePos);
			vertices.push_back(normal[0]);
			vertices.push_back(normal[1]);
			vertices.push_back(normal[2]);
		}

		centrePos = glm::vec3(-R, 0.0f, 0.0f);
		for (int i = 0; i < CIRCLE_VERTS; ++i) {
			// the x, y, z coordinates of the upper base
			vertices.push_back(-R);
			vertices.push_back(R * minorRadiusRatio * cos(glm::radians(360.0f / CIRCLE_VERTS * i)));
			vertices.push_back(R * minorRadiusRatio * sin(glm::radians(360.0f / CIRCLE_VERTS * i)));
			// color
			for (int i = 0; i < 4; ++i)
				vertices.push_back(color[i]);
			// texture
			vertices.push_back(0.0f);
			vertices.push_back(0.0f);
			// normal
			vertexPos = glm::vec3(-R, R * minorRadiusRatio * cos(glm::radians(360.0f / CIRCLE_VERTS * i)), R * minorRadiusRatio * sin(glm::radians(360.0f / CIRCLE_VERTS * i)));
			normal = normalize(-vertexPos + centrePos);
			vertices.push_back(normal[0]);
			vertices.push_back(normal[1]);
			vertices.push_back(normal[2]);
		}
	}

	void setIndices() override {
		for (int i = 0; i < CIRCLE_VERTS; ++i) {
			// top base
			indices.push_back(i % CIRCLE_VERTS);
			indices.push_back((i + 1) % CIRCLE_VERTS);
			indices.push_back(CIRCLE_VERTS + ((i + 1) % CIRCLE_VERTS));

			indices.push_back(i % CIRCLE_VERTS);
			indices.push_back(CIRCLE_VERTS + (i % CIRCLE_VERTS));
			indices.push_back(CIRCLE_VERTS + ((i + 1) % CIRCLE_VERTS));
		}

		for (int i = 0; i < CIRCLE_VERTS; ++i) {
			// outer side
			indices.push_back(0 * CIRCLE_VERTS + (i % CIRCLE_VERTS));
			indices.push_back(0 * CIRCLE_VERTS + (i + 1) % CIRCLE_VERTS);
			indices.push_back(2 * CIRCLE_VERTS + ((i + 1) % CIRCLE_VERTS));

			indices.push_back(0 * CIRCLE_VERTS + (i % CIRCLE_VERTS));
			indices.push_back(2 * CIRCLE_VERTS + (i % CIRCLE_VERTS));
			indices.push_back(2 * CIRCLE_VERTS + ((i + 1) % CIRCLE_VERTS));
		}

		for (int i = 0; i < CIRCLE_VERTS; ++i) {
			// inner side
			indices.push_back(1 * CIRCLE_VERTS + (i % CIRCLE_VERTS));
			indices.push_back(1 * CIRCLE_VERTS + (i + 1) % CIRCLE_VERTS);
			indices.push_back(3 * CIRCLE_VERTS + ((i + 1) % CIRCLE_VERTS));

			indices.push_back(1 * CIRCLE_VERTS + (i % CIRCLE_VERTS));
			indices.push_back(3 * CIRCLE_VERTS + (i % CIRCLE_VERTS));
			indices.push_back(3 * CIRCLE_VERTS + ((i + 1) % CIRCLE_VERTS));
		}

		for (int i = 0; i < CIRCLE_VERTS; ++i) {
			// bottom base
			indices.push_back(2 * CIRCLE_VERTS + (i % CIRCLE_VERTS));
			indices.push_back(2 * CIRCLE_VERTS + (i + 1) % CIRCLE_VERTS);
			indices.push_back(3 * CIRCLE_VERTS + ((i + 1) % CIRCLE_VERTS));

			indices.push_back(2 * CIRCLE_VERTS + (i % CIRCLE_VERTS));
			indices.push_back(3 * CIRCLE_VERTS + (i % CIRCLE_VERTS));
			indices.push_back(3 * CIRCLE_VERTS + ((i + 1) % CIRCLE_VERTS));
		}
	}
};