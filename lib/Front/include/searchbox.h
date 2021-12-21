#pragma once

#include <functional>

#include "object_widget.h"

class SearchBox: public Wt::WContainerWidget {
/*
Интерфейс поисковой выдачи (GUI составляющая).
Обеспечивает отображение заданного списка объектов подключенной модели (квартир).
*/
  public:
    SearchBox(std::function<std::vector<std::unique_ptr<Object>>(Wt::WString)> gd): get_data(gd) {
      setContentAlignment(Wt::AlignmentFlag::Center);
      addStyleClass("row align-self-center");
      is_shown = false;
      //auto address_label = addWidget(std::make_unique<Wt::WLabel>("Ваш адрес:"));
      search_input = addWidget(std::make_unique<Wt::WLineEdit>());
      //address_label->addStyleClass("input-group-text");
      search_input->addStyleClass("col m-4 align-self-center input-lg");
      search_input->setAttributeValue("data-toggle", "collapse");
      search_input->setAttributeValue("href", "#obj_container");
      search_input->setAttributeValue("style", "font-size: 24px;");
      search_input->setPlaceholderText("Ваш адрес");
      search_input->setId("search_input");
      search_input->enterPressed().connect(this, &SearchBox::showresults);
      addWidget(std::make_unique<Wt::WBreak>());
      //auto show_button = addWidget(std::make_unique<Wt::WPushButton>("Показать."));
      //show_button->clicked().connect(this, &SearchBox::showflats);
      obj_container = addWidget(std::make_unique<Wt::WContainerWidget>());
      obj_container->setContentAlignment(Wt::AlignmentFlag::Left);
      obj_container->setId("obj_container");
      obj_container->addStyleClass("collapse");
      //obj_container->hide();
    };
    std::function<std::vector<std::unique_ptr<Object>>(Wt::WString)> get_data;
    void showresults() {
      data = get_data(search_input->text());
      obj_container->clear();
      for (int i = 0; i < data.size(); i++) {
        obj_container->addWidget(std::make_unique<ObjectWidget>(*(data[i].get())));
        obj_container->addWidget(std::make_unique<Wt::WBreak>());
      }
      if (!is_shown) {
        collapse();
        is_shown = !obj_container->isHidden();
      }
    };
    std::vector<std::unique_ptr<Object>> data;
  private:
    void collapse() {
        doJavaScript("var collapseElementList = [].slice.call(document.querySelectorAll('#obj_container'))\n"
    "var collapseList = collapseElementList.map(function (collapseEl) {\n"
    "return new bootstrap.Collapse(collapseEl)\n"
    "})");
    }
    Wt::WLineEdit *search_input;
    bool is_shown;
    Wt::WContainerWidget *obj_container;
};