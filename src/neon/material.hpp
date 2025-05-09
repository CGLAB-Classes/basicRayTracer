#ifndef __MATERIAL_H_
#define __MATERIAL_H_

#include "neon/blueprint.hpp"
#include "neon/intersection.hpp"
#include "neon/ray.hpp"

namespace ne {

namespace abstract {

// Absract material class for inteface
// you can add/change variables/methods if you want
class Material {
public:

  glm::vec3 getLa() { return La; }
  glm::vec3 getLd() { return Ld; }
  glm::vec3 getLs() { return Ls; }
  glm::vec3 getKa() { return Ka; }
  glm::vec3 getKd() { return Kd; }
  glm::vec3 getKs() { return Ks; }
  float getS() { return s; }

  bool isEmiited() {
      return isEmitted;
  }


protected:
    glm::vec3 La, Ld, Ls; 
    glm::vec3 Ka, Kd, Ks;
    float s;
    bool isEmitted = false;
};

} // namespace abstract

/*  Actual implementation of materials  */
// you can add/change variables/methods if you want

// Light material which glow unifomly.
class PointLight final : public ne::abstract::Material {
public:
    PointLight(const glm::vec3& la = glm::vec3(1.0f), const glm::vec3& ld = glm::vec3(1.0f), const glm::vec3& ls = glm::vec3(1.0f)){
        La = la;
        Ld = ld;
        Ls = ls;
        isEmitted = true;
    }

};

// PhongMaterial follows an approximation of light reflection.
class PhongMaterial final : public ne::abstract::Material {
public:
    PhongMaterial(const glm::vec3& ka = glm::vec3(1.0f), const glm::vec3& kd = glm::vec3(1.0f), const glm::vec3& ks = glm::vec3(1.0f), const float s_ = 1.0f){
        Ka = ka;
        Kd = kd;
        Ks = ks;
        s = s_;
    }
};



} // namespace ne

#endif // __MATERIAL_H_
