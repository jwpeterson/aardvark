//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef AARDVARKTESTAPP_H
#define AARDVARKTESTAPP_H

#include "MooseApp.h"

class aardvarkTestApp;

template <>
InputParameters validParams<aardvarkTestApp>();

class aardvarkTestApp : public MooseApp
{
public:
  aardvarkTestApp(InputParameters parameters);
  virtual ~aardvarkTestApp();

  static void registerApps();
  static void registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs = false);
};

#endif /* AARDVARKTESTAPP_H */
