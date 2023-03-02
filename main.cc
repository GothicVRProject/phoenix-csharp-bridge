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

struct Mesh {
  int verticesCount;
  Vector3* vertices;
};


DllExport Mesh* loadWorldMesh(vdf_file* vdfContainer, char* worldFileName) {
  auto entry = getVDFEntry(vdfContainer, worldFileName);
  auto world = world::parse(entry->open(), game_version::gothic_1);
  auto &origVertices = world.world_mesh.vertices;

  auto mesh = new Mesh();
  mesh->verticesCount = origVertices.size();
  mesh->vertices = new Vector3[mesh->verticesCount];

  for (int i=0; i<mesh->verticesCount; i++) {
    mesh->vertices[i] = {origVertices[i].x, origVertices[i].y, origVertices[i].z};
  }

  return mesh;
}

DllExport int getWorldVerticesCount(Mesh* mesh) {
  return mesh->verticesCount;
}

DllExport void getMeshVertex(Mesh* mesh, int index, float* x, float* y, float* z) {
  *x = mesh->vertices[index].x;
  *y = mesh->vertices[index].y;
  *z = mesh->vertices[index].z;
}

DllExport void disposeMesh(Mesh* mesh) {
  delete mesh->vertices;
  delete mesh;
}

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
