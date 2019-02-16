#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <glm/glm.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/string_cast.hpp>
struct BoundingBox {

	glm::vec3 minVert;
	glm::vec3 maxVert;
	glm::mat4 transform;

	inline BoundingBox() {
		minVert = glm::vec3(0.0f);
		maxVert = glm::vec3(0.0f);
		transform = glm::mat4(0.0f);
	}

	inline BoundingBox(glm::vec3 minVert_, glm::vec3 maxVert_, glm::mat4 transform_) {
		minVert = minVert_;
		maxVert = maxVert_;
		transform = transform_;
	}

	inline bool Intersects(BoundingBox* box_)
	{
		glm::vec3 minCorner = GetTrandformedPoint(minVert, transform);
		glm::vec3 maxCorner = GetTrandformedPoint(maxVert, transform);
		glm::vec3 other_minCorner= GetTrandformedPoint(box_->minVert, box_->transform);
		glm::vec3 other_maxCorner= GetTrandformedPoint(box_->maxVert, box_->transform);

		return true;
	}
private:
	inline glm::vec3 GetTrandformedPoint(glm::vec3 point_, glm::mat4 transform_)
	{
		glm::vec3 scale;
		glm::quat rotation;
		glm::vec3 translation;
		glm::vec3 skew;
		glm::vec4 perspective;
		glm::decompose(transform_, scale, rotation, translation, skew, perspective);
		return point_ + translation;
	}
};

#endif
