#include <iostream>

#include <b_vdfs.hh>
#include <b_world.hh>

using namespace phoenix;



void printWorldData() {
  auto vdfContainer = createVDFContainer();
  addVDFToContainer(vdfContainer, (char*)"C:\\Program Files (x86)\\Steam\\steamapps\\common\\Gothic\\Data\\worlds.vdf");

  auto entry = getVDFEntry(vdfContainer, (char*)"world.zen");
  auto world = world::parse(entry->open(), game_version::gothic_1);

  auto &mesh = world.world_mesh;


  std::cout << "Mesh data:" << std::endl
    << "name=" << mesh.name
    << "materials.size=" << mesh.materials.size() << std::endl
    << "vertices.size=" << mesh.vertices.size() << std::endl
    << "polygons.vertex_indices.size=" << mesh.polygons.vertex_indices.size() << std::endl
    << "polygons.material_indices.size=" << mesh.polygons.material_indices.size() << std::endl
    << "polygons.feature_indices.size=" << mesh.polygons.feature_indices.size() << std::endl
    << std::endl;

}


int main(int argc, char** argv) {
  printWorldData();

	// int a;
	// std::cin >> a;
	// return 0;
}
