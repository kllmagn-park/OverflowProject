#include "home.h"

/*
 * The env argument contains information about the new session, and
 * the initial request. It must be passed to the WApplication
 * constructor so it is typically also an argument for your custom
 * application constructor.
*/
OverflowProject::OverflowProject(const Wt::WEnvironment& env)
  : WApplication(env)
{
  setInternalPath("home");
  setTitle(Settings::General::site_title);
  messageResourceBundle().use("./"+Settings::Templates::templates_dir+"/base");
  cout << appRoot();
  root()->addWidget(std::make_unique<Wt::WText>("Your name, please ? ")); // show some text

  nameEdit_ = root()->addWidget(std::make_unique<Wt::WLineEdit>()); // allow text input
  nameEdit_->setFocus();                              // give focus

  auto button = root()->addWidget(std::make_unique<Wt::WPushButton>("Greet me."));
                                                      // create a button
  button->setMargin(5, Wt::Side::Left);                   // add 5 pixels margin

  root()->addWidget(std::make_unique<Wt::WBreak>());    // insert a line break
  greeting_ = root()->addWidget(std::make_unique<Wt::WText>()); // empty text

  /*
   * Connect signals with slots
   *
   * - simple Wt-way: specify object and method
   */
  button->clicked().connect(this, &OverflowProject::greet);

  /*
   * - using an arbitrary function object, e.g. useful to bind
   *   values with std::bind() to the resulting method call
   */
  nameEdit_->enterPressed().connect(std::bind(&OverflowProject::greet, this));

  /*
   * - using a lambda:
   */
  button->clicked().connect([=]() { 
      std::cerr << "Hello there, " << nameEdit_->text() << std::endl;
  });
}

void OverflowProject::greet()
{
  /*
   * Update the text, using text input into the nameEdit_ field.
   */
  greeting_->setText("Hello there, " + nameEdit_->text());
}