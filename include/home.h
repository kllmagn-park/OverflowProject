#pragma once

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTemplate.h>

#include "settings.h"

class OverflowProject : public Wt::WApplication
{
public:
  OverflowProject(const Wt::WEnvironment& env);

private:
  Wt::WLineEdit *nameEdit_;
  Wt::WText     *greeting_;

  void greet();
};
