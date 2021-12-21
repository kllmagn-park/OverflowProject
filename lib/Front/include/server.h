#include "settings.h"
#include "searchbox.h"

#include <regex> // для замены <br> на \n в описании квартир

class FlatWrapper: public Object {
/*
Обертка поверх модели.
Преобразует модель в объект для обеспечения взаимодействия с GUI.
*/
public:
  FlatWrapper() {};
  std::unique_ptr<Wt::WTemplate> info() override;
};

class OverflowProject : public Wt::WApplication
{
public:
  OverflowProject(const Wt::WEnvironment& env);
  SearchBox *searchbox;
};

int run_server(int argc, char **argv);