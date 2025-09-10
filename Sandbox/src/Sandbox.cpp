#include <OGL.h>
#include <memory>

class Sandbox : public OGL::App {

};

OGL::App* OGL::CreateApp() {
	return new Sandbox();
}