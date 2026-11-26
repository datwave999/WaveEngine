#pragma once

#include<glad/glad.h>

#include<string>
#include<array>

#include "Graphics/Uniform.h"

#include<glm/glm.hpp>

class Shader {
public:
	Shader() = default;
	Shader(const char* vertexShaderLocation, const char* fragmentShaderLocation, const char* geometryShaderLocation = nullptr);
	void enableShader();
	void disableShader();

	// utility functions
	std::string loadShaderSource(const char* filename);
	GLuint compileShader(const char* filepath, GLenum type);

	// uniform functions
	void setUniform(Uniform name, bool value) const;
	void setUniform(Uniform name, int value) const;
	void setUniform(Uniform name, float value) const;
	void setUniform(Uniform name, const glm::vec3& value) const;
	void setUniform(Uniform name, const glm::mat4& mat) const;
	void setUniform(Uniform name, const glm::mat3& mat) const;

	~Shader();

private:
	GLuint shaderID = 0;

	// Caching uniform locations
	mutable std::array<GLint, static_cast<size_t>(Uniform::NUM_UNIFORMS)> uniformLocationCache;

	GLint GetUniformLocation(Uniform name) const;
};
