#include <dbus-cxx.h>
#include <unistd.h>

double add( double param1, double param2 )      { return param1 + param2; }

int main()
{
  int ret;

  DBus::init();

  DBus::Dispatcher::pointer dispatcher = DBus::Dispatcher::create();

  DBus::Connection::pointer conn = dispatcher->create_connection(DBus::BUS_SESSION);

  ret = conn->request_name( "dbuscxx.quickstart_0.server", DBUS_NAME_FLAG_REPLACE_EXISTING );
  if (DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER != ret) return 1;

  //create an object on us
  DBus::Object::pointer object = conn->create_object("/dbuscxx/quickstart_0");

  //add a method that can be called over the dbus
  object->create_method<double,double,double>("dbuscxx.Quickstart", "add", sigc::ptr_fun(add) );

  sleep(30);

  return 0;
}
