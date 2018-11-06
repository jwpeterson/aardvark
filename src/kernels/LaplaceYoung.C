#include "LaplaceYoung.h"

registerMooseObject("MooseApp", LaplaceYoung);

template <>
InputParameters
validParams<LaplaceYoung>()
{
  InputParameters params = validParams<Kernel>();
  params.addClassDescription("This class ...");
  params.addRequiredParam<Real>("kappa", "Coefficient of zeroth order term.");
  return params;
}

LaplaceYoung::LaplaceYoung(const InputParameters & parameters) : 
  Kernel(parameters),
  _kappa(getParam<Real>("kappa")),
  _k(getMaterialProperty<Real>("k"))
{}

Real 
LaplaceYoung::k() const
{
  return 1. / std::sqrt(1. + _grad_u[_qp] * _grad_u[_qp]);
}

Real
LaplaceYoung::computeQpResidual()
{
  // std::cout << "k from Material: " << _k[_qp] << std::endl;
  // std::cout << "k from helper function: " << k() << std::endl;
  return _k[_qp] * _grad_u[_qp] * _grad_test[_i][_qp]
    + _kappa * _u[_qp] * _test[_i][_qp];
}

Real
LaplaceYoung::computeQpJacobian()
{
  Real dkdu = - _grad_u[_qp] * _grad_phi[_j][_qp] / 
    std::pow(1. + _grad_u[_qp] * _grad_u[_qp], 1.5);
  return _k[_qp] * _grad_phi[_j][_qp] * _grad_test[_i][_qp]
    + dkdu * _grad_u[_qp] * _grad_test[_i][_qp]
    + _kappa * _phi[_j][_qp] * _test[_i][_qp];
}
