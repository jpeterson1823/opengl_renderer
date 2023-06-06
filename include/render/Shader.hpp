#pragma once
#include <string>
#include <glm/glm.hpp>

class Shader {
private:
	unsigned int id;
    
	void checkShaderCompilation(unsigned int shader, bool vert);
public:
    unsigned int vao;
    unsigned int vbo;
	Shader();
	Shader(const char* vertexPath, const char* fragmentPath);
	~Shader();
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMat4(const std::string& name, glm::mat4& mat) const;
	void setVec3(const std::string& name, glm::vec3& vec) const;
	void setMVP(glm::mat4 model, glm::mat4 view, glm::mat4 projection);
	unsigned int getID();

    void bindVertexArray();
};
