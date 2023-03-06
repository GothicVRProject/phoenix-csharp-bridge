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
  int verticesCount;
  Vector3* vertices; // array
  int vertexIndicesCount;
  uint32_t* vertexIndices; // array
};


DllExport Mesh* loadWorldMesh(vdf_file* vdfContainer, char* worldFileName);
DllExport int getWorldVerticesCount(Mesh* mesh);
DllExport void getMeshVertex(Mesh* mesh, int index, float* x, float* y, float* z);
DllExport int getWorldMeshVertexIndicesCount(Mesh* mesh);
DllExport void getWorldMeshVertexIndex(Mesh* mesh, int index, uint32_t *value);
DllExport void disposeMesh(Mesh* mesh);
