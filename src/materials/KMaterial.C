#include "KMaterial.h"

registerMooseObject("aardvarkApp", KMaterial);

template <>
InputParameters
validParams<KMaterial>()
{
  InputParameters params = validParams<Material>();
  params.addRequiredCoupledVar("u", "The Laplace-Young elevation variable.");
  return params;
}

KMaterial::KMaterial(const InputParameters & parameters)
  : Material(parameters),
    _k(declareProperty<Real>("k")),
    _grad_u(coupledGradient("u"))
{
}

void
KMaterial::computeQpProperties()
{
  _k[_qp] = std::sqrt(1. + _grad_u[_qp] * _grad_u[_qp]);
}
