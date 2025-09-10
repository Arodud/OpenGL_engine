#pragma once

#ifdef OGL_PLATFORM_WINDOWS

extern OGL::OGLApp* OGL::CreateApp();

int main(int argc, char** argv) {
	auto app = OGL::CreateApp();
	app->Run();
	delete app;
}

#endif