#ifndef CONTACTDATA_H
#define CONTACTDATA_H

#include "../Rendering/3D/GameObject.h"
#include <glm\glm.hpp>



	struct ContactData {
		GameObject *A;
		GameObject *B;
		glm::vec3 normal;
		float penatration = 0.0f;

		static ContactData * CreateContactData(GameObject * _A, GameObject * _B) {
			ContactData *Contact = new ContactData();
			Contact->A = _A;
			Contact->B = _B;
			return Contact;
		}
	};

#endif