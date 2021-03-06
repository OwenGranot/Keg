#pragma once

#include <string>
#include <vector>
#include <entt.hpp>

#include "Renderer/Vertex.h"
#include "Renderer/DrawDetails.h"
#include "Scene/Components.h"

namespace Keg
{

#define RENDERER_NEAR_PLANE 0.1f
#define RENDERER_FAR_PLANE 100.0f
#define RENDERER_FOV 90.0f
#define RENDERER_DEFAULT_SHADER "ColorShader"
#define RENDERER_LIGHTSOURCE_SHADER "LightSourceShader"

	class Renderer
	{
	public:
		virtual void Init(void* procAddress) = 0;
		virtual void Shutdown() = 0;
		virtual void OnViewportChange(int width, int height) = 0;
		virtual void SetFOV(float fov) = 0;

		virtual void BeginRender() = 0;
		virtual void BeginRender(glm::mat4 &viewMatrix) = 0;
		virtual void BeginRender(glm::mat4 &viewMatrix, Shader *shader) = 0;
		virtual void EndRender() = 0;
		virtual void Render(entt::registry& registery) = 0;
		virtual void Draw(entt::registry& registery, entt::entity& entity, Shader* shader) = 0;
		
		// Mesh

		// Shaders
		virtual void AddShader(const std::string& name, const std::string& vs, const std::string& fs) = 0;
		virtual void AddShader(const std::string& name, Shader* s) = 0;
		virtual void RemoveShader(const std::string& name) = 0;
		virtual Shader* GetShader(const std::string &name) = 0;
	};
}

