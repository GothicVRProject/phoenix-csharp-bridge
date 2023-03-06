#define DllExport extern "C" __declspec( dllexport )

#include <iostream>
#include <map>
#include <strings.h>

#include <vdfs.hh>
#include <world.hh>

using namespace phoenix;


DllExport void disposeVDFContainer(vdf_file* vdfContainer) {
  delete vdfContainer;
}



int main(int argc, char** argv) {
  auto vdf = createVDFContainer();
  addVDFToContainer(vdf, (char*)"C:\\Program Files (x86)\\Steam\\steamapps\\common\\Gothic\\Data\\worlds.vdf");
  Mesh* mesh = loadWorldMesh(vdf, (char*)"world.zen");
	std::cout << "vertices: " << getWorldVerticesCount(mesh) << std::endl;

  disposeMesh(mesh);

	// int a;
	// std::cin >> a;
	// return 0;
}
