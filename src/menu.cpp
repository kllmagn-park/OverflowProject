#include "menu.h"

Menu::Menu() {
    auto container = std::make_unique<Wt::WContainerWidget>();

    // Create a stack where the contents will be located.
    auto contents = std::make_unique<Wt::WStackedWidget>();

    Wt::WMenu *menu = container->addNew<Wt::WMenu>(contents.get());
    menu->setStyleClass("nav nav-pills nav-stacked");
    menu->setWidth(150);

    // Add menu items using the default lazy loading policy.
    menu->addItem("Internal paths", std::make_unique<Wt::WTextArea>("Internal paths contents"));
    menu->addItem("Anchor", std::make_unique<Wt::WTextArea>("Anchor contents"));
    menu->addItem("Stacked widget", std::make_unique<Wt::WTextArea>("Stacked widget contents"));
    menu->addItem("Tab widget", std::make_unique<Wt::WTextArea>("Tab widget contents"));
    menu->addItem("Menu", std::make_unique<Wt::WTextArea>("Menu contents"));

    container->addWidget(std::move(contents));
}