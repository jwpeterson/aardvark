#ifndef LAPLACEYOUNG_H
#define LAPLACEYOUNG_H

#include "Kernel.h"

class LaplaceYoung;

template <>
InputParameters validParams<LaplaceYoung>();

/**
 * This kernel implements ...:
 */
class LaplaceYoung : public Kernel
{
public:
  LaplaceYoung(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual() override;

  virtual Real computeQpJacobian() override;

  const Real & _kappa;
  Real k() const;
};

#endif /* LAPLACEYOUNG_H */
