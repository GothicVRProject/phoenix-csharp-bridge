#pragma once
#define DllExport extern "C" __declspec( dllexport )

#include <phoenix/vdfs.hh>
#include <phoenix/world.hh>

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


DllExport Mesh* loadWorldMesh(vdf_file* vdfContainer, char* worldFileName);
DllExport int getWorldVerticesCount(Mesh* mesh);
DllExport void getWorldMeshVertex(Mesh* mesh, int index, float* x, float* y, float* z);
DllExport int getWorldMeshVertexIndicesCount(Mesh* mesh);
DllExport void getWorldMeshVertexIndex(Mesh* mesh, int index, uint32_t *value);
DllExport void disposeWorldMesh(Mesh* mesh);
