#include "settings.h"
#include "searchbox.h"

#include <regex> // для замены <br> на \n в описании квартир

class FlatWrapper: public Object {
public:
  FlatWrapper() {};
  std::unique_ptr<Wt::WTemplate> info();
};

class OverflowProject : public Wt::WApplication
{
public:
  OverflowProject(const Wt::WEnvironment& env);
  SearchBox<FlatWrapper> *searchbox;
};

int run_server(int argc, char **argv);