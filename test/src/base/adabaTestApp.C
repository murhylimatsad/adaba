//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "adabaTestApp.h"
#include "adabaApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
adabaTestApp::validParams()
{
  InputParameters params = adabaApp::validParams();
  return params;
}

adabaTestApp::adabaTestApp(InputParameters parameters) : MooseApp(parameters)
{
  adabaTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

adabaTestApp::~adabaTestApp() {}

void
adabaTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  adabaApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"adabaTestApp"});
    Registry::registerActionsTo(af, {"adabaTestApp"});
  }
}

void
adabaTestApp::registerApps()
{
  registerApp(adabaApp);
  registerApp(adabaTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
adabaTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  adabaTestApp::registerAll(f, af, s);
}
extern "C" void
adabaTestApp__registerApps()
{
  adabaTestApp::registerApps();
}
