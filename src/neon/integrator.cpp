#include "integrator.hpp"
#include "neon/intersection.hpp"
#include "neon/material.hpp"
#include "neon/scene.hpp"
#include "neon/sphere.hpp"

namespace ne {

namespace core {

glm::vec3 Integrator::integrate(const ne::Ray &ray,
                                std::shared_ptr<ne::Scene> scene) {
  glm::vec3 L{0.0f};
  ne::Ray r{ray};
  ne::Intersection hit;

  // if ray hit object in scene, apply shading
  if (scene->rayIntersect(r, hit)) {
    MaterialPointer material = hit.material;
    L += glm::vec3(0.f);
  }
  // background color
  else
    L = scene->sampleBackgroundLight(r.dir);

  return L;
}

} // namespace core
} // namespace ne
