#include "test.h"

TEST(SEARCHBOX_TEST, OBJ_COUNT) {
  Wt::Test::WTestEnvironment environment;
  OverflowProject *app = new OverflowProject(environment);
  std::function<std::vector<std::unique_ptr<Object>>(Wt::WString)> get_data = [](Wt::WString input) {
    std::vector<std::unique_ptr<Object>> out = {};
    for (int i = 0; i < 4; i++) {
      out.push_back(std::make_unique<FlatWrapper>());
    }
    return out;
  };
  app->searchbox->get_data = get_data;
  app->searchbox->showresults();
  EXPECT_EQ(app->searchbox->data.size(), 4);
  delete app;
}

TEST(FLATWRAPPER_TEST, INFO) {
  /*
  Проверка вывода при наличии файла шаблона.
  */
  std::ofstream f("info.xml");
  f << "<?xml version=\"1.0\" encoding=\"UTF-8\" ?>"
  "<messages>"
  "<message id=\"info\">"
  "${title} ${price}"
  "</message>"
  "</messages>";
  f.close();
  Wt::Test::WTestEnvironment environment;
  environment.setDocRoot(".");
  OverflowProject *app = new OverflowProject(environment);
  std::function<std::vector<std::unique_ptr<Object>>(Wt::WString)> get_data = [](Wt::WString input) {
    std::vector<std::unique_ptr<Object>> out = {};
    for (int i = 0; i < 1; i++) {
      out.push_back(std::make_unique<FlatWrapper>());
    }
    return out;
  };
  app->searchbox->get_data = get_data;
  app->searchbox->showresults();
  std::stringstream result;
  app->searchbox->data[0]->info()->renderTemplate(result);
  EXPECT_EQ(result.str(), "title price");
  delete app;
}

TEST(FLATWRAPPER_TEST, INFO_NOT_FOUND) {
  /*
    Проверка вывода при отсутствии файла шаблона.
  */
  FlatWrapper flatw = FlatWrapper();
  EXPECT_EQ(flatw.info()->templateText().toUTF8(), "??info??");
}