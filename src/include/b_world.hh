#pragma once

#include <phoenix/vdfs.hh>
#include <phoenix/world.hh>
#include <exports.hh>

using namespace phoenix;


struct Vector3 {
  float x;
  float y;
  float z;
};

struct Mesh {
  std::vector<Vector3> vertices;
  std::vector<uint32_t> vertexIndices;
};


EXPORT Mesh* loadWorldMesh(vdf_file* vdfContainer, char* worldFileName);
EXPORT int getWorldVerticesCount(Mesh* mesh);
EXPORT void getWorldMeshVertex(Mesh* mesh, int index, float* x, float* y, float* z);
EXPORT int getWorldMeshVertexIndicesCount(Mesh* mesh);
EXPORT void getWorldMeshVertexIndex(Mesh* mesh, int index, uint32_t *value);
EXPORT void disposeWorldMesh(Mesh* mesh);
