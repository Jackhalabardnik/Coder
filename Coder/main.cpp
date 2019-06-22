#include "mainwindow.h"

int main (int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "Coder");
  MainWindow mainwindow;

  return app->run(mainwindow);
}