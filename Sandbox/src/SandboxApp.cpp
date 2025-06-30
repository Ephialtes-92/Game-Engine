#include <Hephaestus.h>

class Sandbox : public hf::app
{
public :
	Sandbox() {}

	~Sandbox() {}
};

hf::app* hf::CreateApplication()
{
	return new Sandbox();
}