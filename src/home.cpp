#include "home.h"

FlatWidget::FlatWidget(const Flat flat)
{
    setContentAlignment(Wt::AlignmentFlag::Center);
    //decorationStyle().setBackgroundColor(Wt::WColor(226, 226, 226));
    auto layout = setLayout(std::make_unique<Wt::WVBoxLayout>());
    addStyleClass("row rounded-3 bg-secondary");
    price_ = layout->addWidget(std::make_unique<Wt::WText>("Цена: " + std::to_string(flat.price)));
    address_ = layout->addWidget(std::make_unique<Wt::WText>("Адрес: " + flat.address));
    rooms_ = layout->addWidget(std::make_unique<Wt::WText>("Количество комнат: " + std::to_string(flat.rooms)));
    square_ = layout->addWidget(std::make_unique<Wt::WText>("Площадь: " + std::to_string(flat.square)));
    floor_ = layout->addWidget(std::make_unique<Wt::WText>("Этаж: " + std::to_string(flat.floor)));
}

FlatBox::FlatBox(const vector<Flat> flats) {
  setContentAlignment(Wt::AlignmentFlag::Center);
  addStyleClass("row align-self-center");
  data = flats;
  is_shown = false;
  //auto address_label = addWidget(std::make_unique<Wt::WLabel>("Ваш адрес:"));
  auto address_input = addWidget(std::make_unique<Wt::WLineEdit>());
  //address_label->addStyleClass("input-group-text");
  address_input->addStyleClass("col m-4 align-self-center input-lg");
  address_input->setAttributeValue("data-toggle", "collapse");
  address_input->setAttributeValue("href", "#flat_container");
  address_input->setAttributeValue("style", "font-size: 24px;");
  address_input->setPlaceholderText("Ваш адрес");
  address_input->setId("address_input");
  address_input->enterPressed().connect(this, &FlatBox::showflats);
  addWidget(std::make_unique<Wt::WBreak>());
  //auto show_button = addWidget(std::make_unique<Wt::WPushButton>("Показать."));
  //show_button->clicked().connect(this, &FlatBox::showflats);
  flat_container = addWidget(std::make_unique<Wt::WContainerWidget>());
  flat_container->setContentAlignment(Wt::AlignmentFlag::Left);
  flat_container->setId("flat_container");
  flat_container->addStyleClass("collapse");
  for (auto flat: data) {
    flat_container->addWidget(std::make_unique<FlatWidget>(flat));
    flat_container->addWidget(std::make_unique<Wt::WBreak>());
  }
  //flat_container->hide();
}

void FlatBox::collapse(std::string id = "flat_container") {
  doJavaScript("var collapseElementList = [].slice.call(document.querySelectorAll('#" + id + "'))\n"
    "var collapseList = collapseElementList.map(function (collapseEl) {\n"
    "return new bootstrap.Collapse(collapseEl)\n"
    "})");
}

void FlatBox::showflats() {
  collapse();
  is_shown = !is_shown;
  //if (is_shown) flat_container->show(); else flat_container->hide();
}

OverflowProject::OverflowProject(const Wt::WEnvironment& env) : WApplication(env)
{
  auto theme = std::make_shared<Wt::WBootstrapTheme>();
  theme->setVersion(Wt::BootstrapVersion::v3);
  setTheme(theme);
  useStyleSheet(Wt::WLink("https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/css/bootstrap.min.css"));
  require("https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js");
  setTitle(Settings::General::site_title);
  setBodyClass("bg-primary text-white");
  //root()->decorationStyle().setBackgroundColor(Wt::WColor("blue"));
  root()->addStyleClass("container vh-100 vw-100");
  auto site_label = root()->addWidget(std::make_unique<Wt::WText>(Settings::General::site_title));
  site_label->setAttributeValue("style", "font-size: 74px;");
  site_label->setStyleClass("row justify-content-center align-items-center h-50 m-4");
  site_label->setId("site_label");
  //auto menu = root()->addWidget(std::make_unique<Menu>());
  vector<Flat> flats = {Flat{4.1, "Москва", 8, 7, 4}, Flat{10.1, "Краснодар", 1, 8, 3}, Flat{4.1, "Москва", 8, 7, 4}, Flat{10.1, "Краснодар", 1, 8, 3},
    Flat{4.1, "Москва", 8, 7, 4}, Flat{10.1, "Краснодар", 1, 8, 3}};
  auto flatbox = root()->addWidget(std::make_unique<FlatBox>(flats));
  //flatbox->collapse();
  //messageResourceBundle().use("./"+Settings::Templates::templates_dir+"/base");
}