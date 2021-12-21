#pragma once

#include <iostream>

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

class Object {
public:
    Object() {};
    virtual std::unique_ptr<Wt::WTemplate> info() {return std::unique_ptr<Wt::WTemplate>();};
};

class ObjectWidget : public Wt::WContainerWidget
{
public:
    ObjectWidget(Object& obj) {
        setContentAlignment(Wt::AlignmentFlag::Center);
        //decorationStyle().setBackgroundColor(Wt::WColor(226, 226, 226));
        auto layout = setLayout(std::make_unique<Wt::WVBoxLayout>());
        addStyleClass("row rounded-3 border border-white border-3");
        Wt::WColor color = Wt::WColor();
        color.setRgb(44, 47, 51);
        decorationStyle().setBackgroundColor(color);
        info_ = layout->addWidget(obj.info());
    }
public:
    Wt::WPushButton  *show_; // кнопка - показать объект
private:
    Wt::WTemplate    *info_; // вся информация об объекте
};

