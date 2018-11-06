#include "aardvarkApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<aardvarkApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

aardvarkApp::aardvarkApp(InputParameters parameters) : MooseApp(parameters)
{
  aardvarkApp::registerAll(_factory, _action_factory, _syntax);
}

aardvarkApp::~aardvarkApp() {}

void
aardvarkApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"aardvarkApp"});
  Registry::registerActionsTo(af, {"aardvarkApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
aardvarkApp::registerApps()
{
  registerApp(aardvarkApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
aardvarkApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  aardvarkApp::registerAll(f, af, s);
}
extern "C" void
aardvarkApp__registerApps()
{
  aardvarkApp::registerApps();
}
