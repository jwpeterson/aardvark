#ifndef KMATERIAL_H
#define KMATERIAL_H

#include "Material.h"

// Forward Declarations
class KMaterial;

template <>
InputParameters validParams<KMaterial>();

/**
 *
 */
class KMaterial : public Material
{
public:
  KMaterial(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

  MaterialProperty<Real> & _k;
  const VariableGradient & _grad_u;
};

#endif
