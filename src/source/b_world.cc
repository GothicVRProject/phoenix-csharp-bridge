#include <phoenix/vdfs.hh>
#include <phoenix/world.hh>
#include <exports.hh>
#include <b_vdfs.hh>
#include <b_world.hh>

using namespace phoenix;


EXPORT Mesh* loadWorldMesh(vdf_file* vdfContainer, char* worldFileName) {
  auto entry = getVDFEntry(vdfContainer, worldFileName);
  auto world = world::parse(entry->open(), game_version::gothic_1);

  auto &origVertices = world.world_mesh.vertices;
  auto &origPolygons = world.world_mesh.polygons;

  auto mesh = new Mesh();

  mesh->vertices = {};
  for (int i = 0; i < origVertices.size(); i++) {
    mesh->vertices.push_back({origVertices[i].x, origVertices[i].y, origVertices[i].z});
  }

  mesh->vertexIndices = {};
  for (int i = 0; i < origPolygons.vertex_indices.size(); i++) {
    mesh->vertexIndices.push_back(origPolygons.vertex_indices[i]);
  }

  return mesh;
}

EXPORT int getWorldVerticesCount(Mesh* mesh) {
  return mesh->vertices.size();
}

EXPORT void getWorldMeshVertex(Mesh* mesh, int index, float* x, float* y, float* z) {
  *x = mesh->vertices[index].x;
  *y = mesh->vertices[index].y;
  *z = mesh->vertices[index].z;
}

EXPORT int getWorldMeshVertexIndicesCount(Mesh* mesh) {
  return mesh->vertexIndices.size();
}

EXPORT void getWorldMeshVertexIndex(Mesh* mesh, int index, uint32_t *value) {
  *value = mesh->vertexIndices[index];
}


EXPORT void disposeWorldMesh(Mesh* mesh) {
  delete mesh;
}
