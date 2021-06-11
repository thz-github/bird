#include "birdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
birdApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

birdApp::birdApp(InputParameters parameters) : MooseApp(parameters)
{
  birdApp::registerAll(_factory, _action_factory, _syntax);
}

birdApp::~birdApp() {}

void
birdApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"birdApp"});
  Registry::registerActionsTo(af, {"birdApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
birdApp::registerApps()
{
  registerApp(birdApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
birdApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  birdApp::registerAll(f, af, s);
}
extern "C" void
birdApp__registerApps()
{
  birdApp::registerApps();
}
