#include <gtkmm.h>

using namespace Glib;
using namespace Gtk;

class Form : public Window {
public:
  Form() {
    this->add(this->scrolledWindow);
    this->scrolledWindow.add(this->fixed);
    
    this->checkBox1.set_label("Checked");
    this->checkBox1.set_active(true);
    this->fixed.add(this->checkBox1);
    this->fixed.child_property_x(this->checkBox1) = 30;
    this->fixed.child_property_y(this->checkBox1) = 30;
    
    this->checkBox2.set_label("Unchecked");
    this->checkBox2.set_active(false);
    this->fixed.add(this->checkBox2);
    this->fixed.child_property_x(this->checkBox2) = 30;
    this->fixed.child_property_y(this->checkBox2) = 60;
    
    this->checkBox3.set_label("Indeterminate");
    this->checkBox3.set_inconsistent(true);
    this->checkBox3.set_active(false);
    this->fixed.add(this->checkBox3);
    this->fixed.child_property_x(this->checkBox3) = 30;
    this->fixed.child_property_y(this->checkBox3) = 90;

    this->set_title("CheckBox example");
    this->set_size_request(300, 300);
    this->show_all();
  }
  
private:
  Fixed fixed;
  ScrolledWindow scrolledWindow;
  CheckButton checkBox1;
  CheckButton checkBox2;
  CheckButton checkBox3;
};

int main(int argc, char* argv[]) {
  RefPtr<Application> application = Application::create(argc, argv);
  Form form;
  return application->run(form);
}
