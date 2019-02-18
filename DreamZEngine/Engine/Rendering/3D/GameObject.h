#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H



#include "../../FX/BasicLight.h"
#include "SkyBox.h"
#include "Terrain.h"


class GameObject
{
public:
	GameObject(Model* model_);
	GameObject(BasicLight* light_);
	GameObject(Model* model_, glm::vec3 position_);
	~GameObject();

	void Update(const float deltaTime_);


	void SetPosition(glm::vec3 position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 rotation_);
	void SetScale(glm::vec3 scale_);

	float GetAngle();
	glm::vec3 GetPosition() const;
	glm::vec3 GetRotation() const;
	glm::vec3 GetScale() const;





	BoundingBox GetBoundingBox() const;

	std::string GetTag();
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);



private:

	Model* model;
	GLuint modelInstance;
	glm::vec3 modelPosition;
	float modelAngle;
	glm::vec3 modelRotation;
	glm::vec3 modelScale;


	BoundingBox box;

	BasicLight* light;
	GLuint lightInstance;
	glm::vec3 lightPosition;
	float lightAngle;
	glm::vec3 lightRotation;
	glm::vec3 lightScale;

//	std::vector<LightStruct*> lights;
	std::string tag;
	bool hit;

};



#endif

