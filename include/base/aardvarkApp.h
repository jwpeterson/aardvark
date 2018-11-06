//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef AARDVARKAPP_H
#define AARDVARKAPP_H

#include "MooseApp.h"

class aardvarkApp;

template <>
InputParameters validParams<aardvarkApp>();

class aardvarkApp : public MooseApp
{
public:
  aardvarkApp(InputParameters parameters);
  virtual ~aardvarkApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s);
};

#endif /* AARDVARKAPP_H */
