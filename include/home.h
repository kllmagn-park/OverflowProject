#pragma once

#include <Wt/WApplication.h>
#include <Wt/WBreak.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WLineEdit.h>
#include <Wt/WPushButton.h>
#include <Wt/WText.h>
#include <Wt/WTemplate.h>
#include <Wt/WBootstrapTheme.h>
#include <Wt/WTheme.h>

#include <Wt/WVBoxLayout.h>
#include <Wt/WLabel.h>

#include <Wt/WInteractWidget.h>

#include <iostream>

#include "settings.h"
#include "menu.h"

class OverflowProject : public Wt::WApplication
{
public:
  OverflowProject(const Wt::WEnvironment& env);
};

struct Flat {
  public:
    float price;
    string address;
    int rooms;
    int square;
    int floor;
    // и т.д.
};

class FlatWidget : public Wt::WContainerWidget
{
public:
    FlatWidget(const Flat flat);

    //Wt::Signal<int>& scoreUpdated() { return scoreUpdated_; }

private:
    Wt::WText        *price_;
    Wt::WText        *address_;
    Wt::WText        *rooms_;
    Wt::WText        *square_;
    Wt::WText        *floor_;
    Wt::WPushButton  *showflat_;
};

class FlatBox: public Wt::WContainerWidget {
  public:
    FlatBox(const std::vector<Flat> flats);
    void showflats();
    void collapse(std::string id);
    Wt::WContainerWidget *flat_container;
  private:
    bool is_shown;
    std::vector<Flat> data;
};