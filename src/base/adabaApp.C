#include "adabaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
adabaApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

adabaApp::adabaApp(InputParameters parameters) : MooseApp(parameters)
{
  adabaApp::registerAll(_factory, _action_factory, _syntax);
}

adabaApp::~adabaApp() {}

void
adabaApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"adabaApp"});
  Registry::registerActionsTo(af, {"adabaApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
adabaApp::registerApps()
{
  registerApp(adabaApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
adabaApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  adabaApp::registerAll(f, af, s);
}
extern "C" void
adabaApp__registerApps()
{
  adabaApp::registerApps();
}
