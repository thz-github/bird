//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "birdTestApp.h"
#include "birdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
birdTestApp::validParams()
{
  InputParameters params = birdApp::validParams();
  return params;
}

birdTestApp::birdTestApp(InputParameters parameters) : MooseApp(parameters)
{
  birdTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

birdTestApp::~birdTestApp() {}

void
birdTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  birdApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"birdTestApp"});
    Registry::registerActionsTo(af, {"birdTestApp"});
  }
}

void
birdTestApp::registerApps()
{
  registerApp(birdApp);
  registerApp(birdTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
birdTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  birdTestApp::registerAll(f, af, s);
}
extern "C" void
birdTestApp__registerApps()
{
  birdTestApp::registerApps();
}
