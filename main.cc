#define DllExport extern "C" __declspec( dllexport )

#include <iostream>
#include <map>
#include <strings.h>
#include <phoenix/vdfs.hh>
#include <phoenix/world.hh>

using namespace phoenix;


DllExport vdf_file* createVDFContainer() {
	return new vdf_file("Root");
}

DllExport void addVDFToContainer(vdf_file* vdfContainer, char* newVdfPath) {
	vdfContainer->merge(vdf_file::open(newVdfPath));
}

DllExport const vdf_entry* getVDFEntry(vdf_file* vdfContainer, char* fileName) {
    return static_cast<const vdf_file*>(vdfContainer)->find_entry(fileName);
}


struct Vector3 {
  float x;
  float y;
  float z;
};


DllExport void loadWorld(vdf_file* vdfContainer, char* worldFileName, Vector3 vectors[]) {
  auto entry = getVDFEntry(vdfContainer, worldFileName);
  auto world = world::parse(entry->open(), game_version::gothic_1);

  auto oneVertice = world.world_mesh.vertices[0];

  auto vector3 = Vector3{oneVertice.x, oneVertice.y, oneVertice.z};

  vectors[0] = vector3;
}


// DllExport const char* getHeaderComment(vdf_header* header) {
// 	if (header->comment.empty())
// 		return NULL;

// 	return header->comment.c_str();
// }

DllExport void disposeVDFContainer(vdf_file* vdfContainer) {
	if(vdfContainer != NULL) {
        delete vdfContainer;
        vdfContainer = NULL;
    }
}



int main(int argc, char** argv) {
	// getVDFHeader((char*)"C:\\Program Files (x86)\\Steam\\steamapps\\common\\Gothic\\Data\\SystemPack.vdf");

	// std::cout << "headerComment: " << header->comment << header->comment.empty() << "END;" << std::endl;


	int a;
	std::cin >> a;
	return 0;
}
