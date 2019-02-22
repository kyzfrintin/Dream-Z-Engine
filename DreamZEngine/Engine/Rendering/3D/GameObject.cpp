#include "GameObject.h"




GameObject::GameObject(Model* model_) : model(model_),modelPosition(glm::vec3(0.0f, 1.0f, 0.0f)), modelAngle(0.0f), modelRotation(glm::vec3(0.0f, 1.0f, 0.0f)), modelScale(glm::vec3(1.0f)), tag(""), hit(false)
{
	model = model_;
	if (model)
	{
		modelInstance = model->CreateInstance(modelPosition, modelAngle, modelRotation, modelScale);
		box = model->GetBoundingBox();
		box.transform = model->GetTransform(modelInstance);
		box.CreateVertexBuffer();
	}

}



GameObject::GameObject(Model* model_, glm::vec3 position_) : modelPosition(glm::vec3()), modelAngle(0.0f), modelRotation(glm::vec3(0.0f, 1.0f, 0.0f)), modelScale(glm::vec3(1.0f)), tag(""), hit(false)
{
	model = model_;
	modelPosition = position_;
	if (model)
	{
		modelInstance = model->CreateInstance(modelPosition, modelAngle, modelRotation, modelScale);
		box = model->GetBoundingBox();
		box.transform = model->GetTransform(modelInstance);
		
	}

}


GameObject::GameObject(BasicLight* light_) : lightPosition(glm::vec3()), lightAngle(0.0f), lightRotation(glm::vec3(0.0f, 1.0f, 0.0f)), lightScale(glm::vec3(1.0f)), tag(""), hit(false)
{
	light = light_;
	if (light)
	{
		lightInstance = light->CreateBasicLightInstance(lightPosition, lightAngle, lightRotation, lightScale);
	//	box = model->GetBoundingBox();
		//box.transform = light->GetTransform(modelInstance);
	}
	//LightingManager::GetInstance()->AddLight(light_->tag,lightstruct_);

}

GameObject::GameObject(Cube* cube_) : collider(cube_), colliderPosition(glm::vec3(0.0f, 1.0f, 0.0f)), colliderAngle(0.0f), colliderRotation(glm::vec3(0.0f, 1.0f, 0.0f)), colliderScale(glm::vec3(1.0f)), tag(""), hit(false)
{
	collider = cube_;
	if (collider)
	{
		colliderInstance = collider->CreateCubeInstance(colliderPosition, colliderAngle, colliderRotation, colliderScale);
		//	box = model->GetBoundingBox();
			//box.transform = collider->GetTransform(modelInstance);
	}
	//collideringManager::GetInstance()->Addcollider(collider_->tag,colliderstruct_);

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
		box.transform = model->GetTransform(modelInstance);
	}
	lightPosition = position_;
	if (light)
	{
		//light->UpdateInstance(lightInstance, lightPosition, lightAngle, lightRotation, lightScale);
		LightingManager::GetInstance()->UpdateLightPosition(this->GetTag(), position_);
	}
	colliderPosition = position_;
	if (collider)
	{
		//light->UpdateInstance(lightInstance, lightPosition, lightAngle, lightRotation, lightScale);
		collider->UpdateInstance(colliderInstance, colliderPosition, colliderAngle, colliderRotation, colliderScale);
	}

}
void GameObject::SetAngle(float angle_)
{
	modelAngle = angle_;
	if (model)
	{
		model->UpdateInstance(modelInstance, modelPosition, modelAngle, modelRotation, modelScale);
		box.transform = model->GetTransform(modelInstance);
	}
	lightAngle = angle_;
	if (light)
	{
		light->UpdateInstance(lightInstance, lightPosition, lightAngle, lightRotation, lightScale);
	}
	colliderAngle = angle_;
	if (collider)
	{
		collider->UpdateInstance(colliderInstance, colliderPosition, colliderAngle, colliderRotation, colliderScale);
	}
}

void GameObject::SetRotation(glm::vec3 rotation_)
{
	modelRotation = rotation_;
	if (model)
	{
		model->UpdateInstance(modelInstance, modelPosition, modelAngle, modelRotation, modelScale);
		box.transform = model->GetTransform(modelInstance);
	}

	lightRotation = rotation_;
	if (light)
	{
		light->UpdateInstance(lightInstance, lightPosition, lightAngle, lightRotation, lightScale);
	}
	colliderRotation = rotation_;
	if (collider)
	{
		collider->UpdateInstance(colliderInstance, colliderPosition, colliderAngle, colliderRotation, colliderScale);
	}
}

void GameObject::SetScale(glm::vec3 scale_)
{
	modelScale = scale_;
	if (model)
	{
		model->UpdateInstance(modelInstance, modelPosition, modelAngle, modelRotation, modelScale);
		box.transform = model->GetTransform(modelInstance);
		box.minVert *= (modelScale);
		box.maxVert *= (modelScale);
	}

	lightScale = scale_;
	if (light)
	{
		light->UpdateInstance(lightInstance, lightPosition, lightAngle, lightRotation, lightScale);
	}
	colliderScale = scale_;
	if (collider)
	{
		collider->UpdateInstance(colliderInstance, colliderPosition, colliderAngle, colliderRotation, colliderScale);
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
	if (collider)
	{
		return colliderPosition;
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
	if (collider)
	{
		return colliderAngle;
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
	if (collider)
	{
		return colliderRotation;
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
	if (collider)
	{
		return colliderScale;
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

BoundingBox GameObject::GetBoundingBox() const {

	return box;
}