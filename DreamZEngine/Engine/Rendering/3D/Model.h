#ifndef MODEL_H
#define MODEL_H


#include "../../Graphics/stb_image.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "../../Camera/Camera.h"

#include"Mesh.h"

#include "../../Math/BoundingBox.h"

using namespace std;



class Model
{
public:
	/*  Model Data */
	vector<Texture> textures_loaded;	// stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
	vector<Mesh> meshes;
	string directory;
	bool gammaCorrection;

	/*  Functions   */
	// constructor, expects a filepath to a 3D model.
	Model(Shader* ourShader_, string const &path, bool gamma = false);


	std::vector<glm::mat4> modelInstances;
	GLuint CreateInstance(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);

	void UpdateInstance(GLuint index_, glm::vec3 position_, float angle_, glm::vec3 rotation, glm::vec3 scale_);

	glm::mat4 GetTransform(GLuint index_) const;

	Shader* ourShader;
	glm::mat4 GetTransform(glm::vec3 position_, float angle_, glm::vec3 rotation_, glm::vec3 scale_);
	// draws the model, and thus all its meshes
	void Render();

	Shader* GetShader() { return ourShader; }
	/*  Functions   */
	// loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
	void loadModel(string const &path);

	// processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
	void processNode(aiNode *node, const aiScene *scene);

	Mesh processMesh(aiMesh *mesh, const aiScene *scene);

	// checks all material textures of a given type and loads the textures if they're not loaded yet.
	// the required info is returned as a Texture struct.
	vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
	GLuint TextureFromFile(const char *path, const string &directory, bool gamma = false);

	BoundingBox GetBoundingBox();

private:
	BoundingBox box;
};



#endif