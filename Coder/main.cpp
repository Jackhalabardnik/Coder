#include "mainwindow.h"

int main (int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  MainWindow mainwindow;

  return app->run(mainwindow);
}