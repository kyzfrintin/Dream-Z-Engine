#include "GameObject.h"




GameObject::GameObject(Model* model_) : modelPosition(glm::vec3()), modelAngle(0.0f), modelRotation(glm::vec3(0.0f, 1.0f, 0.0f)), modelScale(glm::vec3(1.0f)), tag(""), hit(false)
{
	model = model_;
	if (model)
	{
		modelInstance = model->CreateInstance(modelPosition, modelAngle, modelRotation, modelScale);
	}

}



GameObject::GameObject(Model* model_, glm::vec3 position_) : modelPosition(glm::vec3()), modelAngle(0.0f), modelRotation(glm::vec3(0.0f, 1.0f, 0.0f)), modelScale(glm::vec3(1.0f)), tag(""), hit(false)
{
	model = model_;
	modelPosition = position_;
	if (model)
	{
		//	modelInstance = model->CreateModelInstance(modelPosition, modelAngle, modelRotation, modelScale);
	}

}


GameObject::GameObject(BasicLight* light_) : lightPosition(glm::vec3()), lightAngle(0.0f), lightRotation(glm::vec3(0.0f, 1.0f, 0.0f)), lightScale(glm::vec3(1.0f)), tag(""), hit(false)
{
	light = light_;
	if (light)
	{
		lightInstance = light->CreateBasicLightInstance(lightPosition, lightAngle, lightRotation, lightScale);

	}
	//LightingManager::GetInstance()->AddLight(light_->tag,lightstruct_);

}

GameObject::~GameObject()
{
	if (model)
	{
		delete model;
	}

	model = nullptr;

}

void GameObject::Update(const float deltaTime_)
{
	//SetAngle(angle + 0.05f);
}
void GameObject::SetPosition(glm::vec3 position_)
{
	modelPosition = position_;
	if (model)
	{
		model->UpdateInstance(modelInstance, modelPosition, modelAngle, modelRotation, modelScale);
	}
	lightPosition = position_;
	if (light)
	{
		//light->UpdateInstance(lightInstance, lightPosition, lightAngle, lightRotation, lightScale);
		LightingManager::GetInstance()->UpdateLightPosition(this->GetTag(), position_);
	}

}
void GameObject::SetAngle(float angle_)
{
	modelAngle = angle_;
	if (model)
	{
		model->UpdateInstance(modelInstance, modelPosition, modelAngle, modelRotation, modelScale);
	}
	lightAngle = angle_;
	if (light)
	{
		light->UpdateInstance(lightInstance, lightPosition, lightAngle, lightRotation, lightScale);
	}
}

void GameObject::SetRotation(glm::vec3 rotation_)
{
	modelRotation = rotation_;
	if (model)
	{
		model->UpdateInstance(modelInstance, modelPosition, modelAngle, modelRotation, modelScale);
	}

	lightRotation = rotation_;
	if (light)
	{
		light->UpdateInstance(lightInstance, lightPosition, lightAngle, lightRotation, lightScale);
	}
}

void GameObject::SetScale(glm::vec3 scale_)
{
	modelScale = scale_;
	if (model)
	{
		model->UpdateInstance(modelInstance, modelPosition, modelAngle, modelRotation, modelScale);
	}

	lightScale = scale_;
	if (light)
	{
		light->UpdateInstance(lightInstance, lightPosition, lightAngle, lightRotation, lightScale);
	}

}

void GameObject::SetHit(bool hit_, int buttonType_) {
	hit = hit_;


}


glm::vec3 GameObject::GetPosition() const
{
	if (model)
	{
		return modelPosition;
	}
	if (light)
	{
		return LightingManager::GetInstance()->GetLightValueForUpdating(this->tag)->position;
	}
	return glm::vec3(0);
}
float GameObject::GetAngle()
{
	if (model)
	{
		return modelAngle;
	}
	if (light)
	{
		return lightAngle;
	}
	return 0.0f;
}
glm::vec3 GameObject::GetRotation() const
{
	if (model)
	{
		return modelRotation;
	}
	if (light)
	{
		return lightRotation;
	}
	return glm::vec3(0);
}
glm::vec3 GameObject::GetScale() const
{
	if (model)
	{
		return modelScale;
	}
	if (light)
	{
		return lightScale;
	}
	return glm::vec3(0);
}



std::string GameObject::GetTag()
{
	return tag;
}

void GameObject::SetTag(std::string tag_)
{
	tag = tag_;
}

