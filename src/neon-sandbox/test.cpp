#include "test.hpp"

#include "neon/material.hpp"
#include "neon/scene.hpp"
#include "neon/sphere.hpp"
#include <memory>

// Factory function for simple test scene1
std::shared_ptr<ne::Scene> testScene1() {
  // Define materials
  const ne::MaterialPointer mat1 =
      std::make_shared<ne::PhongMaterial>(glm::vec3{0.1f, 0.1f, 0.1f}, glm::vec3{ 0.8f, 0.4f, 0.6f }, glm::vec3{ 0.6f, 0.4f, 0.5f }, 50.0f);
  const ne::MaterialPointer mat2 =
      std::make_shared<ne::PhongMaterial>(glm::vec3{0.05f, 0.05f, 0.05f}, glm::vec3{ 0.6f, 1.0f, 0.6f }, glm::vec3{ 0.f, 0.f, 0.f }, 10.0f);
  const ne::MaterialPointer mat3 =
      std::make_shared<ne::PointLight>(glm::vec3{ 0.1f, 0.1f, 0.1f }, glm::vec3{ 1.0f, 1.0f, 1.0f }, glm::vec3{ 0.5f, 0.5f, 0.5f });

  // Define rendable geometries and bind materials
  const ne::RendablePointer s1 =
      std::make_shared<ne::Sphere>(glm::vec3(0, 0, -1), 0.5f, mat1);
  const ne::RendablePointer s2 =
      std::make_shared<ne::Sphere>(glm::vec3(0, -100.5, -1), 100.f, mat2);
  const ne::RendablePointer s3 =
      std::make_shared<ne::Sphere>(glm::vec3(0, 5, -1), 0.0f, mat3);  // light

  // Assemble the scene
  std::shared_ptr<ne::Scene> scene = std::make_shared<ne::Scene>();
  scene->add(s1);
  scene->add(s2);
  scene->add(s3);

  return scene;
}

