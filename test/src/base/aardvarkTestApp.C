//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "aardvarkTestApp.h"
#include "aardvarkApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<aardvarkTestApp>()
{
  InputParameters params = validParams<aardvarkApp>();
  return params;
}

aardvarkTestApp::aardvarkTestApp(InputParameters parameters) : MooseApp(parameters)
{
  aardvarkTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

aardvarkTestApp::~aardvarkTestApp() {}

void
aardvarkTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  aardvarkApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"aardvarkTestApp"});
    Registry::registerActionsTo(af, {"aardvarkTestApp"});
  }
}

void
aardvarkTestApp::registerApps()
{
  registerApp(aardvarkApp);
  registerApp(aardvarkTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
aardvarkTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  aardvarkTestApp::registerAll(f, af, s);
}
extern "C" void
aardvarkTestApp__registerApps()
{
  aardvarkTestApp::registerApps();
}
