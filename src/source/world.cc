#define DllExport extern "C" __declspec( dllexport )

#include <phoenix/vdfs.hh>
#include <phoenix/world.hh>
#include <vdfs.hh>
#include <world.hh>

using namespace phoenix;


DllExport Mesh* loadWorldMesh(vdf_file* vdfContainer, char* worldFileName) {
  auto entry = getVDFEntry(vdfContainer, worldFileName);
  auto world = world::parse(entry->open(), game_version::gothic_1);

  auto &origVertices = world.world_mesh.vertices;
  auto &origPolygons = world.world_mesh.polygons;

  auto mesh = new Mesh();

  mesh->verticesCount = origVertices.size();
  mesh->vertices = new Vector3[mesh->verticesCount];
  for (int i=0; i<mesh->verticesCount; i++) {
    mesh->vertices[i] = {origVertices[i].x, origVertices[i].y, origVertices[i].z};
  }

  mesh->vertexIndicesCount = origPolygons.vertex_indices.size();
  mesh->vertexIndices = new uint32_t[mesh->vertexIndicesCount];
  for (int i=0; i<mesh->vertexIndicesCount; i++) {
    mesh->vertexIndices[i] = origPolygons.vertex_indices[i];
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

DllExport int getWorldMeshVertexIndicesCount(Mesh* mesh) {
  return mesh->vertexIndicesCount;
}

DllExport void getWorldMeshVertexIndex(Mesh* mesh, int index, uint32_t *value) {
  *value = mesh->vertexIndices[index];
}


DllExport void disposeMesh(Mesh* mesh) {
  delete mesh->vertices;
  delete mesh->vertexIndices;
  delete mesh;
}
