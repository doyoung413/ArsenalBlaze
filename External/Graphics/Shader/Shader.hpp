#pragma once
#include <map>
#include <string>
#include <filesystem>

#include "glm.hpp"

class Color4f;

class [[nodiscard]] Shader
{
public:
	Shader() noexcept = default;
	Shader(const std::filesystem::path& vertexPath,
		const std::filesystem::path& fragmentPath);
	~Shader() noexcept = default;

	std::string ReadFromSource(const std::filesystem::path& path);
	bool LoadFromSource(const std::filesystem::path& vertexPath,
		const std::filesystem::path& fragmentPath);

	void Use() noexcept;

	void SendUniformVariable(const std::string& variable_name, const glm::mat4& mat) noexcept;
	void SendUniformVariable(const std::string& variable_name, const glm::mat3& affine_matrix) noexcept;
	void SendUniformVariable(const std::string& variable_name, float number) noexcept;
	void SendUniformVariable(const std::string& variable_name, int number) noexcept;
	void SendUniformVariable(const std::string& variable_name, Color4f color) noexcept;

	constexpr unsigned GetShaderHandler() const noexcept { return handleToShader; }

	static void Select(const Shader& shader) noexcept;
	static void SelectNothing() noexcept;
	void Delete() noexcept;

private:
	int GetUniformLocation(const std::string& name) noexcept;

private:
	unsigned                   handleToShader = 0;
	std::map<std::string, int> uniformNameToLocation{};
};
